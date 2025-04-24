#include <iostream>
#include <string>
#include "mecanicien.h"
using namespace std;

int main(){
    /////////partie de mohamed aziz taalouch
    vehicule* v=new vehicule("Toyota", "Corolla", DATE(1, 1, 2020), 10000,"1234");
    //v->afficher();
    cout << *v << endl;
    v->modifierKilometrage(15000);
    //v->afficher();
    cout << *v << endl;
    delete v;
    Client c1("Taalouch","Aziz",29212588,14432289,"taalouchmedaziz@gmail.com",1,"particulier",DATE(1, 1, 2020),0,vector<vehicule*>());
    c1.ajouterVehicule(new vehicule("Toyota", "Corolla", DATE(1, 1, 2020), 10000,"1234"));
    c1.ajouterVehicule(new vehicule( "Honda", "Civic", DATE(1, 1, 2020), 20000,"5678"));
   // c1.afficher();
    cout <<"c1:"<<c1<<endl;
    c1.modifier(22619908,"mohamedaziz.taalouch@enicar.ucar.tn");
   // c1.afficher();
   cout <<"c1:"<<c1<<endl;
    c1.deleteVehicule("1234");
   // c1.afficher();
    cout <<"c1:"<<c1<<endl;

    Client c2=c1;
   // c2.afficher();
    cout << "c2:" << c2 << endl;
    //a verifier 
    cout<<"-----------------------------------------------------------------"<<endl;
    OuvrierMecanicien om("Ahmed", "Tria", 22666777, 14425568, "email@example.com", 33, 1533.5, DATE(1, 1, 2020), "Mecanique", vector<vehicule*>());    
    //om.afficher();
    cout<<"om:"<<om<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    Gestionnaire g("zoro", "tria", 22666777, 14425568, "email", 8, 1533.5, DATE(1, 1, 2020), true, "chef personnel");
   // g.afficher();
    cout<<"g:"<<g<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    ClientEmployee ce("ahmed", "tria", 22666777, 14425568, "email", 8, "particulier", DATE(1, 1, 2020), vector<vehicule*>(), 8, 1533.5, DATE(1, 1, 2020));
   // ce.afficher();
    cout<<"ce:"<<ce<<endl;
    ce.ajouterAvantage("Lavage Voiture Gratuit");
    ce.afficherAvantages();
    //a verifier
    cout << "-----------------------------------------------------------------" << endl;
    cout << "TEST DE LA SURCHARGE D'OPERATEUR +" << endl;

    Client c3("Dupont", "Jean", 12345678, 98765432, "jean.dupont@email.com", 2, "particulier", DATE(1, 1, 2021), 0, vector<vehicule*>());
    c3.ajouterVehicule(new vehicule("Renault", "Clio", DATE(1, 1, 2021), 5000,"4321"));
    
    Client c4 = c1 + c3; // Fusion des clients c1 et c3
    cout << "Client fusionne:" << endl;
    //c4.afficher();
    cout << c4 << endl;
    cout << "*************************************************************************************" << endl;
    //om.afficher();
    cout<<"om:"<<om<<endl;
    om.augmentationSalaire();
   // om.afficher();
    cout<<"om:"<<om<<endl;
    cout << "*************************************************************************************" << endl;

    DATE date1(1, 1, 2020);
    DATE date2;
    date2 = date1; // Utilisation de l'opérateur =
    cout << " " << date2 << endl;
    vehicule v1("Toyota", "Corolla", DATE(1, 1, 2020), 10000, "1234");
    vehicule v2;
    v2 = v1; // Utilisation de l'opérateur =
    cout << " " << v2 << endl;
    Client cc("Dupont", "Jean", 12345678, 98765432, "jean.dupont@email.com", 2, "particulier", DATE(1, 1, 2021), 2, vector<vehicule*>{
        new vehicule("Renault", "Clio", DATE(1, 1, 2021), 5000, "4321"),
        new vehicule("Peugeot", "208", DATE(1, 6, 2021), 8000, "5678")
    });

    c1 = cc;  // Utilisation de l'opérateur =
    cout << "Client après affectation:" <<c1 << endl;
    cout << "----------------------------------------------------------" << endl;

    // Test de l'opérateur >> pour Client
    Client c;
    cin >> c;
    cout << "Client saisie: " << c << endl;
    /////////////partie de mohamed aziz taalouch






    return 0;

    

}