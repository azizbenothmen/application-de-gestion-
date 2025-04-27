#include "employe.h"

///////////employe
Employe::Employe(string n, string p, int t, int c, string e,int i, double s, DATE d): 
Personne(n,p,t,c,e){
    id=i;
    salaire=s;
    Drecrutement=d;
}

Employe::Employe() : Personne(), id(0), salaire(0.0), Drecrutement(0, 0, 0) {
    // Initialisation par défaut
}


void Employe::augmentationSalaire(){
    salaire=salaire*1.1;
    cout<<"salaire modifie"<<endl;

}
ostream& operator<<(ostream& os, const Employe& e) {
    os << static_cast<const Personne&>(e);
    os << "id: " << e.id << endl;
    os << "salaire: " << e.salaire << endl;
    os << "Date de recrutement: " << e.Drecrutement << endl;
    return os;
}

istream& operator>>(istream& is, Employe& e) {
    is >> static_cast<Personne&>(e);
    cout << "Entrez l'ID employe: ";
    is >> e.id;
    cout << "Entrez le salaire: ";
    is >> e.salaire;
    cout << "Entrez la date de recrutement (jour mois annee): ";
    is >> e.Drecrutement; 

    return is;
}

Employe::~Employe(){
    //cout<<"destruction de l'employe"<<endl;
}
///////////employe
