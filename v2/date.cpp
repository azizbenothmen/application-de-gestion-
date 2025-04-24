#include "date.h"
using namespace std;

///////////date
DATE::DATE(){
    jour=0;
    mois=0;
    annee=0;
}

DATE::DATE(int j, int m, int a){
    jour=j;
    mois=m;
    annee=a;
}

void DATE::afficher(){
    cout<<jour<<"/"<<mois<<"/"<<annee<<endl;
}

ostream& operator<<(ostream& os, const DATE& d) {
    os << d.jour << "/" << d.mois << "/" << d.annee;
    return os;
}

DATE& DATE::operator=(const DATE& d) {
    if (this != &d) { 
        jour = d.jour;
        mois = d.mois;
        annee = d.annee;
    }
    return *this;
}


DATE::~DATE(){
   // cout<<"destruction de la date"<<endl;
}
///////////date