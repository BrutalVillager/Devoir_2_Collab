#include <iostream>
#include <string>
#include "file.h"
#include "pile.h"
using namespace std;

int testsReussis = 0;
int testsEchoues = 0;

/**
 * @brief Affiche le résultat d'un test et cumule les statistiques.
 * @param description Description du test effectué.
 * @param succes Vrai si le test a réussi.
 */
void afficherTest(const string& description, bool succes) {
    if (succes) {
        cout << "Réussi!!!" << description << endl;
        testsReussis++;
    } else {
        cout << "Raté :(" << description << endl;
        testsEchoues++;
    }
}

/**
 * @brief Affiche un en-tête de section de tests.
 * @param titre Le titre de la section.
 */
void afficherSection(const string& titre) {
    cout << "\n--- " << titre << " ---" << endl;
}

//Tests de la File

/**
 * @brief Teste les opérations de base de la File (FIFO).
 */
void testerFileBase() {
    afficherSection("File : opérations de base");
    File f;

    // Ajout et taille
    f.ajouterElement(10);
    f.ajouterElement(20);
    f.ajouterElement(30);
    afficherTest("getTaille() == 3 après 3 ajouts", f.getTaille() == 3);
    afficherTest("hasErreur() == faux après ajouts valides", !f.hasErreur());

    // Ordre FIFO (First In, First Out)
    afficherTest("getElement() retourne 10 (premier entré)", f.getElement() == 10);

    f.retirerElement();
    afficherTest("getElement() retourne 20 après un retrait", f.getElement() == 20);
    afficherTest("getTaille() == 2 après un retrait", f.getTaille() == 2);

    f.retirerElement();
    f.retirerElement();
    afficherTest("getTaille() == 0 après tous les retraits", f.getTaille() == 0);
}

/**
 * @brief Teste la méthode vider() de la File.
 */
void testerFileVider() {
    afficherSection("File : vider()");
    File f;

    f.ajouterElement(1);
    f.ajouterElement(2);
    f.ajouterElement(3);
    f.vider();
    afficherTest("getTaille() == 0 après vider()", f.getTaille() == 0);
    afficherTest("hasErreur() == faux après vider()", !f.hasErreur());
}

/**
 * @brief Teste la gestion des erreurs de la File.
 */
void testerFileErreurs() {
    afficherSection("File : gestion des erreurs");
    File f;

    // getElement sur file vide
    f.getElement();
    afficherTest("hasErreur() == vrai si getElement() sur file vide", f.hasErreur());
    afficherTest("getErreur() non vide si erreur", f.getErreur() != "");

    // retirerElement sur une file vide
    f.retirerElement();
    afficherTest("hasErreur() == vrai si retirerElement() sur file vide", f.hasErreur());

    // Pas d'erreur après opération valide
    f.ajouterElement(5);
    afficherTest("hasErreur() == faux après ajout valide", !f.hasErreur());
}

/**
 * @brief Teste la sérialisation JSON de la File.
 */
void testerFileJson() {
    afficherSection("File : JSON");
    File f;

    f.ajouterElement(1);
    f.ajouterElement(2);
    f.ajouterElement(3);
    afficherTest("versJsonString() == [1,2,3]", f.versJsonString() == "[1,2,3]");

    // ajouterJsonString
    File f2;
    f2.ajouterJsonString("[7,8,9]");
    afficherTest("ajouterJsonString() : taille == 3", f2.getTaille() == 3);
    afficherTest("ajouterJsonString() : premier élément == 7", f2.getElement() == 7);
    afficherTest("hasErreur() == faux après JSON valide", !f2.hasErreur());
}

/**
 * @brief Teste la sauvegarde et le chargement de la File.
 */
void testerFileFichier() {
    afficherSection("File : sauvegarde et chargement");
    File f;

    f.ajouterElement(10);
    f.ajouterElement(20);
    f.ajouterElement(30);
    f.sauvegarder("file_test.json");
    afficherTest("sauvegarder() sans erreur", !f.hasErreur());

    File f2;
    f2.charger("file_test.json");
    afficherTest("charger() sans erreur", !f2.hasErreur());
    afficherTest("charger() : taille == 3", f2.getTaille() == 3);
    afficherTest("charger() : premier élément == 10", f2.getElement() == 10);

    // Fichier inexistant
    File f3;
    f3.charger("inexistant.json");
    afficherTest("hasErreur() == vrai si fichier inexistant", f3.hasErreur());
}

// ============================================================
// Tests de la Pile
// ============================================================

/**
 * @brief Teste les opérations de base de la Pile (LIFO).
 */
