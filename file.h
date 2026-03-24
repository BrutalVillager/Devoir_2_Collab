#ifndef FILE_H
#define FILE_H

#include <string>
#include "listeliee.h"

class File
{
private:
    ListeLiee* liste;
    bool erreur;
    std::string messageErreur;

public:
    File();
    ~File();

    /**
     * @brief Implémentation d'un noeud unique d'une liste liée.
     * @param valeur L'element a ajouter
     */
    void ajouterElement(int valeur);

    /**
     * @brief  Retourne le prochain élément de la File
     * @return Valeur
     */
    int getElement();

    /**
     * @brief Retire le prochain élément de la File
     */
    void retirerElement();

    /**
     * @brief Retire tous les éléments de la File
     */
    void vider();

    /**
     * @brief Retourne le nombre d’elements a avoir ete place dans la File
     * @return La taille de notre liste
     */
    int getTaille();

    /**
     * @brief Sérialiser les valeurs de la File en format JSON
     * @return Fichier json
     */
    std::string versJsonString();

    /**
     * @brief Sauvegarder la File dans un fichier JSON
     */
    void sauvegarder(std::string nomFichier);

    /**
     * @brief Ajouter dans la File les valeurs d’un texte en format JSON
     */
    void ajouterJsonString(std::string jsonString);

    /**
     * @brief Ajouter dans la File les valeurs d’un fichier JSON
     */
    void charger(std::string nomFichier);

    /**
     * @brief Retourne Vrai si une erreur est survenue dans le dernier appel de méthode de la File
     */
    bool hasErreur();

    /**
     * @brief  Lorsque hasErreur() est vrai, retourne une description texte de l’erreur
     */
    std::string getErreur();

    bool erreurliste();
};

#endif // FILE_H
