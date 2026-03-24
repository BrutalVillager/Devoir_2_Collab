/**
 * @brief Une liste de valeurs entières implémentée avec des noeuds liées entre eux.
 * @author Louis Marchand
 * @date 10 février 2026
 */

#ifndef LISTELIEE_H
#define LISTELIEE_H

#include <string>

#include "listelieenoeud.h"

class ListeLiee {
private:

    /**
     * @brief Nombre d'éléments dans la liste.
     */
    int taille;

    /**
     * @brief Pointeur vers le premier noeud de la liste.
     */
    ListeLieeNoeud* premier;

    /**
     * @brief Pointeur vers le dernier noeud de la liste.
     */
    ListeLieeNoeud* dernier;

    /**
     * @brief La position du noeud `noeud_courrant` dans la liste.
     */
    int positionCourrante;

    /**
     * @brief Permettant de traverser la liste sans avoir à repartir du début à chaque élément lu.
     */
    ListeLieeNoeud* noeudCourrant;

    /**
     * @brief Vrai si la dernière opération n'a pas pu être complété correctement.
     */
    bool estEnErreur;

    /**
     * @brief Si `a_erreur` est Vrai, contient un message d'erreur. Chaîne vide sinon.
     */
    std::string erreur;

    /**
     * @brief Déplacer le noeud courrant à la position défini par `index`.
     * @param index La position à déplacer le noeud courrant.
     */
    void positionner(int index);

    /**
     * @brief Retire l'erreur en cours, s'il y en a une.
     */
    void retirerErreur();

    /**
     * @brief Place une erreur dans la gestion d'erreur de la liste.
     * @param erreur Le message de l'erreur à placer dans la gestion d'erreur.
     */
    void inscrireErreur(std::string erreur);

public:

    /**
     * @brief Constructeur de la liste liée.
     */
    ListeLiee();

    /**
     * @brief Création d'une nouvelle liste liée contenant le contenue d'un array d'un fichier JSON.
     * @param nomFichier le chemin du fichier à charger
     */
    ListeLiee(std::string nomFichier);

    /**
     * @brief Destructeur de la liste liée.
     */
    ~ListeLiee();

    /**
     * @brief Ajoute la valeur à la fin de la liste.
     * @param valeur L'élément à ajouter à la fin de la liste.
     */
    void ajouterElement(int valeur);

    /**
     * @brief Retourne l'élément stocké dans la liste à une position.
     * @param index La position de l'élément à retourner.
     * @return L'élément stocké dans la liste à une position.
     */
    int getElement(int index);

    /**
     * @brief Retourne le nombre d'éléments dans la liste.
     * @return le nombre d'éléments dans la liste.
     */
    int getTaille();

    /**
     * @brief Change l'élément à une certaine position par un autre element.
     * @param index La position contenant l'élément à remplacer.
     * @param element La nouvelle valeur à stocker dans la liste.
     */
    void remplacerElement(int index, int element);

    /**
     * @brief Insère un élément à une certaine position (décale tous les éléments suivants).
     * @param index La position contenant l'élément à insérer.
     * @param element La nouvelle valeur à stocker dans la liste.
     */
    void insererElement(int index, int element);

    /**
     * @brief Retire un élément à une certaine position
     * @param index La position contenant l'élément à retirer.
     */
    void retirerElement(int index);

    /**
     * @brief Retire tous les éléments de la liste
     */
    void vider();

    /**
     * @brief Créé une string en format JSON à partir de la liste
     * @return La string en format JSON
     */
    std::string versJsonString();

    /**
     * @brief Sauvegarde la liste dans un fichier JSON
     * @param nomFichier le chemin du fichier à créer
     */
    void sauvegarder(std::string nomFichier);

    /**
     * @brief Charge les éléments de la liste d'un fichier JSON
     * @param nomFichier le chemin du fichier à charger
     */
    void charger(std::string nomFichier);

    /**
     * @brief Ajoute les éléments présents dans une string contenant une liste en format JSON
     * @param jsonString La string en format JSON
     */
    void ajouterJsonString(std::string jsonString);

    /**
     * @brief Vrai si la dernière opération n'a pas pu être complété correctement.
     */
    bool hasErreur();

    /**
     * @brief Si `hasErreur` est Vrai, contient un message d'erreur. Chaîne vide sinon.
     */
    std::string getErreur();

};



#endif // LISTELIEE_H
