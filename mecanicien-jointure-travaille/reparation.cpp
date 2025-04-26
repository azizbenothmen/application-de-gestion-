#include<iostream>
#include<string.h>
#include"vehicule.h"
#include"client.h"
#include"employe.h"
#include"date.h"
#include"facture.h"
#include"reparation.h"




reparation::reparation(DATE d ,Client c,vehicule v,string des,facture f){
    date=d;
    client=c;
    vehiculeR=v;
    description=des;
    factureR=f;
}

reparation::reparation(){

}

reparation::~reparation(){}


