#include<iostream>
#include "date.h"
#include"produit.h"
#include<fstream>
#include<string>
using namespace std;





produit::produit(){
    compteur++;

}
produit::produit(string ref, double p, DATE dF, int dG){
    referance=ref;
    prix=p;
    dateFabrication=dF;
    dureeGarantie=dG;
    compteur++;
}
produit::~produit(){
}
void produit::afficherdetailsp(){
    cout<<"la reference est : "<<referance<<endl;
    cout<<"le prix est : "<<prix<<endl;
    cout<<"la date de fabrication est : ";
    dateFabrication.afficher();
    cout<<"la duree de garantie est : "<<dureeGarantie<<endl;
}
int produit::compteur = 0;

istream& operator>>(istream& in ,produit& p){
    cout<<"donner la reference"<<endl;
    in>>p.referance;
    cout<<"donner le prix"<<endl;
    in>>p.prix;
    cin>>p.dateFabrication;
    cout<<"donner la duree de garantie"<<endl;
    in>>p.dureeGarantie;
    return in;

}

ostream& operator<<(ostream& out , produit& p ){
    out<<"referance :"<<p.referance<<endl;
    out<<"prix:"<<p.prix<<endl;
    p.dateFabrication.afficher();
    out<<"duree de Garantie"<<p.dureeGarantie<<endl;
    return out;
}

void produit::creerFichier(const string& p) {
    try {
        ofstream file(p, ios::out | ios::trunc);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de la creation du fichier: "+p);
        }
        file.close();
    } catch (exception& e) {
        cout <<"Exception: "<<e.what()<<endl;
    }
}

void produit::enregistrerFichier(const string& p) const {
    try {
        ofstream file(p, ios::out | ios::app);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier pour l'ecriture: " + p);
        }
       file<<"La referance est :"<<referance<<endl;
       file<<"Le prix est :"<<prix<<endl;
       file<<"La Date de Fabrication est :"<<dateFabrication.getJour()<<"/"<<dateFabrication.getMois()<<"/"<<dateFabrication.getAnnee()<<endl;
       file<<"la duree de garantie est :"<<dureeGarantie<<endl;
       file.close();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}
void produit::afficherFichier(const string& p) {
    try {
        ifstream file(p, ios::in);
        if (!file.is_open()) {
            throw runtime_error("Erreur lors de l'ouverture du fichier pour la lecture: "+p);
        }
        string line;
        getline(file, line);
        cout <<"la referance est : "<< line << endl;
        getline(file, line);
        cout <<"le prix est : "<< line << endl;
        getline(file, line);
        cout <<"la date de fabrication est : "<< line << endl;
        getline(file, line);
        cout <<"la duree de garantie est : "<< line << endl;

        file.close();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

void produit::Remise(float p){
    prix=prix-(prix*p/100);
}