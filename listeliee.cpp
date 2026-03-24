/**
 * @brief Une liste de valeurs entières implémenté avec des noeuds liées entre eux.
 * @author Louis Marchand
 */

#include "listeliee.h"
#include <fstream>
#include <cmath>
#include "json.hpp"

/**
 * @brief Constructeur de la liste liée.
 */
ListeLiee::ListeLiee() {
    taille = 0;
    premier = NULL;
    dernier = NULL;
    positionCourrante = 0;
    noeudCourrant = NULL;
    estEnErreur = false;
    erreur = "";
}

/**
 * @brief Création d'une nouvelle liste liée contenant le contenue d'un array d'un fichier JSON.
 * @param aNomFichier le chemin du fichier à charger
 */
ListeLiee::ListeLiee(std::string aNomFichier): ListeLiee() {
    charger(aNomFichier);
}

/**
 * @brief Destructeur de la liste liée.
 */
ListeLiee::~ListeLiee() {
    vider();
}

/**
 * @brief Ajoute la valeur à la fin de la liste.
 * @param aValeur L'élément à ajouter à la fin de la liste.
 */
void ListeLiee::ajouterElement(int aValeur) {
    retirerErreur();
    ListeLieeNoeud* nouveau = new ListeLieeNoeud(aValeur);
    if (taille == 0) {
        premier = nouveau;
        noeudCourrant = nouveau;
        positionCourrante = 0;
    } else {
        nouveau->precedent = dernier;
        dernier->prochain = nouveau;
    }
    dernier = nouveau;
    taille = taille + 1;
}

/**
 * @brief Retourne l'élément stocké dans la liste à une position
 * @param aIndex La position de l'élément à retourner
 * @return L'élément stocké dans la liste à une position
 */
int ListeLiee::getElement(int aIndex) {
    int resultat = 0;
    retirerErreur();
    if (taille > 0) {
        positionner(aIndex);
        if (positionCourrante == aIndex) {
            resultat = noeudCourrant->valeur;
        }
    } else {
        inscrireErreur("La liste est vide");
    }
    return resultat;
}

/**
 * @brief Retourne le nombre d'éléments dans la liste.
 * @return le nombre d'éléments dans la liste.
 */
int ListeLiee::getTaille() {
    retirerErreur();
    return taille;
}

/**
 * @brief Change l'élément à une certaine position par un autre element.
 * @param aIndex La position contenant l'élément à remplacer.
 * @param aElement La nouvelle valeur à stocker dans la liste.
 */
void ListeLiee::remplacerElement(int aIndex, int aElement) {
    retirerErreur();
    if (taille > 0) {
        positionner(aIndex);
        if (positionCourrante == aIndex) {
            noeudCourrant->valeur = aElement;
        }
    } else {
        inscrireErreur("La liste est vide");
    }
}

/**
 * @brief Insère un élément à une certaine position (décale tous les éléments suivants).
 * @param aIndex La position contenant l'élément à insérer.
 * @param aElement La nouvelle valeur à stocker dans la liste.
 */
void ListeLiee::insererElement(int aIndex, int aElement) {
    retirerErreur();
    if (taille > 0) {
        positionner(aIndex);
        if (positionCourrante == aIndex) {
            ListeLieeNoeud* nouveau = new ListeLieeNoeud(aElement, noeudCourrant->precedent, noeudCourrant);
            if (aIndex > 0) {
                nouveau->precedent->prochain = nouveau;
            } else {
                premier = nouveau;
            }
            noeudCourrant->precedent = nouveau;
            noeudCourrant = nouveau;
            taille = taille + 1;
        }
    } else {
        if (aIndex == 0) {
            ajouterElement(aElement);
        } else {
            inscrireErreur("L'index doit être 0 pour une liste vide.");
        }
    }
}

/**
 * @brief Retire un élément à une certaine position
 * @param aIndex La position contenant l'élément à retirer.
 */
void ListeLiee::retirerElement(int aIndex) {
    retirerErreur();
    if (taille > 0) {
        positionner(aIndex);
        if (positionCourrante == aIndex) {
            ListeLieeNoeud* retire = noeudCourrant;
            if (retire->precedent == nullptr) {
                premier = retire->prochain;
            } else {
                retire->precedent->prochain = retire->prochain;
            }
            if (retire->prochain == nullptr) {
                dernier = retire->precedent;
                noeudCourrant = retire->precedent;
                positionCourrante = positionCourrante - 1;
            } else {
                retire->prochain->precedent = retire->precedent;
                noeudCourrant = retire->prochain;
            }
            delete retire;
            taille = taille - 1;
        }
    } else {
        inscrireErreur("La liste est vide.");
    }
}

