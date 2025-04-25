#include "employe.h"

class Gestionnaire: public Employe{
    private:
        bool accesCaisse;
        string type;
    public:
        Gestionnaire(string nom, string prenom, int tel, int CIN, string email,int id, double salaire, DATE Drecrutement, bool accesCaisse, string type);
      
        void augmentationSalaire() override;
        void afficher() override;   
        
        friend ostream& operator<<(ostream& os, const Gestionnaire& g);

        ~Gestionnaire();
};