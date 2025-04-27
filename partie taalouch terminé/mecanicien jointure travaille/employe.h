#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "personne.h"
#include "date.h"
#include <iostream>

class Employe: virtual public Personne{
    protected:
        int id;
        double salaire;
        DATE Drecrutement;
    public:
        Employe(string nom, string prenom, int tel, int CIN, string email,int id, double salaire, DATE Drecrutement);
        Employe();

        virtual void augmentationSalaire()=0;

        void setId(int id) { this->id = id; }
        void setSalaire(double salaire) { this->salaire = salaire; }
        void setDrecrutement(DATE Drecrutement) { this->Drecrutement = Drecrutement; }
        
        friend ostream& operator<<(ostream& os, const Employe& e);
        friend istream& operator>>(istream& is, Employe& e);
        
        ~Employe();
};
#endif // EMPLOYE_H
