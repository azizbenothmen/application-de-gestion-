#include <iostream>
#include <string>
#include <vector>
#include"produit.h"
using namespace std;
#pragma once





class pieceMecanique : virtual public produit{
    private:
        string qualite;
        string categorie;
        string materiaux;
    public:
        pieceMecanique(string referance, double prix, DATE dateFabrication, int dureeGarantie, string qualite, string categorie, string materiaux);
        ~pieceMecanique();
        void afficherME();
        pieceMecanique();
        void  Remise(float);
        friend istream& operator>>(istream& in ,pieceMecanique& );
        friend ostream& operator<<(ostream& out , pieceMecanique& );
        void SetQualite(string qualite){this->qualite=qualite;};
        void SetCategorie(string cat){categorie=cat;};
        void SetMat(string mat){materiaux=mat;};
        string getqualite(){return qualite;};
        string getcategorie(){return categorie;};
        string getmateriaux(){return materiaux;};
};
