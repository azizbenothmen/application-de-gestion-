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

ostream& operator<<(ostream& os, const DATE& d) {
    os << d.jour << "/" << d.mois << "/" << d.annee;
    return os;
}

DATE& DATE::operator=(const DATE& d) {
    if (this != &d) { // Vérification d'auto-affectation
        jour = d.jour;
        mois = d.mois;
        annee = d.annee;
    }
    return *this; // Retourne une référence à l'objet courant
}


DATE::~DATE(){
    cout<<"destruction de la date"<<endl;
}
///////////date

///////////personne
Personne::Personne(string n, string p, int t, int c, string e)
{
    nom=n;
    prenom=p;
    tel=t;
    CIN=c;
    email=e;
}

Personne::Personne() {
    nom = "";
    prenom = "";
    tel = 0;
    CIN = 0;
    email = "";
}

void Personne::afficher(){
    cout<<"nom: "<<nom<<endl;
    cout<<"prenom: "<<prenom<<endl;
    cout<<"tel: "<<tel<<endl;
    cout<<"CIN: "<<CIN<<endl;
    cout<<"email: "<<email<<endl;    
}

ostream& operator<<(ostream& os, const Personne& p) {
    os << "nom: " << p.nom << endl;
    os << "prenom: " << p.prenom << endl;
    os << "tel: " << p.tel << endl;
    os << "CIN: " << p.CIN << endl;
    os << "email: " << p.email << endl;
    return os;
}

void Personne::modifier(int t, string e){
    tel=t;
    email=e;
}

istream& operator>>(istream& is, Personne& p) {
    cout << "Entrez le nom: ";
    is >> p.nom;
    cout << "Entrez le prenom: ";
    is >> p.prenom;
    cout << "Entrez le telephone: ";
    is >> p.tel;
    cout << "Entrez le CIN: ";
    is >> p.CIN;
    cout << "Entrez l'email: ";
    is >> p.email;
    return is;
}

Personne::~Personne(){
    cout<<"destruction de la personne"<<endl;
}
///////////personne

///////////vehicule
vehicule::vehicule(string ma, string mo, DATE da, int k,string i){
    immatriculation=i;
    marque=ma;
    modele=mo;
    dateAchat=da;
    kilometrage=k;
}

vehicule::vehicule(){
    immatriculation="";
    marque="";
    modele="";
    kilometrage=0;
}

void vehicule::afficher(){
    cout<<"immatriculation: "<<immatriculation<<endl;
    cout<<"marque: "<<marque<<endl;
    cout<<"modele: "<<modele<<endl;
    cout<<"date d'achat: ";
    dateAchat.afficher();
    cout<<"kilometrage: "<<kilometrage<<endl;
}

ostream& operator<<(ostream& os, const vehicule& v) {
    os << "immatriculation: " << v.immatriculation << endl;
    os << "marque: " << v.marque << endl;
    os << "modele: " << v.modele << endl;
    os << "date d'achat: " << v.dateAchat << endl;
    os << "kilometrage: " << v.kilometrage << endl;
    return os;
}

vehicule& vehicule::operator=(const vehicule& v) {
    if (this != &v) { // Vérification d'auto-affectation
        marque = v.marque;
        modele = v.modele;
        dateAchat = v.dateAchat; // Utilise l'opérateur = de DATE
        kilometrage = v.kilometrage;
        immatriculation = v.immatriculation;
    }
    return *this; // Retourne une référence à l'objet courant
}

void vehicule::modifierKilometrage(int k){
    kilometrage=k;
}

string vehicule::getImmatriculation() const {
    return immatriculation;
}

vehicule::~vehicule(){
    cout<<"destruction du vehicule"<<endl;
}
///////////vehicule

///////////client
Client::Client(string n, string p, int t, int c, string e,int i, string ty, DATE d,int nbrV, vector<vehicule*> v): Personne(n,p,t,c,e){
    id=i;
    type=ty;
    ddv=d;
    nbrVehicules=nbrV;
    vehicules=v;
}

