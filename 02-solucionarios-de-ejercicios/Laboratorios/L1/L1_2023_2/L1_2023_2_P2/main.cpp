
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 3 de abril de 2025, 16:49
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include <cmath>
#include <climits>
#include "Controles.h"
#define ESTADOS 2
/*
 * 
 */
void rellenaControles(Controles *controles,int cantidad){
    for(int i=0;i<cantidad;i++)
        controles[i].id=i+1;
    controles[0].inversion=32000;
    controles[1].inversion=8000;
    controles[2].inversion=40000;
    controles[3].inversion=40000;
    controles[4].inversion=20000;
    controles[5].inversion=4000;
    controles[6].inversion=16000;
    controles[7].inversion=16000;
    controles[2].requisitos[0]=1;
    controles[2].requisitos[1]=2;
    controles[5].requisitos[0]=2;
    controles[6].requisitos[0]=6;
    controles[7].requisitos[0]=6;
    controles[0].beneficio=60000;
    controles[1].beneficio=32000;
    controles[2].beneficio=120000;
    controles[3].beneficio=60000;
    controles[4].beneficio=32000;
    controles[5].beneficio=20000;
    controles[6].beneficio=48000;
    controles[7].beneficio=60000;
            
};
void cargabase(int *cromosoma,int numero,int base,int cantidad){
    int i=0;
    for(int j=0;j<cantidad;j++)
        cromosoma[j]=0;
    while(numero>0){
        cromosoma[i]=numero%base;
        numero=numero/base;
        i++;
    }
}

bool verificaRequisito(int *cromosoma,Controles *controles,int cantidad){
    bool bandera;
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1){
            bandera=false;
            for(int j=0;j<3;j++){
                if(controles[i].requisitos[j]!=0){
                    for(int k=0;k<cantidad;k++){
//                        if(cromosoma[k]==1)
                            if(controles[i].requisitos[j]==controles[k].id)
                                bandera=true;
                    }
                    if(!bandera)
                        return false;
                }
            }
        }
    }
    return true;
}
int calculaPresupuesto(int *cromosoma,Controles *controles,int cantidad){
    int total=0;
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1){
            total+=controles[i].inversion;
        }
    }
    return total;
}
int calculaPresupuestoMod(int *cromosoma,Controles *controles,int cantidad,
        int &beneficio){
    int total=0;
    int benef=0;
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1){
            total+=controles[i].inversion;
            benef+=controles[i].beneficio;
        }
    }
    beneficio=benef;
    return total;
}
void imprimecromosoma(int *cromosoma,int cantidad){
    cout<<"Una solucion: ";
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}
void imprimecromosoma(int *cromosoma,int cantidad,int beneficio){
    cout<<"Una solucion: ";
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1){
            cout<<i+1<<" ";
        }
    }
    cout<<"  Beneficio "<<beneficio<<endl;
}
void imprimeMaximo(int *cromosoma,int cantidad,int beneficio,int combinacion_maxima){
    cargabase(cromosoma,combinacion_maxima,ESTADOS,cantidad);
    cout<<"Solución Máxima:"<<endl;
    imprimecromosoma(cromosoma,cantidad,beneficio);
}
void mejorSoluConPresupuesto(Controles *controles,int combinaciones,
        int presupuesto,int cantidad){
    int cromosoma[cantidad]{};
    for(int i=0;i<combinaciones;i++){
        cargabase(cromosoma,i,ESTADOS,cantidad);
        if(verificaRequisito(cromosoma,controles,cantidad))
            if(calculaPresupuesto(cromosoma,controles,cantidad)==presupuesto)
                imprimecromosoma(cromosoma,cantidad);
    }
}
void mejorSoluConPresupuestoMod(Controles *controles,int combinaciones,
        int presupuesto,int cantidad){
    int cromosoma[cantidad]{};
    int maximo=INT_MIN;
    int combinacion_maxima;
    int beneficio=0;
    for(int i=0;i<combinaciones;i++){
        cargabase(cromosoma,i,ESTADOS,cantidad);
        if(verificaRequisito(cromosoma,controles,cantidad))
            if(calculaPresupuestoMod(cromosoma,controles,cantidad,beneficio)==presupuesto){
                imprimecromosoma(cromosoma,cantidad,beneficio);
                if(beneficio>maximo){
                    maximo=beneficio;
                    combinacion_maxima=i;
                }
            }
    }
    imprimeMaximo(cromosoma,cantidad,beneficio,combinacion_maxima);
}
int main(int argc, char** argv) {
    Controles controles[9];
    int n=8;
    int p=100000;
    rellenaControles(controles,n);
    int combinaciones=pow(ESTADOS,n+1)-1;
    mejorSoluConPresupuesto(controles,combinaciones,p,n);
    cout<<"Solución con beneficios"<<endl;
    mejorSoluConPresupuestoMod(controles,combinaciones,p,n);
    return 0;
}

