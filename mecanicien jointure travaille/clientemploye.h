#ifndef CLIENTEMPLOYE_H
#define CLIENTEMPLOYE_H

#include "employe.h"
#include "client.h"

class ClientEmployee : public Employe, public Client {
    private:
        double rabaisEmploye;
        int nombreTransactions;
        vector<string> avantages;  
        int nbrTransactionsmax; 
    public:
        ClientEmployee(string nom, string prenom, int tel, int CIN, string email, int clientId, string type, DATE ddv,int nbrVehicules, vector<vehicule*> vehicules, int employeId, double salaire, DATE Drecrutement, int nbrTransactionsmax=10, vector<string> avantages={}, double rabaisEmploye=0.1, int nombreTransactions=0);
     
        void augmentationSalaire() override;
        void afficher() override;   
        void afficherAvantages();
        void ajouterAvantage(string avantage);
        
        friend ostream& operator<<(ostream& os, const ClientEmployee& ce);

        ~ClientEmployee();
};
#endif // CLIENTEMPLOYE_H