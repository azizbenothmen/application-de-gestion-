#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma once


class DATE{
    private:
        int jour;
        int mois;
        int annee;
    public:
        DATE(int jour, int mois, int annee);
        void afficher();
        ~DATE();
};
class Personne{
    protected:
        string nom;
        string prenom;
        int tel;
        int CIN;
        string email;
    public:
        Personne(string nom, string prenom, int tel, int CIN, string email);
        virtual void afficher()=0;
        ~Personne();
};

class Client: public Personne{
    private:
        int id;
        string type;
        DATE ddv;
        vector<vehicule*> vehicules;
    public:
        Client(int id, string type, DATE ddv, vector<vehicule*> vehicules):Personne(nom, prenom, tel, CIN, email){};
        void ajouterVehicule(vehicule* v);
        void deleteVehicule(vehicule *v);
        ~Client();
};
class Employe: public Personne{
    protected:
        int id;
        double salaire;
        DATE Drecrutement;
    public:
        Employe(int id, double salaire, DATE Drecrutement):Personne(nom, prenom, tel, CIN, email){};
        virtual void afficher()=0;
        ~Employe();
};
class OuvrierMecanicien: public Employe{
    private:
        string specialite;
        vector<vehicule*> vehiculesEntretenus;
    public:
        OuvrierMecanicien(int id, double salaire, DATE Drecrutement, string specialite, vector<vehicule*> vehiculesEntretenus)
        : Employe(id, salaire, Drecrutement), specialite(specialite), vehiculesEntretenus(vehiculesEntretenus) {};
        void afficher();
        ~OuvrierMecanicien();
};
class Gestionnaire: public Employe{
    private:
        bool accesCaisse;
        string type;
    public:
        Gestionnaire(int id, double salaire, DATE Drecrutement, bool accesCaisse, string type)
        : Employe(id, salaire, Drecrutement), accesCaisse(accesCaisse), type(type) {};
        void afficher();
        ~Gestionnaire();
};
class ClientEmployee : public Employe, public Client {
    private:
        double rabaisEmploye;
        int nombreTransactions;
        vector<string> avantages;  
        int nbrTransactionsmax; 
    public:
        ClientEmployee(int id, double salaire, DATE Drecrutement, string nom, string prenom, int tel, int CIN, string email, int clientId, string type, DATE ddv, vector<vehicule*> vehicules, double rabaisEmploye, int nombreTransactions, vector<string> avantages, int nbrTransactionsmax)
            : Employe(id, salaire, Drecrutement), Client(clientId, type, ddv, vehicules), rabaisEmploye(rabaisEmploye), nombreTransactions(nombreTransactions), avantages(avantages), nbrTransactionsmax(nbrTransactionsmax) {}
        ~ClientEmployee() {}
};
class vehicule{
    protected:
        string immatriculation;
        string marque;
        string modele;
        DATE dateAchat;
        int kilometrage;
    public:
        vehicule(string immatriculation, string marque, string modele, DATE dateAchat, int kilometrage);
        void afficher();
        void modifierKilometrage(int kilometrage);
        ~vehicule();
};

class Produit{
    protected:
        string referance;
        double prix;
        DATE dateFabrication;
        int dureeGarantie;
    public:
        Produit(string referance, double prix, DATE dateFabrication, int dureeGarantie);
        ~Produit();
};

class liquide : public Produit{
    private:
        bool flammable;
        float volume;
        string viscosite;
        string contenance;
        string type;
        string description;
    public:
       liquide(string referance, double prix, DATE dateFabrication, int dureeGarantie, bool flammable, float volume, string viscosite, string contenance, string type, string description)
        : Produit(referance, prix, dateFabrication, dureeGarantie), flammable(flammable), volume(volume), viscosite(viscosite), contenance(contenance), type(type), description(description) {};
        void afficherdetails();
        ~liquide();
};

class PieceElectronique : public Produit{
   private:
        double tension;
        double courant;
        vector<string> compatibilite;
    
        public:
        PieceElectronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite)
        : Produit(referance, prix, dateFabrication, dureeGarantie), tension(tension), courant(courant), compatibilite(compatibilite) {};
        ~PieceElectronique();
};
class PieceMecanique : public Produit{
    private:
        string qualité;
        string catégorie;
        string Matériaux;
    public:
        PieceMecanique(string referance, double prix, DATE dateFabrication, int dureeGarantie, string qualité, string catégorie, string Matériaux)
        : Produit(referance, prix, dateFabrication, dureeGarantie), qualité(qualité), catégorie(catégorie), Matériaux(Matériaux) {};
        ~PieceMecanique();
}
class PieceMecatronique: public PieceMecanique ,  public PieceElectronique{
    private:
        vector<string> compatibilite;
    public:
        PieceMecatronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite, string qualité, string catégorie, string Matériaux)
        :PieceElectronique(referance, prix, dateFabrication, dureeGarantie, tension, courant, compatibilite), PieceMecanique(referance, prix, dateFabrication, dureeGarantie, qualité, catégorie, Matériaux) {};
        ~PieceMecatronique();
};


class RendezVous{
    private:
       DATE date;
       float heure;
       Client client;
       OuvrierMecanicien employee;
       string description;
    public:
        RendezVous(DATE date, float heure, Client client, OuvrierMecanicien employee, string description)
        : date(date), heure(heure), client(client), employee(employee), description(description) {};
        void modifierRV();
        ~RendezVous();


};

class Reparation{
    private:
        DATE date;
        Client client;
        vehicule vehicule;
        Facture facture;
        Employe employee;
        string description;
    public:
        Reparation(DATE date, Client client, vehicule vehicule, Facture facture, Employe employee, string description)
        : date(date), client(client), vehicule(vehicule), facture(facture), employee(employee), description(description) {};
        ~Reparation();
      
};

class Facture{
    private:
        int id;
        float montant;
        DATE date;
        string modepaiement;
        string status;
    public:
        Facture(int id, float montant, DATE date, string modepaiement, string status)
        : id(id), montant(montant), date(date), modepaiement(modepaiement), status(status) {};
        void afficher();
        int CalculTax();
        void GenererFacture();
        ~Facture();
};







        
        