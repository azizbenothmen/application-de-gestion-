#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma once

class Personne{
    protected:
        string nom;
        string prenom;
        int tel;
        int CIN;
        string email;
    public:
        Personne(string nom, string prenom, int tel, int CIN, string email);
        Personne();

        virtual void afficher()=0;

        void modifier(int tel, string email);

        friend ostream& operator<<(ostream& os, const Personne& p);  
        friend istream& operator>>(istream& is, Personne& p);
        Personne& operator=(const Personne& other);
        
        //fichiers
        void creerFichier(const string& f);
        void enregistrerFichier(const string& f) const;
        //void recuperer(const string& f, Personne& p);
        void afficherFichier(const string& f);

        ~Personne();


};