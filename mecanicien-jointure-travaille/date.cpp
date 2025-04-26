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

///othmane
DATE DATE::comp(DATE d){
    DATE d2,d3;
    bool T,T2,T3;
    T=annee<d.annee;
    T2=d.mois<mois;
    T3=d.jour<jour;
    
    
    if (annee<d.annee){
        cout<<"cAnnee"<<endl;
        d2=d;
    }
    else if((annee==d.annee)&&(d.mois<mois)){
        cout<<"cMois"<<endl;
        d2=d;
    }
    else if((annee==d.annee)&&(d.mois==mois)&&(d.jour<jour)){
        cout<<"cJours"<<endl;
        d2=d;
    }
    else{
       cout<<"ELSE"<<endl;
       cout<<"annee="<<annee<<endl;
       DATE d3(jour,mois,annee);
       d3.afficher();
       return d3;
    }
    cout<<"d2="<<endl;
    d2.afficher();
    return d2;

}

istream& operator>>(istream& in,DATE& d){
    cout<<"donner la date "<<endl;
    in>>d.jour;
    in>>d.mois;
    in>>d.annee;
    return in;
}
///////////date