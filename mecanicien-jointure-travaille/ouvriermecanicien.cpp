#include "ouvriermecanicien.h"

///////////ouvrier mecanicien

OuvrierMecanicien::OuvrierMecanicien(string n, string p, int t, int c, string e, int i, double s, DATE d, string s1, vector<vehicule*> v) 
    : Personne(n, p, t, c, e), Employe(n, p, t, c, e, i, s, d) {
    specialite = s1;
    vehiculesEntretenus = v;
}
OuvrierMecanicien::OuvrierMecanicien(const OuvrierMecanicien& other) 
    : Personne(other), Employe(other) {
    specialite = other.specialite;
    for (int i = 0; i < other.vehiculesEntretenus.size(); i++) {
        vehiculesEntretenus.push_back(new vehicule(*other.vehiculesEntretenus[i]));
    }
}

void OuvrierMecanicien::augmentationSalaire(){
    salaire=salaire*1.2;
    cout<<"salaire modifié"<<endl;
}

void OuvrierMecanicien::afficher() {
    Personne::afficher();
    cout << "Specialite: " << specialite << endl;
    cout << "salaire: " << salaire << endl;
    cout << "Date de recrutement: ";
    Drecrutement.afficher();
    cout << "Vehicules entretenus: " << endl;
    for (auto v : vehiculesEntretenus) {
        v->afficher();
    }
}

ostream& operator<<(ostream& os, const OuvrierMecanicien& om) {
    os << static_cast<const Employe&>(om);
    os << "Specialite: " << om.specialite << endl;
    os << "Vehicules entretenus: " << endl;
    for (auto v : om.vehiculesEntretenus) {
        os << *v << endl;
    }
    return os;
}

OuvrierMecanicien::~OuvrierMecanicien(){
    //cout<<"destruction de l'ouvriermecanicien"<<endl;
}
///////////ouvrier mecanicien