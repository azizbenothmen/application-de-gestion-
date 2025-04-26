#include<iostream>
#include<string.h>
#include"vehicule.h"
#include"client.h"
#include"employe.h"
#include"date.h"
#include"facture.h"
using namespace std;
#pragma once




class reparation{
    private:
       DATE date;
       Client client;
       vehicule vehiculeR;
       string description;
       facture factureR;
       //Employe employee;
    public:
       reparation(DATE ,Client,vehicule,string,facture );
       reparation();
       ~reparation();
       friend istream& operator>>(istream& in,reparation);
       friend ostream& operator<<(ostream& out,reparation);


};