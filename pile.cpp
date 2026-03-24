#include "pile.h"

Pile::Pile() : erreur(false), messageErreur("") {
    liste = new ListeLiee();
}

Pile::~Pile() {
    delete liste;
    liste = nullptr;
}

void Pile::ajouterElement(int valeur) {
    erreur = false;
    liste->ajouterElement(valeur);
    if (erreurliste()) {
        return;
    }
}

int Pile::getElement() {
    erreur = false;
    if (liste->getTaille() == 0) {
        erreur = true;
        messageErreur = "Erreur : la pile est vide.";
        return -1;
    }
    return liste->getElement(0);
}

void Pile::retirerElement() {
    erreur = false;
    if (liste->getTaille() == 0) {
        erreur = true;
        messageErreur = "Erreur : la pile est vide.";
        return;
    }
    liste->retirerElement(0);
    if (erreurliste()) {
        return;
    }
}

void Pile::vider() {
    erreur = false;
    liste->vider();
    if (erreurliste()) {
        return;
    }
}

int Pile::getTaille() {
    erreur = false;
    return liste->getTaille();
}

std::string Pile::versJsonString() {
    erreur = false;
    std::string json = liste->versJsonString();
    if (erreurliste()) {
        return "";
    }
    return json;
}

void Pile::sauvegarder(std::string nomFichier) {
    erreur = false;
    liste->sauvegarder(nomFichier);
    if (erreurliste()) {
        return;
    }
}

void Pile::ajouterJsonString(std::string jsonString) {
    erreur = false;
    liste->ajouterJsonString(jsonString);
    if (erreurliste()) {
        return;
    }
}

void Pile::charger(std::string nomFichier) {
    erreur = false;
    liste->charger(nomFichier);
    if (erreurliste()) {
        return;
    }
}

bool Pile::hasErreur() {
    return erreur;
}

std::string Pile::getErreur() {
    return messageErreur;
}

bool Pile::erreurliste() {
    if (liste->hasErreur()) {
        erreur = true;
        messageErreur = liste->getErreur();
    }
    return true;
}
