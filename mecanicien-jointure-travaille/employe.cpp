#include "employe.h"

///////////employe
Employe::Employe(string n, string p, int t, int c, string e,int i, double s, DATE d): 
Personne(n,p,t,c,e){
    id=i;
    salaire=s;
    Drecrutement=d;
}


void Employe::augmentationSalaire(){
    salaire=salaire*1.1;
    cout<<"salaire modifié"<<endl;

}
ostream& operator<<(ostream& os, const Employe& e) {
    os << static_cast<const Personne&>(e);
    os << "id: " << e.id << endl;
    os << "salaire: " << e.salaire << endl;
    os << "Date de recrutement: " << e.Drecrutement << endl;
    return os;
}
Employe::~Employe(){
    //cout<<"destruction de l'employe"<<endl;
}
///////////employe
