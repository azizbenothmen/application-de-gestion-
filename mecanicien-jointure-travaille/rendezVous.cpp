#include<iostream>
#include<string.h>
#include"client.h"
#include"employe.h"
#include"ouvriermecanicien.h"
#include"date.h"
#include"rendezVous.h"





rendezVous::rendezVous(DATE d,float h,Client c,OuvrierMecanicien e,string des){
    date=d;
    heure=h;
    client=c;
    employe=e;
    description=des;
}
void rendezVous::modifierRV(){
    cout<<"donner la nouvelle date"<<endl;
    cin>>date;
    cout<<"donner la nouvelle heure"<<endl;
    cin>>heure;
    cout<<"donner la nouvelle description"<<endl;
    cin>>description;
}
rendezVous::~rendezVous(){
    
}