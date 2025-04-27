#include <iostream>
#include <string>
#include <vector>
#include"produit.h"
using namespace std;
#pragma once



class pieceElectronique : virtual public produit{
    private:
         double tension;
         double courant;
         vector<string> compatibilite;
         int nbrP;
         vector<pieceElectronique*> ensemble;
         public:
         pieceElectronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite,int Nbr);
         pieceElectronique(const  pieceElectronique& other);
         void ajouterPiece(pieceElectronique*);
         void afficherPiece();
         void afficherEnsemble();
         double gettension(){return tension;};
         double getcourant(){return courant;};
         ~pieceElectronique();
 };