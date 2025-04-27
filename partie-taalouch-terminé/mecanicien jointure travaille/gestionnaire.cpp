#include "gestionnaire.h"

///////////gestionnaire
Gestionnaire::Gestionnaire(string n, string p, int t, int c, string e,int i, double s, DATE d, bool a, string ty): Personne(n, p, t, c, e), Employe(n, p, t, c, e, i, s, d){
    accesCaisse=a;
    type=ty;
}
Gestionnaire::Gestionnaire() : Employe() {
    accesCaisse = false;
    type = "";
}
void Gestionnaire::augmentationSalaire(){
        salaire=salaire*1.3;
        cout<<"salaire modifie"<<endl;
    
}
void Gestionnaire::afficher() {
    Personne::afficher();
    cout << "id: " << id << endl;
    cout << "salaire: " << salaire << endl;
    cout << "Date de recrutement: ";
    Drecrutement.afficher();
    cout << "Acces caisse: " << (accesCaisse ? "Oui" : "Non") << endl;
    cout << "Type: " << type << endl;
}

ostream& operator<<(ostream& os, const Gestionnaire& g) {
    os << static_cast<const Employe&>(g);
    os << "Acces caisse: " << (g.accesCaisse ? "Oui" : "Non") << endl;
    os << "Type: " << g.type << endl;
    return os;
}

istream& operator>>(istream& is, Gestionnaire& g) {
    is >> static_cast<Employe&>(g);

    cout << "Entrez si le gestionnaire a acces a la caisse (1 pour Oui, 0 pour Non): ";
    is >> g.accesCaisse;
    cout << "Entrez le type de gestionnaire: ";
    is >> g.type;

    return is;
}

Gestionnaire::~Gestionnaire(){
    //cout<<"destruction du gestionnaire"<<endl;
}
///////////gestionnaire