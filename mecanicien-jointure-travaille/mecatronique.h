#include <iostream>
#include <string>
#include <vector>
#include"produit.h"
#include"electronique.h"
#include"mecanique.h"



class pieceMecatronique:  public pieceMecanique ,  public pieceElectronique{
    private:
        vector<string> compatibilite;
        vector<pieceMecatronique*> piece;
    public:
        pieceMecatronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite,int Nbr, string qualite, string catégorie, string Matériaux);
        pieceMecatronique();
        void  Remise(float);
        void afficherMec();
        void ajouterPieceM(pieceMecatronique* );
        friend ostream& operator<<( ostream& out,pieceMecatronique& );
        friend istream& operator>>(istream& in , pieceMecatronique&);
        void afficherEnsemble();
        ~pieceMecatronique();
};