/**
 * @brief Retire tous les éléments de la liste
 */
void ListeLiee::vider() {
    retirerErreur();
    ListeLieeNoeud* courrant = premier;
    ListeLieeNoeud* prochain = nullptr;
    while (courrant != nullptr) {
        prochain = courrant->prochain;
        delete courrant;
        courrant = prochain;
    }
    premier = nullptr;
    dernier = nullptr;
    noeudCourrant = nullptr;
    taille = 0;
    positionCourrante = 0;
}

/**
 * @brief Créé une string en format JSON à partir de la liste
 * @return La string en format JSON
 */
std::string ListeLiee::versJsonString() {
    retirerErreur();
    nlohmann::json json = nlohmann::basic_json();
    for (int i = 0; i < taille; i = i + 1) {
        json.push_back(getElement(i));
    }
    return json.dump();
}

/**
 * @brief Ajoute les éléments présents dans une string contenant une liste en format JSON
 * @param aJsonString La string en format JSON
 */
void ListeLiee::ajouterJsonString(std::string aJsonString) {
    retirerErreur();
    int valeur;
    nlohmann::json json = nlohmann::json::parse(aJsonString);
    if (json.is_null() or json.is_array()) {
        for (int i = 0; i < json.size(); i = i + 1) {
            if (json[i].is_number_integer()) {
                ajouterElement(json[i]);
            } else {
                inscrireErreur("La chaîne JSON contient une valeur non valide: " +
                               json[i].dump() + ".");
            }
        }
    } else {
        inscrireErreur("La chaîne JSON doit contenir un array d'entiers.");
    }
}

/**
 * @brief Sauvegarde la liste dans un fichier JSON
 * @param aNomFichier le chemin du fichier à créer
 */
void ListeLiee::sauvegarder(std::string aNomFichier) {
    retirerErreur();
    std::ofstream fichier(aNomFichier);
    if (fichier.is_open()) {
        fichier << versJsonString();
    } else {
        inscrireErreur("Ne peut ouvrir le fichier " + aNomFichier + " en écriture.");
    }
}

/**
 * @brief Charge les éléments de la liste d'un fichier JSON
 * @param aNomFichier le chemin du fichier à charger
 */
void ListeLiee::charger(std::string aNomFichier) {
    retirerErreur();
    std::ifstream fichier(aNomFichier);
    if (fichier.is_open()) {
        std::ostringstream stringStream;
        stringStream << fichier.rdbuf();
        ajouterJsonString(stringStream.str());
    } else {
        inscrireErreur("Ne peut ouvrir le fichier " + aNomFichier + " en lecture.");
    }
}

/**
 * @brief Déplacer le noeud courrant à la position défini par `index`.
 * @param aIndex La position à déplacer le noeud courrant.
 */
void ListeLiee::positionner(int aIndex) {
    int depuisDebut, depuisFin, depuisCourrant;
    retirerErreur();
    if ((aIndex >= 0) and (aIndex < taille)) {
        depuisDebut = aIndex;
        depuisFin = abs(taille - aIndex - 1);
        depuisCourrant = positionCourrante - aIndex;
        if ((depuisDebut < depuisFin) and
            (depuisDebut < abs(depuisCourrant))) {
            noeudCourrant = premier;
            positionCourrante = 0;
        } else if ((depuisFin < depuisDebut) and
                   (depuisFin < abs(depuisCourrant))) {
            noeudCourrant = dernier;
            positionCourrante = taille - 1;
        }
        while (positionCourrante != aIndex) {
            if (positionCourrante < aIndex) {
                noeudCourrant = noeudCourrant->prochain;
                positionCourrante = positionCourrante + 1;
            } else {
                noeudCourrant = noeudCourrant->precedent;
                positionCourrante = positionCourrante - 1;
            }
        }

    } else {
        inscrireErreur("Index invalide.");
    }
}

/**
 * @brief Retire l'erreur en cours, s'il y en a une.
 */
void ListeLiee::retirerErreur() {
    estEnErreur = false;
    erreur = "";
}
/**
 * @brief Place une erreur dans la gestion d'erreur de la liste.
 * @param erreur Le message de l'erreur à placer dans la gestion d'erreur.
 */
void ListeLiee::inscrireErreur(std::string aErreur){
    estEnErreur = true;
    erreur = aErreur;
}

/**
 * @brief Vrai si la dernière opération n'a pas pu être complété correctement.
 */
bool ListeLiee::hasErreur() {
    return estEnErreur;
}

/**
 * @brief Si `hasErreur` est Vrai, contient un message d'erreur. Chaîne vide sinon.
 */
std::string ListeLiee::getErreur() {
    return erreur;
}
