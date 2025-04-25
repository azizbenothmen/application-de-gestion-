#include "employe.h"
#include "personne.h"
#include "vehicule.h"

class OuvrierMecanicien: public Employe{
    private:
        string specialite;
        vector<vehicule*> vehiculesEntretenus;
    public:
        OuvrierMecanicien(string nom, string prenom, int tel, int CIN, string email,int id, double salaire, DATE Drecrutement, string specialite, vector<vehicule*> vehiculesEntretenus);
        OuvrierMecanicien(const OuvrierMecanicien& other);

        void augmentationSalaire() override;
        void afficher() override;   
        
        friend ostream& operator<<(ostream& os, const OuvrierMecanicien& om);

        ~OuvrierMecanicien();
};