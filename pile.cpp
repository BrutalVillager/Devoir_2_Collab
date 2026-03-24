/**
 * @file Pile.cpp
 * @brief Implémentation de la classe Pile.
 *
 * Cette classe représente une pile (structure LIFO : Last In, First Out)
 * en utilisant une ListeLiee comme structure interne. Elle permet :
 *  - d’ajouter un élément au sommet,
 *  - de retirer l’élément au sommet,
 *  - de consulter l’élément au sommet,
 *  - de vider la pile,
 *  - d’obtenir la taille,
 *  - de convertir la pile en JSON,
 *  - de charger et sauvegarder la pile dans un fichier JSON.
 *
 * La classe gère également un système d’erreurs permettant de savoir si
 * la dernière opération a échoué, ainsi qu’un message décrivant l’erreur.
 *
 * @date 2026-03-10
 * @author Anthony
 */

#include "pile.h"
/**
 * @brief Constructeur : initialise une pile vide.
 */
Pile::Pile() : erreur(false), messageErreur("aucune erreur"), maListe(new ListeLiee()) {}
/**
 * @brief Destructeur : libère la mémoire associée à la liste liée.
 */

Pile::~Pile(){
    delete maListe;
}
/**
 * @brief Ajoute une valeur sur le dessus de la pile.
 * @param valeur La valeur entière à empiler.
 * @post La pile contient un élément de plus.
 */
void Pile::ajouterElement(int valeur){
    erreur = false;
    maListe->ajouterElement(valeur);
}
/**
 * @brief Indique si la dernière opération a généré une erreur.
 * @return true si une erreur est survenue, false sinon.
 */
bool Pile::hasErreur(){
    return erreur;
}
/**
 * @brief Retourne la valeur au sommet de la pile.
 * @return La valeur au sommet, ou -1 si la pile est vide.
 * @pre La pile ne doit pas être vide.
 * @note Ne modifie pas la pile.
 */
int Pile::getElement(){
    int valeur = -1;
    erreur = false;
    if (maListe->getTaille() == 0){
        erreur = true;
        messageErreur = "erreur : la pile est vide.";
    } else {
        valeur = maListe->getElement(maListe->getTaille()-1);
    }
    return valeur;
}
/**
 * @brief Retire l’élément au sommet de la pile.
 * @pre La pile ne doit pas être vide.
 * @post La pile contient un élément de moins.
 */
void Pile::retirerElement(){
    erreur = false;
    if (getTaille() == 0){
        erreur = true;
        messageErreur = "erreur : la pile est vide.";
    } else {
        int index = getTaille() -1;
        int valeur = maListe->getElement(index);
        maListe->retirerElement(index);
        messageErreur = "la valeur " + std::to_string(valeur) + " a été retirée de la pile";
    }
}
/**
 * @brief Vide complètement la pile.
 * @post La pile devient vide.
 */
void Pile::vider(){
    erreur = false;
    maListe->vider();
}
/**
 * @brief Retourne le nombre d’éléments dans la pile.
 * @return La taille de la pile.
 */
int Pile::getTaille(){
    erreur = false;
    return maListe->getTaille();
}
/**
 * @brief Convertit la pile en une chaîne JSON représentant la liste des valeurs.
 * @return Une string contenant un array JSON (ex: "[1,2,3]").
 */
std::string Pile::versJsonString(){
    erreur = false;
    return maListe->versJsonString();
}
/**
 * @brief Sauvegarde le contenu de la pile dans un fichier JSON.
 * @param nomFichier Le nom du fichier où sauvegarder.
 */
void Pile::sauvegarder(std::string nomFichier) {
    erreur = false;
    maListe->sauvegarder(nomFichier);
    if (maListe->hasErreur()) {
        erreur = true;
        messageErreur = "Ne peut ouvrir le fichier " + nomFichier + " en écriture.";
    } else {
        messageErreur = "Le fichier " + nomFichier + " a été sauvegardé";
    }
}
/**
 * @brief Ajoute les éléments contenus dans une chaîne JSON.
 * @param jsonstring Une string contenant un array JSON d’entiers.
 * @post Les valeurs valides sont ajoutées à la pile.
 */
void Pile::ajouterJsonString(std::string jsonstring){
    erreur = false;
    maListe->ajouterJsonString(jsonstring);
    if (maListe->hasErreur()){
        erreur = true;
        messageErreur = "erreur lors de l'ajout du json string : " + maListe->getErreur();
    } else {
        messageErreur = "La chain de Json " + jsonstring +  " à été ajouter";
    }
}
/**
 * @brief Retourne le message d’erreur associé à la dernière opération.
 * @return Une string décrivant l’erreur.
 */
std::string Pile::getErreur(){
    return messageErreur;
}
/**
 * @brief Charge les éléments d’un fichier JSON et remplace le contenu de la pile.
 * @param nomFichier Le fichier à charger.
 */
void Pile::charger(std::string nomFichier){
    erreur = false;
    maListe->charger(nomFichier);
    if(maListe->hasErreur()){
        erreur = true;
        messageErreur = "Ne peut ouvrir le fichier " + nomFichier + " en lecture.";
    } else {
        messageErreur = "Le fichier " + nomFichier +  " a été chargé";
    }
}
