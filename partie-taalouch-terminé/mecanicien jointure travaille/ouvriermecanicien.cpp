#include "ouvriermecanicien.h"

///////////ouvrier mecanicien

OuvrierMecanicien::OuvrierMecanicien(string n, string p, int t, int c, string e, int i, double s, DATE d, string s1, vector<vehicule*> v) 
    : Personne(n, p, t, c, e), Employe(n, p, t, c, e, i, s, d) {
    specialite = s1;
    vehiculesEntretenus = v;
}
OuvrierMecanicien::OuvrierMecanicien() : Employe() {
    specialite = "";
    vehiculesEntretenus.clear();
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
    cout<<"salaire modifie"<<endl;
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

istream& operator>>(istream& is, OuvrierMecanicien& om) {
    is >> static_cast<Employe&>(om);

    cout << "Entrez la specialite de l'ouvrier mecanicien: ";
    is >> om.specialite;

    int nbrVehicules;
    cout << "Entrez le nombre de vehicules entretenus: ";
    is >> nbrVehicules;

    for (auto v : om.vehiculesEntretenus) {
        delete v;
    }
    om.vehiculesEntretenus.clear();

    for (int i = 0; i < nbrVehicules; ++i) {
        string marque, modele, immatriculation;
        int kilometrage;
        DATE d;
        cout << "Vehicule " << i + 1 << ":" << endl;
        cout << "  Marque: ";
        is >> marque;
        cout << "  Modele: ";
        is >> modele;
        cout << "  Date d'achat (jour mois annee): ";
        is >> d;
        cout << "  Kilometrage: ";
        is >> kilometrage;
        cout << "  Immatriculation: ";
        is >> immatriculation;

        om.vehiculesEntretenus.push_back(new vehicule(marque, modele, d, kilometrage, immatriculation));
    }

    return is;
}
OuvrierMecanicien::~OuvrierMecanicien(){
    //cout<<"destruction de l'ouvriermecanicien"<<endl;
}
///////////ouvrier mecanicien