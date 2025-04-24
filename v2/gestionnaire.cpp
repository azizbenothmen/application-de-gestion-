#include "gestionnaire.h"

///////////gestionnaire
Gestionnaire::Gestionnaire(string n, string p, int t, int c, string e,int i, double s, DATE d, bool a, string ty): Personne(n, p, t, c, e), Employe(n, p, t, c, e, i, s, d){
    accesCaisse=a;
    type=ty;
}

void Gestionnaire::augmentationSalaire(){
        salaire=salaire*1.3;
        cout<<"salaire modifié"<<endl;
    
}
void Gestionnaire::afficher() {
    Personne::afficher();
    cout << "Acces caisse: " << (accesCaisse ? "Oui" : "Non") << endl;
    cout << "Type: " << type << endl;
}

ostream& operator<<(ostream& os, const Gestionnaire& g) {
    os << static_cast<const Employe&>(g);
    os << "Acces caisse: " << (g.accesCaisse ? "Oui" : "Non") << endl;
    os << "Type: " << g.type << endl;
    return os;
}

Gestionnaire::~Gestionnaire(){
    //cout<<"destruction du gestionnaire"<<endl;
}
///////////gestionnaire