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
        friend ostream& operator<<(ostream& os, const Personne& p);  
        friend istream& operator>>(istream& is, Personne& p);
        Personne& operator=(const Personne& other);
        void modifier(int tel, string email);
        ~Personne();
        //fichiers
        void creerFichier(const string& f);
        void enregistrer(const string& f) const;
        void recuperer(const string& f, Personne& p);
};