#include "file.h"

File::File() : erreur(false), messageErreur("") {
    liste = new ListeLiee();
}

File::~File() {
    delete liste;
    liste = nullptr;
}

void File::ajouterElement(int valeur) {
    erreur = false;
    liste->ajouterElement(valeur);
    if (erreurliste()) {
        return;
    }
}

int File::getElement() {
    erreur = false;
    if (liste->getTaille() == 0) {
        erreur = true;
        messageErreur = "Erreur : la file est vide.";
        return -1;
    }
    int valeur = liste->getElement(0);
    if (erreurliste()) {
        return 0;
    }
    return valeur;
}

void File::retirerElement() {
    erreur = false;
    if (liste->getTaille() == 0) {
        erreur = true;
        messageErreur = "Erreur : la file est vide.";
        return;
    }
    liste->retirerElement(0);
    if (erreurliste()) {
        return;
    }
}

void File::vider() {
    erreur = false;
    liste->vider();
    if (erreurliste()) {
        return;
    }
}

int File::getTaille() {
    erreur = false;
    return liste->getTaille();
}

std::string File::versJsonString() {
    erreur = false;
    std::string json = liste->versJsonString();
    if (erreurliste()) {
        return "";
    }
    return json;
}

void File::sauvegarder(std::string nomFichier) {
    erreur = false;
    liste->sauvegarder(nomFichier);
    if (erreurliste()) {
        return;
    }
}

void File::ajouterJsonString(std::string jsonString) {
    erreur = false;
    liste->ajouterJsonString(jsonString);
    if (erreurliste()) {
        return;
    }
}

void File::charger(std::string nomFichier) {
    erreur = false;
    liste->charger(nomFichier);
    if (erreurliste()) {
        return;
    }
}

bool File::hasErreur() {
    return erreur;
}

std::string File::getErreur() {
    return messageErreur;
}

bool File::erreurliste() {
    if (liste->hasErreur()) {
        erreur = true;
        messageErreur = liste->getErreur();
        return true;
    }
    return false;
}
