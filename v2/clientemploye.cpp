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
    this->avantages = avantages;
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
    cout << "salaire: " << ce.salaire << endl;
    cout << "Drecrutement: " << ce.Drecrutement << endl;
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
   // cout << "destruction du clientemployee" << endl;
}
///////////client employee
