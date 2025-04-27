#include <iostream>
#include <string>
#include <vector>
#include"date.h"
using namespace std;
#pragma once






class produit
{
    protected:
        string referance;
        double prix;
        DATE dateFabrication;
        int dureeGarantie;
        static int compteur;
    public:
        produit(string referance, double prix, DATE dateFabrication, int dureeGarantie);
        produit();
        void virtual Remise(float)=0;
        void  virtual  afficherdetailsp();
        static int getCompteur() { return compteur; };
        friend istream& operator>>(istream& in,produit&);
        friend ostream& operator<<(ostream& out , produit& );
        void creerFichier(const string& p);
        void enregistrerFichier(const string& p) const;
        void afficherFichier(const string& p);
        ~produit();
};

