/** @file Pile.h
 *  @brief Définition de la classe Pile, représentant une pile (structure LIFO).
 *
 *  Cette classe encapsule une ListeLiee afin d’offrir les opérations classiques
 *  d’une pile : ajouter un élément, retirer le dernier élément ajouté, consulter
 *  l’élément au sommet, vider la pile, obtenir sa taille, et gérer la
 *  sérialisation en JSON (chargement et sauvegarde).
 *
 *  La pile fonctionne selon le principe LIFO (Last In, First Out) :
 *  - Le dernier élément ajouté est toujours le premier retiré.
 *
 *  La classe gère également un système d’erreurs permettant de savoir si la
 *  dernière opération a échoué, ainsi qu’un message décrivant l’erreur.
 *
 *  @date 2026-03-10
 *  @author Anthony
 */

#ifndef PILE_H
#define PILE_H

#include "listeliee.h"
#include <string>

class Pile
{
private:
    /*
     * @brief Pointeur vers la liste liée utilisée pour stocker les éléments.
     */
    ListeLiee* maListe;

    /*
     * @brief Indique si la dernière opération a généré une erreur.
     */
    bool erreur;

    /*
     * @brief Message décrivant l’erreur si `erreur` est vrai.
     */
    std::string messageErreur;

public:
    /*
     * @brief Constructeur : initialise une pile vide.
     */
    Pile();

    /*
     * @brief Destructeur : libère la mémoire associée à la liste liée.
     */
    ~Pile();

    /*
     * @brief Ajoute une valeur sur le dessus de la pile.
     * @param valeur La valeur entière à empiler.
     * @post La pile contient un élément de plus.
     */
    void ajouterElement(int valeur);

    /*
     * @brief Retourne la valeur au sommet de la pile.
     * @return La valeur au sommet.
     * @pre La pile ne doit pas être vide.
     * @note Cette fonction ne modifie pas la pile.
     */
    int getElement();

    /*
     * @brief Retire l’élément au sommet de la pile.
     * @pre La pile ne doit pas être vide.
     * @post La pile contient un élément de moins.
     */
    void retirerElement();

    /*
     * @brief Vide complètement la pile.
     * @post La pile devient vide.
     */
    void vider();

    /*
     * @brief Retourne le nombre d’éléments dans la pile.
     * @return La taille de la pile.
     */
    int getTaille();

    /*
     * @brief Convertit la pile en une chaîne JSON représentant la liste des valeurs.
     * @return Une string contenant un array JSON (ex: "[1,2,3]").
     */
    std::string versJsonString();

    /*
     * @brief Sauvegarde le contenu de la pile dans un fichier JSON.
     * @param nomFichier Le nom du fichier où sauvegarder.
     */
    void sauvegarder(std::string nomFichier);

    /*
     * @brief Ajoute les éléments contenus dans une chaîne JSON.
     * @param jsonString Une string contenant un array JSON d’entiers.
     * @post Les valeurs valides sont ajoutées à la pile.
     */
    void ajouterJsonString(std::string jsonString);

    /*
     * @brief Charge les éléments d’un fichier JSON et remplace le contenu de la pile.
     * @param nomFichier Le fichier à charger.
     */
    void charger(std::string nomFichier);

    /*
     * @brief Indique si la dernière opération a échoué.
     * @return true si une erreur est survenue, false sinon.
     */
    bool hasErreur();

    /*
     * @brief Retourne le message d’erreur associé à la dernière opération.
     * @return Une string décrivant l’erreur.
     */
    std::string getErreur();
};

#endif // PILE_H
