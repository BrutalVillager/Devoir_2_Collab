/**
 * @brief Déclaration d'un noeud unique d'une liste liée.
 * @author Louis Marchand
 * @date 10 février 2026
 */

#ifndef LISTELIEENOEUD_H
#define LISTELIEENOEUD_H

class ListeLiee;

/**
 * @brief Un simple noeud d'une liste liée.
 */
class ListeLieeNoeud {
    friend ListeLiee;
private:

    /**
     * @brief L'information contenue dans le noeud.
     */
    int valeur;

    /**
     * @brief Indique le prochain noeud de la liste
     */
    ListeLieeNoeud *prochain;

    /**
     * @brief Indique le noeud précédent de la liste
     */
    ListeLieeNoeud *precedent;

public:

    /**
     * @brief Constructeur du noeud
     * @param valeur L'information
     */
    ListeLieeNoeud(int valeur):
        valeur(valeur), prochain(nullptr), precedent(nullptr) {};

    /**
     * @brief Constructeur du noeud
     * @param valeur L'information
     * @param prochain Indique le prochain noeud de la liste
     * @param precedent Indique le noeud précédent de la liste
     */
    ListeLieeNoeud(int valeur, ListeLieeNoeud *precedent, ListeLieeNoeud *prochain):
        valeur(valeur), precedent(precedent), prochain(prochain) {};

    /**
     * @brief Retourne la valeur du noeud
     * @return La valeur du noeud
     */
    int getValeur();

};

#endif // LISTELIEENOEUD_H
