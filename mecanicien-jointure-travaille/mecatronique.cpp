#include "mecatronique.h"
#include"produit.h"
#include"electronique.h"
#include"mecanique.h"
#include <iostream>


pieceMecatronique::pieceMecatronique(){}

pieceMecatronique::pieceMecatronique(string referance, double prix, DATE dateFabrication, int dureeGarantie, double tension, double courant, vector<string> compatibilite,int Nbr, string qualite, string categorie, string materiaux):produit(referance,prix,dateFabrication,dureeGarantie),pieceMecanique(referance,prix,dateFabrication,dureeGarantie,qualite,categorie,materiaux),pieceElectronique(referance,prix,dateFabrication,dureeGarantie,tension,courant,compatibilite,Nbr){
    this->referance=referance;
    this->prix=prix;
    this->dateFabrication=dateFabrication;
    this->dureeGarantie=dureeGarantie;
    Setcourant(courant);
    SetTension(tension);
    this->compatibilite=compatibilite;
}

pieceMecatronique::~pieceMecatronique(){
}
void pieceMecatronique::ajouterPieceM(pieceMecatronique*p ){
    piece.push_back(p);
}

void  pieceMecatronique::afficherEnsemble(){
    for(int i=0;i<piece.size();i++){
        cout<<"--------affichage de la piece Mecatronique"<<i<<"---------------"<<endl;
        piece[i]->afficherMec();
    }
}

void pieceMecatronique::afficherMec(){
    cout<<"Referance:"<<referance<<endl;
    cout<<"prix:"<<prix<<endl;
    cout<<"Date de Fabrication :"<<endl;
    dateFabrication.afficher();
    cout<<"Duree Garantie:"<<dureeGarantie<<endl;
    cout<<"Tension:"<<gettension()<<endl;
    cout<<"courant:"<<getcourant()<<endl;
    cout<<"Catergorie"<<getcategorie()<<endl;
    cout<<"qualite"<<getqualite()<<endl;
    cout<<"Materiaux"<<getmateriaux()<<endl;


}
ostream& operator<<( ostream& out,pieceMecatronique& pmca ){
  out<<static_cast<pieceElectronique&>(pmca);
  out<<static_cast<pieceMecanique&>(pmca);

    return out ;
}
    
istream& operator >>(istream& in , pieceMecatronique& pmca){
    string pa;
    in>>static_cast<pieceElectronique&>(pmca);
    cout<<" donner la qualite"<<endl;
    in>>pa;
    pmca.SetQualite(pa);
    cout<<"donner la categorie"<<endl;
    in>>pa;
    pmca.SetCategorie(pa);
    cout<<"donner les materiaux"<<endl;
    in>>pa;
    pmca.SetMat(pa);
    return in ;
}
void pieceMecatronique::Remise(float p){
    prix=prix-(prix*p/100);
}
