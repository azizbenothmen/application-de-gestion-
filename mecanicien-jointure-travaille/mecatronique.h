#include <iostream>
#include <string>
#include <vector>
#include"produit.h"
#include"electronique.h"
#include"mecanique.h"



class pieceMecatronique: public pieceMecanique ,  public pieceElectronique{
    private:
        vector<string> compatibilite;
        vector<pieceMecatronique*> piece;
    public:
        pieceMecatronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite,int Nbr, string qualite, string catégorie, string Matériaux);
        void afficherMec();
        void ajouterPieceM(pieceMecatronique* );
        friend ostream& operator<<(const ostream& out,pieceMecatronique& );
        void afficherEnsemble();
        ~pieceMecatronique();
};