void testerPileBase() {
    afficherSection("Pile : opérations de base");
    Pile p;

    // Ajout et taille
    p.ajouterElement(10);
    p.ajouterElement(20);
    p.ajouterElement(30);
    afficherTest("getTaille() == 3 après 3 ajouts", p.getTaille() == 3);
    afficherTest("hasErreur() == faux après ajouts valides", !p.hasErreur());

    // Ordre LIFO (Last In, First Out)
    afficherTest("getElement() retourne 30 (dernier entré)", p.getElement() == 30);

    p.retirerElement();
    afficherTest("getElement() retourne 20 après un retrait", p.getElement() == 20);
    afficherTest("getTaille() == 2 après un retrait", p.getTaille() == 2);

    p.retirerElement();
    p.retirerElement();
    afficherTest("getTaille() == 0 après tous les retraits", p.getTaille() == 0);
}

/**
 * @brief Teste la méthode vider() de la Pile.
 */
void testerPileVider() {
    afficherSection("Pile : vider()");
    Pile p;

    p.ajouterElement(1);
    p.ajouterElement(2);
    p.ajouterElement(3);
    p.vider();
    afficherTest("getTaille() == 0 après vider()", p.getTaille() == 0);
    afficherTest("hasErreur() == faux après vider()", !p.hasErreur());
}

/**
 * @brief Teste la gestion des erreurs de la Pile.
 */
void testerPileErreurs() {
    afficherSection("Pile : gestion des erreurs");
    Pile p;

    // getElement sur pile vide
    p.getElement();
    afficherTest("hasErreur() == vrai si getElement() sur pile vide", p.hasErreur());
    afficherTest("getErreur() non vide si erreur", p.getErreur() != "");

    // retirerElement sur pile vide
    p.retirerElement();
    afficherTest("hasErreur() == vrai si retirerElement() sur pile vide", p.hasErreur());

    // Pas d'erreur après opération valide
    p.ajouterElement(5);
    afficherTest("hasErreur() == faux après ajout valide", !p.hasErreur());
}

/**
 * @brief Teste la sérialisation JSON de la Pile.
 */
void testerPileJson() {
    afficherSection("Pile : JSON");
    Pile p;

    p.ajouterElement(1);
    p.ajouterElement(2);
    p.ajouterElement(3);
    // LIFO : 3 est au sommet, donc affiché en premier
    afficherTest("versJsonString() == [3,2,1]", p.versJsonString() == "[3,2,1]");

    // ajouterJsonString
    Pile p2;
    p2.ajouterJsonString("[4,5,6]");
    afficherTest("ajouterJsonString() : taille == 3", p2.getTaille() == 3);
    afficherTest("ajouterJsonString() : sommet == 6", p2.getElement() == 6);
    afficherTest("hasErreur() == faux après JSON valide", !p2.hasErreur());
}

/**
 * @brief Teste la sauvegarde et le chargement de la Pile.
 */
void testerPileFichier() {
    afficherSection("Pile : sauvegarde et chargement");
    Pile p;

    p.ajouterElement(10);
    p.ajouterElement(20);
    p.ajouterElement(30);
    p.sauvegarder("pile_test.json");
    afficherTest("sauvegarder() sans erreur", !p.hasErreur());

    Pile p2;
    p2.charger("pile_test.json");
    afficherTest("charger() sans erreur", !p2.hasErreur());
    afficherTest("charger() : taille == 3", p2.getTaille() == 3);
    afficherTest("charger() : sommet == 30", p2.getElement() == 30);

    // Fichier inexistant
    Pile p3;
    p3.charger("inexistant.json");
    afficherTest("hasErreur() == vrai si fichier inexistant", p3.hasErreur());
}
/*
 * @brief teste de la nouvelle fonction pop.
 */
void testpop(){
    File f;
    Pile p;
    p.ajouterElement(10);
    p.ajouterElement(20);
    p.ajouterElement(30);
    f.ajouterElement(10);
    f.ajouterElement(20);
    f.ajouterElement(30);
    cout << "la file est rendu à la valeur " << f.pop() << "\n";
    cout << "La pile est rendu à la valeur " << p.pop() << "\n";
}
// Main

int main() {
    cout << "=== Jeu de tests : File et Pile ===" << endl;

    testerFileBase();
    testerFileVider();
    testerFileErreurs();
    testerFileFichier();

    testerPileBase();
    testerPileVider();
    testerPileErreurs();
    testerPileFichier();


    cout << "\n=== Résultats ===" << endl;
    cout << "Réussis : " << testsReussis << endl;
    cout << "Échoués : " << testsEchoues << endl;
    testpop();

    return 0;
}
