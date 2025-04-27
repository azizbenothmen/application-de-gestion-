#include<iostream>
#include "electronique.h"
#include"produit.h"
#include<string>


pieceElectronique::pieceElectronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite,int Nbr):produit(referance,prix,dateFabrication,dureeGarantie){
    this->tension=tension;
    this->courant=courant;
    this->compatibilite=compatibilite;
    this->nbrP=Nbr;
    
}

pieceElectronique::pieceElectronique(const  pieceElectronique& other):produit(referance,prix,dateFabrication,dureeGarantie){
    tension=other.tension;
    courant=other.courant;
    compatibilite=other.compatibilite;
    nbrP=other.nbrP;


}

void pieceElectronique::ajouterPiece(pieceElectronique* p){
    ensemble.push_back(p);
   }
pieceElectronique::~pieceElectronique(){
}
void  pieceElectronique::afficherEnsemble(){
    for(int i=0;i<ensemble.size();i++){
        cout<<"--------affichage de la piece Electronique"<<i<<"---------------"<<endl;
        ensemble[i]->afficherPiece();
    }
}
void pieceElectronique::afficherPiece(){
    cout<<"Referance:"<<referance<<endl;
    cout<<"prix:"<<prix<<endl;
    cout<<"Date de Fabrication :"<<endl;
    dateFabrication.afficher();
    cout<<"Duree Garantie:"<<dureeGarantie<<endl;
    cout<<"Tension:"<<tension<<endl;
    cout<<"courant:"<<courant<<endl;

}