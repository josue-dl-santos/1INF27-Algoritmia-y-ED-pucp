/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de abril de 2025, 09:16 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include <cmath>
#include <climits>
#include "Recurso_Seguridad.h"

void rellenarecurso(Recurso *recursos){
    recursos[0].nombre="Firewall";
    recursos[0].costo=50;
    recursos[0].nivelSeg=120;
    recursos[1].nombre="IDS";
    recursos[1].costo=40;
    recursos[1].nivelSeg=110;
    recursos[2].nombre="Monitoreo de Red";
    recursos[2].costo=80;
    recursos[2].nivelSeg=140;
    recursos[3].nombre="Sistema de Autenticacion";
    recursos[3].costo=70;
    recursos[3].nivelSeg=130;
    recursos[4].nombre="IPS";
    recursos[4].costo=85;
    recursos[4].nivelSeg=160;
    recursos[5].nombre="IDS Avanzado";
    recursos[5].costo=140;
    recursos[5].nivelSeg=250;
    recursos[6].nombre="Honeypot";
    recursos[6].costo=55;
    recursos[6].nivelSeg=100;
    recursos[7].nombre="Deteccion de instrusos";
    recursos[7].costo=130;
    recursos[7].nivelSeg=240;
    recursos[8].nombre="Seguridad de Correo";
    recursos[8].costo=30;
    recursos[8].nivelSeg=90;
    recursos[9].nombre="Gestion centralizada";
    recursos[9].costo=150;
    recursos[9].nivelSeg=300;
    recursos[3].requisitos[0]="Firewall";
    recursos[4].requisitos[0]="Firewall";
    recursos[5].requisitos[0]="Firewall";
    recursos[5].requisitos[1]="IDS";
    recursos[6].requisitos[0]="IDS";
    recursos[7].requisitos[0]="IDS";
    recursos[7].requisitos[1]="Monitoreo de Red";
    recursos[9].requisitos[0]="Firewall";
    recursos[9].requisitos[1]="IDS";
    recursos[9].requisitos[1]="IPS";
    recursos[0].cantReq=0;
    recursos[1].cantReq=0;
    recursos[2].cantReq=0;
    recursos[3].cantReq=1;
    recursos[4].cantReq=1;
    recursos[5].cantReq=2;
    recursos[6].cantReq=1;
    recursos[7].cantReq=2;
    recursos[8].cantReq=0;
    recursos[9].cantReq=3;
    

}
void cargabase(int numero,int base,int *cromosoma){
    int i=0;
    for (int j=0;j<6;j++)
        cromosoma[j]=0;
    while(numero>0){
        cromosoma[i]=numero%base;
        numero=numero/base;
        i++;
    }
}

bool VerificaRecursos(int *cromosoma,Recurso *recursos){
    bool bandera=true;
    for(int i=0;i<11;i++){
        if(cromosoma[i]!=0){
            for(int j=0;j<recursos[i].cantReq;j++){
                bandera=false;
                for(int k=0;k<11;k++)
                    if(cromosoma[k]!=0){
                        if(recursos[i].requisitos[j]==recursos[k].nombre)
                            bandera=true;
                }
                if(!bandera)return false;
            }
        }
    }
    return true;
}

bool VerificaPresupuesto(int *cromosoma,Recurso *recursos,int presupuesto,
        int &costo){
    int costoparcial=0;
    int costominimo=presupuesto*0.8;
    for(int i=0;i<11;i++){
        if(cromosoma[i]==1)
        costoparcial+=recursos[i].costo;
    }
    if(costoparcial>=costominimo and costoparcial<=presupuesto){
        costo=costoparcial;
        return true;
    }
    else
        return false;
}

void imprimeCromo(int *cromosoma,int combinacion,int costo){
    cout<<"Combinacion "<<combinacion<<": Recursos: ";
    for(int i=0;i<10;i++){
        if(cromosoma[i]==1)
            cout<<"R"<<i+1<<" ";
    }
//    for(int i=0;i<11;i++){
//        cout<<cromosoma[i];
//    }
    cout<<"| Costo: "<<costo<<" miles"<<endl;
}
void CalculaCombinaciones(int combinaciones,Recurso *recursos,int presupuesto){
    int cromosoma[11]{};
    int costo=0;
    cout<<"Combinaciones validas(Costo entre "<<presupuesto*0.8<<" y "<<presupuesto<<
            " miles):"<<endl;
    for(int i=0;i<combinaciones;i++){
        cargabase(i,2,cromosoma);
        if(VerificaRecursos(cromosoma,recursos))
            if(VerificaPresupuesto(cromosoma,recursos,presupuesto,costo)){
                imprimeCromo(cromosoma,i,costo);
            }
                
    }
}
void ingresoDeDatos(int &presupuesto){
    int pre;
    cout<<"Ingrese el presupuesto(en miles de soles):";
    cin>>pre;;
    presupuesto=pre;
}

int main(int argc, char** argv) {
    Recurso recursos[11];
    rellenarecurso(recursos);
    int presupuesto;
    ingresoDeDatos(presupuesto);
    int combinaciones=pow(2,11)-1;
    CalculaCombinaciones(combinaciones,recursos,presupuesto);
    return 0;
}

