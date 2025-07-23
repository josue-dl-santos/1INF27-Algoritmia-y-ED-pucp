
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 29 de marzo de 2025, 20:10
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include <cmath>
#include "Armas.h"
#include "Guerreros.h"
#define CANTARMAS 12
#define CANTGUERRERO 3

//Version por defecto de datos hardcodeados
void rellenaArmas(Arma *armas){
    armas[0].nombre='Z';
    armas[0].poder=60;
    armas[0].tipo=3;
    armas[0].cantreq=0;
    armas[1].nombre='P';
    armas[1].poder=80;
    armas[1].tipo=1;
    armas[1].req[0]='Z';
    armas[1].cantreq=1;
    armas[2].nombre='R';
    armas[2].poder=38;
    armas[2].tipo=2;
    armas[2].cantreq=0;
    armas[3].nombre='D';
    armas[3].poder=25;
    armas[3].tipo=2;
    armas[3].cantreq=1;
    armas[3].req[0]='R';
    armas[4].nombre='E';
    armas[4].poder=49;
    armas[4].tipo=2;
    armas[4].cantreq=0;
    armas[5].nombre='F';
    armas[5].poder=57;
    armas[5].tipo=1;
    armas[5].cantreq=0;
    armas[6].nombre='G';
    armas[6].poder=68;
    armas[6].tipo=3;
    armas[6].cantreq=0;
    armas[7].nombre='H';
    armas[7].poder=35;
    armas[7].tipo=2;
    armas[7].cantreq=2;
    armas[7].req[0]='Z';
    armas[7].req[1]='E';
    armas[8].nombre='I';
    armas[8].poder=62;
    armas[8].tipo=2;
    armas[8].cantreq=1;
    armas[8].req[0]='R';
    armas[9].nombre='J';
    armas[9].poder=42;
    armas[9].tipo=2;
    armas[9].cantreq=0;
    armas[10].nombre='K';
    armas[10].poder=36;
    armas[10].tipo=1;
    armas[10].cantreq=1;
    armas[10].req[0]='Z';
    armas[11].nombre='L';
    armas[11].poder=54;
    armas[11].tipo=3;
    armas[11].cantreq=0;
}
void rellenaGuerreros(Guerrero *guerreros){
    guerreros[0].poder=120;
    guerreros[0].tipoArmas[0]=2;
    guerreros[0].cantTipos=1;
    guerreros[1].poder=160;
    guerreros[1].tipoArmas[0]=1;
    guerreros[1].tipoArmas[1]=3;
    guerreros[1].cantTipos=2;
    guerreros[2].poder=80;
    guerreros[2].tipoArmas[0]=3;
    guerreros[2].cantTipos=1;
}
void cargacromo(int *cromosoma,int numero,int estado){
    int i=0;
    for(int j=0;j<CANTARMAS;j++)
        cromosoma[j]=0;
    while(numero>0){
        cromosoma[i]=numero%estado;
        numero=numero/estado;
        i++;
    }
}
bool verificaReq(int *cromosoma,int nguerrero,Arma *armas,int narma,int k){
    //Esta función solo sirve colocando una variable cantidad de requisitos, no se puede modificar facilmente
   int cantidadver=0;
   for(int i=0;i<narma;i++){
       for(int j=0;j<CANTARMAS;j++){
           if(cromosoma[j]==nguerrero)
               if(armas[k].req[i]==armas[j].nombre){
                   cantidadver++;
                   break;
               }
       }
   }
   if(cantidadver==narma)
       return true;
   else
       return false;   
}
bool verificaCromo(Arma *armas,Guerrero *guerreros,int *cromosoma){
    for(int i=0;i<CANTARMAS;i++){
        if(cromosoma[i]!=0)
            if(!verificaReq(cromosoma,cromosoma[i],armas,armas[i].cantreq,i)){
            return false;
        }
    }
    return true;
}
bool verificaTipo(Guerrero guerreros,int *cromosoma,int n,Arma *armas){
    bool bandera;
    for(int i=0;i<3;i++){
        if(guerreros.tipoArmas[i]!=0){
            for(int j=0;j<CANTARMAS;j++)
                if(cromosoma[j]==n){
                    bandera=false;
                    for(int a=0;a<guerreros.cantTipos;a++){
                        if(armas[j].tipo==guerreros.tipoArmas[a]){
                            bandera=true;
                        }
                    }
                    if(!bandera)return false;
                }           
        }
    }
        return true;
   
}
bool verificaGuerrero(Arma *armas,Guerrero *guerreros,int *cromosoma){
    int poderes[3]{};
    for(int i=0;i<CANTARMAS;i++){
        if(cromosoma[i]==1)
            poderes[0]+=armas[i].poder;
        if(cromosoma[i]==2)
            poderes[1]+=armas[i].poder;
        if(cromosoma[i]==3)
            poderes[2]+=armas[i].poder;
    }
    for(int j=0;j<CANTGUERRERO;j++){
        if(verificaTipo(guerreros[j],cromosoma,j+1,armas)){
            if(poderes[j]<guerreros[j].poder)
                return false;
        }
        else
            return false;
                          
    }
    return true;
}
void imprimesolucion(int *cromosoma,Guerrero *guerreros,Arma *armas){
    for(int i=0;i<CANTGUERRERO;i++){
        cout<<"Guerrero "<<i+1<<endl;
        cout<<"Poder: "<<guerreros[i].poder<<endl;
        cout<<"Armas en mochila para vencerlo: ";
        for(int j=0;j<CANTARMAS;j++){
            if(cromosoma[j]==i+1)
                cout<<armas[j].nombre<<" ";
        }
        cout<<endl;
    }
}
bool calculaCombinacion(Arma *armas,Guerrero *guerreros,int combinaciones,
        int *cromosoma){
    bool bandera=false;
    int soluciones=0;
    for(int i=0;i<combinaciones;i++){
        cargacromo(cromosoma,i,CANTGUERRERO+1);
        if(verificaCromo(armas,guerreros,cromosoma))
            if(verificaGuerrero(armas,guerreros,cromosoma)){
                return true;
            }
        
    }
    return false;
}