Client::Client(){
    id=0;
    type="";
    ddv=DATE(0,0,0);
    nbrVehicules=0;
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

Client Client::operator+(const Client& other) {
    Client result(*this);
    for (int i = 0; i < other.nbrVehicules; i++) {
        result.ajouterVehicule(new vehicule(*other.vehicules[i]));
    }
    result.nbrVehicules = this->nbrVehicules + other.nbrVehicules;
    return result;
}

Client& Client::operator=(const Client& other) {
    if (this != &other) {  // Vérification d'auto-affectation
        // Copie des membres de Personne
        nom = other.nom;
        prenom = other.prenom;
        tel = other.tel;
        CIN = other.CIN;
        email = other.email;

        // Copie des membres spécifiques à Client
        id = other.id;
        type = other.type;
        ddv = other.ddv;  // Utilise l'opérateur = de DATE
        nbrVehicules = other.nbrVehicules;

        // Libération des anciens véhicules
        for (auto v : vehicules) {
            delete v;
        }
        vehicules.clear();

        // Copie profonde des véhicules
        for (auto v : other.vehicules) {
            vehicules.push_back(new vehicule(*v));
        }
    }
    return *this;  // Retourne une référence à l'objet courant
}

istream& operator>>(istream& is, Client& c) {
    // Lecture des données de Personne
    is >> static_cast<Personne&>(c);
    
    cout << "Entrez l'ID client: ";
    is >> c.id;
    cout << "Entrez le type (particulier/professionnel): ";
    is >> c.type;
    
    cout << "Entrez la date de derniere visite (jour mois annee): ";
    int j, m, a;
    is >> j >> m >> a;
    c.ddv = DATE(j, m, a);
    
    cout << "Entrez le nombre de vehicules: ";
    is >> c.nbrVehicules;
    
    // Nettoyer les véhicules existants
    for (auto v : c.vehicules) {
        delete v;
    }
    c.vehicules.clear();
    
    // Lecture des véhicules
    for (int i = 0; i < c.nbrVehicules; i++) {
        cout << "Vehicule " << i+1 << ":" << endl;
        string marque, modele, immatriculation;
        int kilometrage;
        int j, m, a;
        
        cout << "  Marque: ";
        is >> marque;
        cout << "  Modele: ";
        is >> modele;
        cout << "  Date d'achat (jour mois annee): ";
        is >> j >> m >> a;
        cout << "  Kilometrage: ";
        is >> kilometrage;
        cout << "  Immatriculation: ";
        is >> immatriculation;
        
        c.vehicules.push_back(new vehicule(marque, modele, DATE(j, m, a), kilometrage, immatriculation));
    }
    
    return is;
}

void Client::ajouterVehicule(vehicule* v){
    vehicules.push_back(v);
    nbrVehicules++;
}

void Client::deleteVehicule(string immatriculation){
    for (int j=0; j<nbrVehicules; j++){
        if (vehicules[j]->getImmatriculation() == immatriculation) {
            delete vehicules[j];
            vehicules.erase(vehicules.begin()+j);
            nbrVehicules--;
            break;
        }
    }
}

void Client::afficher(){
    Personne::afficher();
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

ostream& operator<<(ostream& os, const Client& c) {
    os << static_cast<const Personne&>(c);
    os << "id: " << c.id << endl;
    os << "type: " << c.type << endl;
    os << "date de derniere visite: " << c.ddv << endl;
    os << "nombre de vehicules: " << c.nbrVehicules << endl;
    for (int i = 0; i < c.nbrVehicules; i++) {
        os << "vehicule NUMERO : " << i+1 << endl;
        os << *(c.vehicules[i]) << endl;
    }
    return os;
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

///////////client

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
    cout<<"destruction de l'employe"<<endl;
}
///////////employe

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
    cout<<"destruction de l'ouvrier mecanicien"<<endl;
}
///////////ouvrier mecanicien

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
    cout<<"destruction du gestionnaire"<<endl;
}
///////////gestionnaire

///////////client employee
ClientEmployee::ClientEmployee(string n, string p, int t, int c, string e, int clientId, string type, DATE ddv, vector<vehicule*> vehicules, int employeId, double salaire, DATE Drecrutement)
    : Personne(n, p, t, c, e), Employe(n, p, t, c, e, employeId, salaire, Drecrutement), Client(n, p, t, c, e, clientId, type, ddv, 0, vehicules) {
    rabaisEmploye = 0.1; 
    nombreTransactions = 0;
    nbrTransactionsmax = 10; 
}
void ClientEmployee::augmentationSalaire() {
    salaire=salaire*1.25;
    cout<<"salaire modifié"<<endl;
}
void ClientEmployee::afficher() {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Tel: " << tel << endl;
    cout << "CIN: " << CIN << endl;
    cout << "Email: " << email << endl;
    cout << "Rabais employe: " << rabaisEmploye * 100 << "%" << endl;
    cout << "Nombre de transactions: " << nombreTransactions << endl;
}

ostream& operator<<(ostream& os, const ClientEmployee& ce) {
    os << "Nom: " << ce.nom << endl;
    os << "Prenom: " << ce.prenom << endl;
    os << "Tel: " << ce.tel << endl;
    os << "CIN: " << ce.CIN << endl;
    os << "Email: " << ce.email << endl;
    os << "Rabais employe: " << ce.rabaisEmploye * 100 << "%" << endl;
    os << "Nombre de transactions: " << ce.nombreTransactions << endl;
    return os;
}
void ClientEmployee::afficherAvantages() {
    cout << "Avantages: " << endl;
    for (const auto& avantage : avantages) {
        cout << "- " << avantage << endl;
    }
}
void ClientEmployee::ajouterAvantage(string avantage) {
    avantages.push_back(avantage);
}

ClientEmployee::~ClientEmployee() {
    cout << "Destruction de ClientEmployee" << endl;
}
///////////client employee
