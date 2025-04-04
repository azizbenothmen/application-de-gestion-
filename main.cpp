#include <iostream>
#include <string>
#include "mecanicien.h"
using namespace std;

int main(){
    /////////partie de mohamed aziz taalouch
    vehicule* v=new vehicule("1234", "Toyota", "Corolla", DATE(1, 1, 2020), 10000);
    v->afficher();
    v->modifierKilometrage(15000);
    v->afficher();
    delete v;
    Client c1("Taalouch","Aziz",29212588,14432289,"taalouchmedaziz@gmail.com",1,"particulier",DATE(1, 1, 2020),0,vector<vehicule*>());
    c1.ajouterVehicule(new vehicule("1234", "Toyota", "Corolla", DATE(1, 1, 2020), 10000));
    c1.ajouterVehicule(new vehicule("5678", "Honda", "Civic", DATE(1, 1, 2020), 20000));
    c1.afficher();
    c1.modifier(22619908,"mohamedaziz.taalouch@enicar.ucar.tn");
    c1.afficher();
    c1.deleteVehicule("1234");
    c1.afficher();
    Client c2=c1;
    c2.afficher();
    
    /////////////partie de mohamed aziz taalouch






    return 0;

    

}