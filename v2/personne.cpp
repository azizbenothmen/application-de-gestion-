#include <iostream>
#include "personne.h"
using namespace std;
#include <fstream>
#include <sstream>
#include <stdexcept>

///////////personne
Personne::Personne(string n, string p, int t, int c, string e)
{
    nom=n;
    prenom=p;
    tel=t;
    CIN=c;
    email=e;
}

Personne::Personne() {
    nom = "";
    prenom = "";
    tel = 0;
    CIN = 0;
    email = "";
}

void Personne::afficher(){
    cout<<"nom: "<<nom<<endl;
    cout<<"prenom: "<<prenom<<endl;
    cout<<"tel: "<<tel<<endl;
    cout<<"CIN: "<<CIN<<endl;
    cout<<"email: "<<email<<endl;    
}

ostream& operator<<(ostream& os, const Personne& p) {
    os << "nom: " << p.nom << endl;
    os << "prenom: " << p.prenom << endl;
    os << "tel: " << p.tel << endl;
    os << "CIN: " << p.CIN << endl;
    os << "email: " << p.email << endl;
    return os;
}

void Personne::modifier(int t, string e){
    tel=t;
    email=e;
}

istream& operator>>(istream& is, Personne& p) {
    cout << "Entrez le nom: ";
    is >> p.nom;
    cout << "Entrez le prenom: ";
    is >> p.prenom;
    cout << "Entrez le telephone: ";
    is >> p.tel;
    cout << "Entrez le CIN: ";
    is >> p.CIN;
    cout << "Entrez l'email: ";
    is >> p.email;
    return is;
}
Personne& Personne::operator=(const Personne& other) {
    if (this != &other) { 
        nom = other.nom;
        prenom = other.prenom;
        tel = other.tel;
        CIN = other.CIN;
        email = other.email;
    }
    return *this; 
}
Personne::~Personne(){
    //cout<<"destruction du personne"<<endl;
}
///////////fichiers
void Personne::creerFichier(const string& f) {
    try {
        ofstream file(f, ios::out | ios::trunc);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de la creation du fichier: "+f);
        }
        file.close();
    } catch (exception& e) {
        cout <<"Exception: "<<e.what()<<endl;
    }
}

void Personne::enregistrer(const string& f) const {
    try {
        ofstream file(f, ios::out | ios::app);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier pour l'ecriture: " + f);
        }
        file << nom << endl;
        file << prenom << endl;
        file << tel << endl;
        file << CIN << endl;
        file << email << endl;
        file.close();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void Personne::recuperer(const string& f, Personne& p) {
    try {
        ifstream file(f, ios::in);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier pour la lecture: "+f);
        }

        getline(file, p.nom);
        getline(file, p.prenom);
        file >> p.tel;
        file.ignore(); 
        file >> p.CIN;
        file.ignore(); 
        getline(file, p.email);

        file.close();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}
///////////personne