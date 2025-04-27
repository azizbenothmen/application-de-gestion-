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
        friend istream& operator>>(istream& in ,pieceMecanique& );
        friend ostream& operator<<(ostream& out , pieceMecanique& );
        string getqualite(){return qualite;};
        string getcategorie(){return categorie;};
        string getmateriaux(){return materiaux;};
};