void ingresaDatosGuerreros(Guerrero *guerreros){
    int nguerreros,poder,tipos;
    cout<<"Ingrese el número de guerreros: ";
    cin>>nguerreros;
    for(int i=0;i<nguerreros;i++){
        cout<<"Ingrese los datos del guerrero "<<i+1<<endl;
        cout<<"Ingrese el poder: ";
        cin>>poder;
        guerreros[i].poder=poder;
        cout<<"Ingrese los tipos de arma para ser vencidos (-1 para acabar)"<<
                endl;
        cout<<"Solo máximo 3 armas"<<endl;
        for(int j=0;j<3;j++){
            cout<<"Ingrese el arma "<<j+1<<" :";
            cin>>tipos;
            if(tipos==-1)break;
            guerreros[i].tipoArmas[j]=tipos;
        }
    }
}
void ingresaDatosArmas(Arma *armas){
    int narmas,poder,tipo,nreq;
    char requisito,nombre;
    cout<<"Ingrese el número de armas: ";
    cin>>narmas;
    for(int i=0;i<narmas;i++){
        cout<<"Ingrese los datos del arma "<<i+1<<endl;
        cout<<"Ingrese el nombre: ";
        cin>>nombre;
        armas[i].nombre=nombre;
        cout<<"Ingrese el poder: ";
        cin>>poder;
        armas[i].poder=poder;
        cout<<"Ingrese el tipo de arma: ";
        cin>>tipo;
        armas[i].tipo=tipo;
        cout<<"Ingrese la cantidad de requisitos del arma(solo maximo 3)"<<
                endl;
        cin>>nreq;
        armas[i].cantreq=nreq;
        for(int j=0;j<nreq;j++){
            cout<<"Ingrese el arma "<<j+1<<" : ";
            cin>>requisito;
            armas[i].req[j]=requisito;
        }
    }
}
int main(int argc, char** argv) {
    Arma armas[CANTARMAS];
    rellenaArmas(armas);
//    ingresaDatosArmas(armas);
    Guerrero guerreros[CANTGUERRERO];
    rellenaGuerreros(guerreros);
//    ingresaDatosGuerreros(guerreros);
    int combinaciones=pow(CANTGUERRERO+1,CANTARMAS)-1;
    int cromosoma[CANTARMAS]{};
    int n;
    if(calculaCombinacion(armas,guerreros,combinaciones,cromosoma)){
        cout<<"Existe una solución"<<endl;
        imprimesolucion(cromosoma,guerreros,armas);
    }
    else
        cout<<"No existe una solución"<<endl;
    return 0;
}

