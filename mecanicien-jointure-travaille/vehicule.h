#ifndef VEHICULE_H
#define VEHICULE_H

#include <iostream>
#include <string>
using namespace std;
#include "date.h"

class vehicule{
    protected:
        string marque;
        string modele;
        DATE dateAchat;
        int kilometrage;
        string immatriculation;
    public:
        vehicule(string marque, string modele, DATE dateAchat, int kilometrage,string immatriculation);
        vehicule();

        void afficher();
        void modifierKilometrage(int kilometrage);

        friend ostream& operator<<(ostream& os, const vehicule& v);
        vehicule& operator=(const vehicule& v); 
        bool operator==(const vehicule& other) const;
        
        //getters
        string getImmatriculation() const{return immatriculation;};
        string getMarque() const { return marque; }
        string getModele() const { return modele; }
        DATE getDateAchat() const { return dateAchat; }
        int getKilometrage() const { return kilometrage; }
        //setters
        void setImmatriculation(const string& immatriculation);
        void setMarque(const string& marque);
        void setModele(const string& modele);
        void setDateAchat(const DATE& dateAchat);
        void setKilometrage(int kilometrage);

        ~vehicule();

};

#endif // VEHICULE_H