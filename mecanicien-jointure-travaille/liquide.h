#include <iostream>
#include <string>
#include <vector>
#include"produit.h"
using namespace std;
#pragma once



class liquide : public virtual produit{
    private:
        string flammable;
        float volume;
        string viscosite;
        string contenance;
        string type;
        string description;
    public:
        liquide(string referance, double prix, DATE dateFabrication, int dureeGarantie, string flammable, float volume, string viscosite, string contenance, string type, string description);
        liquide();
        friend istream& operator>>(istream& in ,liquide& );
        friend ostream& operator<<(ostream& out,liquide&);
        //Fonctions Fichier
        void creerFichier(const string& f);
        void enregisterFichierLiquide(const string& f) const;
        void afficherFichierLiquide(const string& f);
        ~liquide();
};
