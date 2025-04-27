#include "client.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
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
    if (this != &other) {  
        nom = other.nom;
        prenom = other.prenom;
        tel = other.tel;
        CIN = other.CIN;
        email = other.email;

        id = other.id;
        type = other.type;
        ddv = other.ddv; 
        nbrVehicules = other.nbrVehicules;

        for (auto v : vehicules) {
            delete v;
        }
        vehicules.clear();

        for (auto v : other.vehicules) {
            vehicules.push_back(new vehicule(*v));
        }
    }
    return *this; 
}

istream& operator>>(istream& is, Client& c) {
    is >> static_cast<Personne&>(c);
    
    cout << "Entrez l'ID client: ";
    is >> c.id;
    cout << "Entrez le type (particulier/professionnel): ";
    is >> c.type;
    
    cout << "Entrez la date de derniere visite (jour mois annee): ";
    is >> c.ddv; 

    cout << "Entrez le nombre de vehicules: ";
    is >> c.nbrVehicules;
    
    for (auto v : c.vehicules) {
        delete v;
    }
    c.vehicules.clear();
    
    for (int i = 0; i < c.nbrVehicules; i++) {
        cout << "Vehicule " << i+1 << ":" << endl;
        string marque, modele, immatriculation;
        int kilometrage;
        DATE d;
        
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
        
        c.vehicules.push_back(new vehicule(marque, modele, d, kilometrage, immatriculation));
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
    //cout<<"destruction du client"<<endl;
}

///////////fichiers
void Client::creerFichier(const string& f) {
    Personne::creerFichier(f);
}

void Client::enregistrerFichier(const string& f) const {
    try {
        Personne::enregistrerFichier(f);
        ofstream file(f, ios::out | ios::app);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier pour l'ecriture: " + f);
        }
        file << id << endl;
        file << type << endl;
        file << ddv.getJour() << "/" << ddv.getMois() << "/" << ddv.getAnnee() << endl;
        file << nbrVehicules << endl;

        for (int i = 0; i < nbrVehicules; i++) {
            file << *(vehicules[i]) << endl;
        }

        file.close();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void Client::afficherFichier(const string& f) {
    try {
        ifstream file(f, ios::in);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier pour la lecture: " + f);
        }
        Personne::afficherFichier(f);
        string line;
        getline(file, line); 
        cout << "id: " << line << endl;
        getline(file, line); 
        cout << "type: " << line << endl;
        getline(file, line); 
        cout << "date de derniere visite: " << line << endl;

        getline(file, line);
        int nbrVehicules = stoi(line);
        cout << "nombre de vehicules: " << nbrVehicules << endl;

        for (int i = 0; i < nbrVehicules; ++i) {
            while (getline(file, line)) {
                if (line.empty()) continue; 
                cout << line << endl;
            }
        }

        file.close();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

/*void Client::recuperer(const string& f, Client& c) {
    try {
        ifstream file(f, ios::in);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier pour la lecture: " + f);
        }

        // personne
        getline(file, c.nom);
        getline(file, c.prenom);
        file >> c.tel;
        file.ignore(); 
        file >> c.CIN;
        file.ignore(); 
        getline(file, c.email);

        // client
        file >> c.id;
        file.ignore(); 
        getline(file, c.type);
        string dateStr;
        getline(file, dateStr);
        DATE date;
        size_t partie1 = dateStr.find('/');
        size_t partie2 = dateStr.find('/', partie1 + 1);
        if (partie1 != string::npos && partie2 != string::npos) {
            string jourStr = dateStr.substr(0, partie1);
            string moisStr = dateStr.substr(partie1 + 1, partie2 - partie1 - 1);
            string anneeStr = dateStr.substr(partie2 + 1);

            int jour = atoi(jourStr.c_str());
            int mois = atoi(moisStr.c_str());
            int annee = atoi(anneeStr.c_str());

            c.ddv = DATE(jour, mois, annee);
        }

        file >> c.nbrVehicules;
        file.ignore();

        // vehicules
        c.vehicules.clear();
        for (int i = 0; i < c.nbrVehicules; i++) {
            vehicule* v = new vehicule();
            string line;

            while (getline(file, line)) {
                if (line.find("immatriculation:") != string::npos) {
                    break;
                }
            }
            v->setImmatriculation(line.substr(line.find(": ")+2));
            getline(file, line);
            v->setMarque(line.substr(line.find(": ")+2));
            getline(file, line);
            v->setModele(line.substr(line.find(": ")+2));
            getline(file, line);
            DATE dateAchat;
            size_t partie1 = line.find('/');
            size_t partie2 = line.find('/', partie1 + 1);
            if (partie1 != string::npos && partie2 != string::npos) {
                string jourStr = line.substr(line.find(": ")+2, partie1 - 2);
                string moisStr = line.substr(partie1 + 1, partie2 - partie1 - 1);
                string anneeStr = line.substr(partie2 + 1);

                int jour = atoi(jourStr.c_str());
                int mois = atoi(moisStr.c_str());
                int annee = atoi(anneeStr.c_str());

                v->setDateAchat(DATE(jour, mois, annee));
            }
            getline(file, line);
            v->setKilometrage(atoi(line.substr(line.find(": ")+2).c_str()));

            c.vehicules.push_back(v);
        }
        file.close();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}*/


///////////client