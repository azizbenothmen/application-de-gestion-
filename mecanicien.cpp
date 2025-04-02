#include <iostream>
#include "mecanicien.h"
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


DATE::~DATE(){
    cout<<"destruction de la date"<<endl;
}
/////////////////////////

///////////personne
Personne::Personne(string n, string p, int t, int c, string e){
    nom=n;
    prenom=p;
    tel=t;
    CIN=c;
    email=e;
}

void Personne::modifier(int t, string e){
    tel=t;
    email=e;
}

Personne::~Personne(){
    cout<<"destruction de la personne"<<endl;
}
/////////////////////////

///////////vehicule
vehicule::vehicule(string i, string ma, string mo, DATE da, int k){
    immatriculation=i;
    marque=ma;
    modele=mo;
    dateAchat=da;
    kilometrage=k;
}

void vehicule::afficher(){
    cout<<"immatriculation: "<<immatriculation<<endl;
    cout<<"marque: "<<marque<<endl;
    cout<<"modele: "<<modele<<endl;
    cout<<"date d'achat: ";
    dateAchat.afficher();
    cout<<"kilometrage: "<<kilometrage<<endl;
}

void vehicule::modifierKilometrage(int k){
    kilometrage=k;
}

vehicule::~vehicule(){
    cout<<"destruction du vehicule"<<endl;
}
/////////////////

///////////client
Client::Client(string n, string p, int t, int c, string e,int i, string ty, DATE d,int nbrV, vector<vehicule*> v): Personne(n,p,t,c,e){
    id=i;
    type=ty;
    ddv=d;
    nbrVehicules=nbrV;
    vehicules=v;
}

Client::Client(const Client& other): Personne(other.nom, other.prenom, other.tel, other.CIN, other.email){
    id=other.id;
    type=other.type;
    ddv=other.ddv;
    nbrVehicules=other.nbrVehicules;
    for (int i=0; i<other.nbrVehicules; i++){
        vehicules.push_back(new vehicule(*other.vehicules[i])); 
    }
}

void Client::ajouterVehicule(vehicule* v){
    vehicules.push_back(v);
    nbrVehicules++;
}

void Client::deleteVehicule(vehicule *v){
   /* vector<vehicule*> temp;
    for (int i = 0; i < nbrVehicules; i++) {
        if (vehicules[i] != v) {
            temp.push_back(vehicules[i]); 
        }
    }
    vehicules = temp; 
    nbrVehicules--; */

    for (int i=0; i<nbrVehicules; i++){
        if (vehicules[i]==v){
            vehicules.erase(vehicules.begin()+i);
            nbrVehicules--;
            break;
        }
    }
}

Client::~Client(){
    for (int i=0; i<nbrVehicules; i++) {
        delete vehicules[i]; 
    }
    cout<<"destruction du client"<<endl;
}
   