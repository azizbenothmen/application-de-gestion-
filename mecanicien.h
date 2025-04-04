#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma once

/// partie Mohamed Aziz Taalouch
class DATE{   //j'ai pas trouvé un type date en c++ donc j'ai crée une classe date
    private:
        int jour;
        int mois;
        int annee;
    public:
        DATE();
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
        void modifier(int tel, string email);
        ~Personne();
};
class vehicule{
    protected:
        string marque;
        string modele;
        DATE dateAchat;
        int kilometrage;
    public:
        string immatriculation;
        vehicule(string immatriculation, string marque, string modele, DATE dateAchat, int kilometrage);
        void afficher();
        void modifierKilometrage(int kilometrage);
        ~vehicule();
};

class Client: virtual public Personne{
    private:
        int id;
        string type;
        DATE ddv;
        int nbrVehicules;
        vector<vehicule*> vehicules;
    public:
        Client(string nom, string prenom, int tel, int CIN, string email,int id, string type, DATE ddv,int nbrVehicules, vector<vehicule*> vehicules);
        Client(const Client& other);
        void ajouterVehicule(vehicule* v);
        void deleteVehicule(string immatriculation);
        void afficher();
        void modifier(int tel, string email);
        ~Client();
};
class Employe: virtual public Personne{
    protected:
        int id;
        double salaire;
        DATE Drecrutement;
    public:
        Employe(string nom, string prenom, int tel, int CIN, string email,int id, double salaire, DATE Drecrutement);
        virtual void afficherDetails()=0;
        ~Employe();
};
class OuvrierMecanicien: public Employe{
    private:
        string specialite;
        vector<vehicule*> vehiculesEntretenus;
    public:
        OuvrierMecanicien(string nom, string prenom, int tel, int CIN, string email,int id, double salaire, DATE Drecrutement, string specialite, vector<vehicule*> vehiculesEntretenus);
        OuvrierMecanicien(const OuvrierMecanicien& other);
        void afficherDetails();
        ~OuvrierMecanicien();
};
class Gestionnaire: public Employe{
    private:
        bool accesCaisse;
        string type;
    public:
        Gestionnaire(string nom, string prenom, int tel, int CIN, string email,int id, double salaire, DATE Drecrutement, bool accesCaisse, string type);
        void afficherDetails();
        ~Gestionnaire();
};
class ClientEmployee : public Employe, public Client {
    private:
        double rabaisEmploye;
        int nombreTransactions;
        vector<string> avantages;  
        int nbrTransactionsmax; 
    public:
        ClientEmployee(string nom, string prenom, int tel, int CIN, string email, int clientId, string type, DATE ddv, vector<vehicule*> vehicules, int employeId, double salaire, DATE Drecrutement);
        ~ClientEmployee() {}
};

/*
//Partie Aziz BenOthman
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
        liquide(string referance, double prix, DATE dateFabrication, int dureeGarantie, bool flammable, float volume, string viscosite, string contenance, string type, string description);
        void afficherdetails();
        ~liquide();
};

class PieceElectronique : virtual public Produit{
   private:
        double tension;
        double courant;
        vector<string> compatibilite;
        public:
        PieceElectronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite);
        ~PieceElectronique();
};
class PieceMecanique : virtual public Produit{
    private:
        string qualité;
        string catégorie;
        string Matériaux;
    public:
        PieceMecanique(string referance, double prix, DATE dateFabrication, int dureeGarantie, string qualité, string catégorie, string Matériaux);
        ~PieceMecanique();
};
class PieceMecatronique: public PieceMecanique ,  public PieceElectronique{
    private:
        vector<string> compatibilite;
    public:
        PieceMecatronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite, string qualité, string catégorie, string Matériaux);
        ~PieceMecatronique();
};

/*
class RendezVous{
    private:
       DATE date;
       float heure;
       Client client;
       OuvrierMecanicien employee;
       string description;
    public:
        RendezVous(DATE date, float heure, Client client, OuvrierMecanicien employee, string description);
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
        Reparation(DATE date, Client client, vehicule vehicule, Facture facture, Employe employee, string description);
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
        Facture(int id, float montant, DATE date, string modepaiement, string status);
        void afficher();
        int CalculTax();
        ~Facture();
};

*/





        
        