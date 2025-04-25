#include"date.h"
#include<string>
#include<iostream>
using namespace std;
#pragma once



class facture{
    private:
        string id;
        float montant;
        DATE date;
        string modepaiement;
        string status;
    public:
        facture(string id, float montant, DATE date, string modepaiement, string status);
        void afficherfacture();
        facture();
        float calculTax(int);
        friend istream& operator>>(istream& in ,facture& );
        friend ostream& operator<<(ostream& out,facture&);
        facture operator+(const facture& );
        ~facture();
};