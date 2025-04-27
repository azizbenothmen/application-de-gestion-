#include "employe.h"
#include "personne.h"
#include "vehicule.h"

class OuvrierMecanicien: public Employe{
    private:
        string specialite;
        vector<vehicule*> vehiculesEntretenus;
    public:
        OuvrierMecanicien(string nom, string prenom, int tel, int CIN, string email,int id, double salaire, DATE Drecrutement, string specialite, vector<vehicule*> vehiculesEntretenus);
        OuvrierMecanicien(); 
        OuvrierMecanicien(const OuvrierMecanicien& other);

        void augmentationSalaire();
        void afficher();   
        
        friend ostream& operator<<(ostream& os, const OuvrierMecanicien& om);
        friend istream& operator>>(istream& is, OuvrierMecanicien& om);

        ~OuvrierMecanicien();
};