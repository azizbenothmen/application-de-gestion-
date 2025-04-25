#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;


class DATE{   //j'ai pas trouvé un type date en c++ donc j'ai crée une classe date
    private:
        int jour;
        int mois;
        int annee;
    public:
        DATE();
        DATE(int jour, int mois, int annee);
        void afficher();
        
        int getJour() const { return jour; }
        int getMois() const { return mois; }
        int getAnnee() const { return annee; }

        friend ostream& operator<<(ostream& os, const DATE& d);
        DATE& operator=(const DATE& d); 

        //othmane
        DATE comp(DATE );
        friend istream& operator>>(istream& in,DATE&);



        ~DATE();
};

#endif // DATE_H