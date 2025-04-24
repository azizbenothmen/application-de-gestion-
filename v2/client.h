#ifndef CLIENT_H
#define CLIENT_H

#include "personne.h"
#include "vehicule.h"
#include "date.h"

class Client: virtual public Personne{
    private:
        int id;
        string type;
        DATE ddv;
        int nbrVehicules;
        vector<vehicule*> vehicules;
    public:
        Client(string nom, string prenom, int tel, int CIN, string email,int id, string type, DATE ddv,int nbrVehicules, vector<vehicule*> vehicules);
        Client();
        Client(const Client& other);
        Client operator+(const Client& other); 
        void ajouterVehicule(vehicule* v);
        void deleteVehicule(string immatriculation);
        friend ostream& operator<<(ostream& os, const Client& c);
        Client& operator=(const Client& other);  
        friend istream& operator>>(istream& is, Client& c);
        void afficher();
        void modifier(int tel, string email);
        ~Client();
        // File manipulation functions
        void creerFichier(const string& f);
        void enregistrer(const string& f) const;
        void recuperer(const string& filename, Client& c);
};
#endif // CLIENT_H