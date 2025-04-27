#include "vehicule.h"
#include <fstream>
#include <sstream>
///////////vehicule
vehicule::vehicule(string ma, string mo, DATE da, int k,string i){
    immatriculation=i;
    marque=ma;
    modele=mo;
    dateAchat=da;
    kilometrage=k;
}

vehicule::vehicule(){
    immatriculation="";
    marque="";
    modele="";
    kilometrage=0;
}

void vehicule::afficher() {
    cout << "immatriculation: " << immatriculation << endl;
    cout << "marque: " << marque << endl;
    cout << "modele: " << modele << endl;
    cout << "date d'achat: ";
    dateAchat.afficher();
    cout << "kilometrage: " << kilometrage << endl;
}
ostream& operator<<(ostream& os, const vehicule& v) {
    os << "immatriculation: " << v.immatriculation << endl;
    os << "marque: " << v.marque << endl;
    os << "modele: " << v.modele << endl;
    os << "date d'achat: " << v.dateAchat << endl;
    os << "kilometrage: " << v.kilometrage << endl;
    return os;
}

istream& operator>>(istream& is, vehicule& v) {
    cout << "Entrez la marque du vehicule: ";
    is >> v.marque;
    cout << "Entrez le modele du vehicule: ";
    is >> v.modele;
    cout << "Entrez la date d'achat (jour mois annee): ";
    is >> v.dateAchat;
    cout << "Entrez le kilometrage du vehicule: ";
    is >> v.kilometrage;
    cout << "Entrez l'immatriculation du vehicule: ";
    is >> v.immatriculation;
    return is;
}

vehicule& vehicule::operator=(const vehicule& v) {
    if (this != &v) { 
        marque = v.marque;
        modele = v.modele;
        dateAchat = v.dateAchat; 
        kilometrage = v.kilometrage;
        immatriculation = v.immatriculation;
    }
    return *this; 
}

bool vehicule::operator==(const vehicule& other) const {
    return (immatriculation == other.immatriculation &&
            marque == other.marque &&
            modele == other.modele &&
            kilometrage == other.kilometrage &&
            dateAchat.getAnnee() == other.dateAchat.getAnnee() &&
            dateAchat.getMois() == other.dateAchat.getMois() &&
            dateAchat.getJour() == other.dateAchat.getJour());
}

void vehicule::modifierKilometrage(int k){
    kilometrage=k;
}

void vehicule::setImmatriculation(const string& immatriculation) {
    this->immatriculation = immatriculation;
}

void vehicule::setMarque(const string& marque) {
    this->marque = marque;
}

void vehicule::setModele(const string& modele) {
    this->modele = modele;
}

void vehicule::setDateAchat(const DATE& dateAchat) {
    this->dateAchat = dateAchat;
}

void vehicule::setKilometrage(int kilometrage) {
    this->kilometrage = kilometrage;
}
vehicule::~vehicule(){
    //cout<<"destruction du vehicule"<<endl;
}
///////////vehicule
