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

void Client::deleteVehicule(string immatriculation){
    for (int j=0; j<nbrVehicules; j++){
        if (vehicules[j]->immatriculation==immatriculation){
            delete vehicules[j];
            vehicules.erase(vehicules.begin()+j);
            nbrVehicules--;
            break;
        }
    }
}

void Client::afficher(){
    cout<<"nom: "<<nom<<endl;
    cout<<"prenom: "<<prenom<<endl;
    cout<<"tel: "<<tel<<endl;
    cout<<"CIN: "<<CIN<<endl;
    cout<<"email: "<<email<<endl;    
    cout<<"id: "<<id<<endl;
    cout<<"type: "<<type<<endl;
    cout<<"date de derniere visite: ";
    ddv.afficher();
    cout<<"nombre de vehicules: "<<nbrVehicules<<endl;
    for (int i=0; i<nbrVehicules; i++){
        cout<<"vehicule NUMERO : "<<i+1<<endl;
        vehicules[i]->afficher();
    }
}
void Client::modifier(int t, string e){
    tel=t;
    email=e;
}

Client::~Client(){
    for (int i=0; i<nbrVehicules; i++) {
        delete vehicules[i]; 
    }
    cout<<"destruction du client"<<endl;
}

///////////////////////
///////////employe
Employe::Employe(string n, string p, int t, int c, string e,int i, double s, DATE d): Personne(n,p,t,c,e){
    id=i;
    salaire=s;
    Drecrutement=d;
}

void Employe::afficherDetails(){
    cout<<"id: "<<id<<endl;
    cout<<"salaire: "<<salaire<<endl;
    cout<<"date de recrutement: ";
    Drecrutement.afficher();
}
Employe::~Employe(){
    cout<<"destruction de l'employe"<<endl;
}
///////////////////////

///////////ouvrier mecanicien

OuvrierMecanicien::OuvrierMecanicien(string n, string p, int t, int c, string e,int i, double s, DATE d, string s1, vector<vehicule*> v): Employe(n,p,t,c,e,i,s,d){
    specialite=s1;
    vehiculesEntretenus=v;
}

OuvrierMecanicien::OuvrierMecanicien(const OuvrierMecanicien& other): Employe(other.nom, other.prenom, other.tel, other.CIN, other.email, other.id, other.salaire, other.Drecrutement){
    specialite=other.specialite;
    for (int i=0; i<other.vehiculesEntretenus.size(); i++){
        vehiculesEntretenus.push_back(new vehicule(*other.vehiculesEntretenus[i])); 
    }
}
void OuvrierMecanicien::afficherDetails(){
    Employe::afficherDetails();
    cout<<"specialite: "<<specialite<<endl;
    cout<<"vehicules entretiens: "<<endl;
    for (int i=0; i<vehiculesEntretenus.size(); i++){
        vehiculesEntretenus[i]->afficher();
    }
}

OuvrierMecanicien::~OuvrierMecanicien(){
    cout<<"destruction de l'ouvrier mecanicien"<<endl;
}
///////////////////////
///////////gestionnaire
Gestionnaire::Gestionnaire(string n, string p, int t, int c, string e,int i, double s, DATE d, bool a, string ty): Employe(n,p,t,c,e,i,s,d){
    accesCaisse=a;
    type=ty;
}

void Gestionnaire::afficherDetails(){
    Employe::afficherDetails();
    cout<<"acces caisse: "<<accesCaisse<<endl;
    cout<<"type: "<<type<<endl;
}
Gestionnaire::~Gestionnaire(){
    cout<<"destruction du gestionnaire"<<endl;
}
///////////////////////
///////////client employee
ClientEmployee::ClientEmployee(string n, string p, int t, int c, string e, int clientId, string type, DATE ddv, vector<vehicule*> vehicules, int employeId, double salaire, DATE Drecrutement)
    : Employe(n, p, t, c, e, employeId, salaire, Drecrutement), Client(n, p, t, c, e, clientId, type, ddv, 0, vehicules) {
    rabaisEmploye = 0.1; 
    nombreTransactions = 0;
    nbrTransactionsmax = 10; 
}

ClientEmployee::~ClientEmployee() {
    cout << "Destruction de ClientEmployee" << endl;
}
///////////////////////