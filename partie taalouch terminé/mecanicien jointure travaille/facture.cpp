#include<string>
#include<iostream>
#include "facture.h"
#include "date.h"
using namespace std;


facture::facture(){}

facture::facture(string id,float montant,DATE d1,string modepaiement,string status){
    this->id=id;
    this->montant=montant;
    this->date=d1;
    this->modepaiement=modepaiement;
    this->status=status;
}
facture::~facture(){
}
void facture::afficherfacture(){
    cout<<"id="<<id<<endl;
    cout<<"montant="<<montant<<endl;
    cout<<"date=";
    date.afficher();
    cout<<"mode de paiement="<<modepaiement<<endl;
    cout<<"status="<<status<<endl;
}

float facture::calculTax(int taux){
    int tax;
    tax= (montant)*(taux/100);
    return tax;


}
istream& operator>>(istream& in ,facture& f ){
    cout<<"donner l'id"<<endl;
    in>>f.id;
    cout<<"donner le montant"<<endl;
    in>>f.montant;
    cout<<"donner le mode de paiement"<<endl;
    in>>f.modepaiement;
    cout<<"donner le status"<<endl;
    in>>f.status;
    cout<<"donner la date"<<endl;
    in>>f.date;
    return in;
}
ostream& operator<<(ostream& out,facture& f ){
    out<<"id="<<f.id<<endl;
    out<<"montant="<<f.montant<<endl;
    out<<"date=";
    f.date.afficher();
    out<<"mode de paiement="<<f.modepaiement<<endl;
    out<<"status="<<f.status<<endl;
    return out;
}
facture facture::operator+(const facture& f){
    string id1,mode,statue;
    float montant1;
    DATE d;
    cout<<f.id<<endl;;
    montant1=montant+f.montant;
    id1=id+"&"+f.id;
    mode=modepaiement+"/"+f.modepaiement;
    statue=status+"/"+f.status;
    d=date.comp(f.date);
    return facture(id1,montant1,d,mode,statue);
}