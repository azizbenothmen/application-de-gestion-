#include <iostream>
#include <string>
#include <vector>
#include"produit.h"
#include"mecanique.h"



pieceMecanique::pieceMecanique(){}
pieceMecanique::pieceMecanique(string referance, double prix, DATE dateFabrication, int dureeGarantie, string qualite, string categorie, string materiaux):produit(referance,prix,dateFabrication,dureeGarantie){
    this->referance=referance;
    this->prix=prix;
    this->dateFabrication=dateFabrication;
    this->dureeGarantie=dureeGarantie;
    this->qualite=qualite;
    this->categorie=categorie;
    this->materiaux=materiaux;

}
pieceMecanique::~pieceMecanique(){
    cout<<"destruction de la piece mecanique"<<endl;
}

void pieceMecanique::afficherME(){
   produit::afficherdetailsp();
    cout<<"qualite:"<<qualite<<endl;
    cout<<"categorie:"<<categorie<<endl;
    cout<<"materiaux:"<<materiaux<<endl;


}
istream& operator>>(istream& in ,pieceMecanique& pm){
    in>>static_cast<produit&>(pm);
    cout<<"donner la qualite"<<endl;
    in>>pm.qualite;
    cout<<"donner la categorie"<<endl;
    in>>pm.categorie;
    cout<<"donner le materiaux"<<endl;
    in>>pm.materiaux;
    return in;

}
ostream& operator<<(ostream& out , pieceMecanique& pm ){
    out<<static_cast<produit&>(pm);
    out<<"qualite:"<<pm.qualite<<endl;
    out<<"categorie:"<<pm.categorie<<endl;
    out<<"materiaux:"<<pm.materiaux<<endl;
    return out;

}




