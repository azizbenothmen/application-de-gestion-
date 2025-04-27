#include "clientemploye.h"

///////////client employee
ClientEmployee::ClientEmployee(string nom, string prenom, int tel, int CIN, string email, int clientId, string type, DATE ddv,int nbrVehicules, vector<vehicule*> vehicules, int employeId, double salaire, DATE Drecrutement, int nbrTransactionsmax, vector<string> avantages, double rabaisEmploye, int nombreTransactions) : 
Client(nom, prenom, tel, CIN, email, clientId, type, ddv,nbrVehicules, vehicules), 
Employe(nom, prenom, tel, CIN, email, employeId,salaire,Drecrutement) {
    
    this->nom = nom;
    this->prenom = prenom;
    this->tel = tel;
    this->CIN = CIN;
    this->email = email;
    clientId = clientId;
    type = type;
    ddv = ddv;
    nbrVehicules = nbrVehicules;
    vehicules = vehicules;
    employeId = employeId;
    this->salaire = salaire;
    this->Drecrutement = Drecrutement;

    this->rabaisEmploye = rabaisEmploye;
    this->nombreTransactions = nombreTransactions;
    this->nbrTransactionsmax = nbrTransactionsmax;
   // this->avantages = avantages;
    avantages = {};  // modification pour utiliser une liste

}

ClientEmployee::ClientEmployee() : Client(), Employe() {
    rabaisEmploye = 0.0;
    nombreTransactions = 0;
    nbrTransactionsmax = 10;
    avantages = {};
}

void ClientEmployee::augmentationSalaire() {
    salaire=salaire*1.25;
    cout<<"salaire modifie"<<endl;
}
void ClientEmployee::afficher() {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Tel: " << tel << endl;
    cout << "CIN: " << CIN << endl;
    cout << "Email: " << email << endl;
    cout << "Rabais employe: " << rabaisEmploye * 100 << "%" << endl;
    cout << "Nombre de transactions: " << nombreTransactions << endl;
    cout << "salaire: " << salaire << endl;
    cout << "Drecrutement: " << Drecrutement << endl;

}

ostream& operator<<(ostream& os, const ClientEmployee& ce) {
    os << "Nom: " << ce.nom << endl;
    os << "Prenom: " << ce.prenom << endl;
    os << "Tel: " << ce.tel << endl;
    os << "CIN: " << ce.CIN << endl;
    os << "Email: " << ce.email << endl;
    os << "Rabais employe: " << ce.rabaisEmploye * 100 << "%" << endl;
    os << "Nombre de transactions: " << ce.nombreTransactions << endl;
    os << "nombre maximum de transactions: " << ce.nbrTransactionsmax << endl;
    cout << "salaire: " << ce.salaire << endl;
    cout << "Drecrutement: " << ce.Drecrutement << endl;

    os << "Avantages: " << endl;
    for (const auto& avantage : ce.avantages) {
        os << "- " << avantage << endl;
    }

    os << "Vehicules: " << endl;
    for (int i = 0; i < ce.getnbrVehicules(); i++) {
        os << "Vehicule NUMERO : " << i+1 << endl;
        os << *(ce.getVehicules()[i]) << endl; 
    }
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

istream& operator>>(istream& is, ClientEmployee& ce) {
    is >> static_cast<Client&>(ce);
    

    cout << "Entrez le salaire: ";
    is >> ce.salaire;
    cout << "Entrez la date de recrutement (jour mois annee): ";
    is >> ce.Drecrutement; 

    cout << "Entrez le rabais employe (en decimal, ex: 0.1 pour 10%): ";
    is >> ce.rabaisEmploye;
    cout << "Entrez le nombre de transactions: ";
    is >> ce.nombreTransactions;
    cout << "Entrez le nombre maximum de transactions: ";
    is >> ce.nbrTransactionsmax;

    ce.avantages.clear();

    string avantage;
    cout << "Entrez les avantages (ou 'fin' pour terminer):" << endl;
    while (true) {
        cin >> avantage;
        if (avantage == "fin") break;
        ce.avantages.push_back(avantage);
    }

    return is;
}

ClientEmployee::~ClientEmployee() {
   // cout << "destruction du clientemployee" << endl;
}
///////////client employee
