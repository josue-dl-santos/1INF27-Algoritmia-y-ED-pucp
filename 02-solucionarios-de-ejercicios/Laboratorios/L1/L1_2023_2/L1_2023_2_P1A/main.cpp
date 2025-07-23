
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 30 de marzo de 2025, 19:45
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include <cmath>
#include <climits>
#define CANTNAVIO 1
#define CANTCONTENEDORES 16

void cargacromo(int numero,int *cromosoma,int base){
    int i=0;
    for(int j=0;j<CANTCONTENEDORES;j++)
        cromosoma[j]=0;
    while(numero>0){
        cromosoma[i]=numero%base;
        numero=numero/base;
        i++;
    }
    
}
void calculavalores(int *cromosoma,int *pesos,int *valores,int &peso,
        int &valorBruto){
    int apeso=0,bvalor=0;
    
    for(int i=0;i<CANTCONTENEDORES;i++){
        if(cromosoma[i]==1){
            apeso+=pesos[i];
            bvalor+=valores[i];
        }
            
    }
    peso=apeso;
    valorBruto=bvalor;
}
void imprimirCombinacion(int combinacion,int *cromosoma,int *pesos,
        int *valores,int maximo){
    cout<<"Valor Máximo: "<<maximo<<" (en miles de soles)"<<endl;
    cout<<"Pesos(Toneladas)"<<endl;
    cargacromo(combinacion,cromosoma,CANTNAVIO+1);
    for(int i=0;i<CANTCONTENEDORES;i++){
        if(i%4==0 and i>0)
                cout<<endl;
        if(cromosoma[i]==1){
            cout<<setw(2)<<pesos[i]<<" ";
            
        }
        else{
            cout<<setw(2)<<0<<" ";
        }
           
    }
    cout<<endl;
    cout<<endl;
    cout<<"VALORES(Miles de soles)"<<endl;
    for(int i=0;i<CANTCONTENEDORES;i++){
        if(i%4==0 and i>0)
                cout<<endl;
        if(cromosoma[i]==1)
            cout<<setw(2)<<valores[i]<<" ";
        else
            cout<<setw(2)<<0<<" ";
        
           
    }
}
void CalculaCombiOptima(int *pesos,int *valores,int combinaciones,int pesoMax){
    int maximo=INT_MIN;
    int combinacion=0;
    int peso=0,valorBruto=0;
    int cromosoma[CANTCONTENEDORES]{};
    for(int i=0;i<combinaciones;i++){
        cargacromo(i,cromosoma,CANTNAVIO+1);
        calculavalores(cromosoma,pesos,valores,peso,valorBruto);
        if(peso<=pesoMax)
            if(valorBruto>=maximo){
                combinacion=i;
                maximo=valorBruto;
            }
    }
    imprimirCombinacion(combinacion,cromosoma,pesos,valores,maximo);
}
    
int main(int argc, char** argv) {
    int pesos[16]={20,20,20,20,10,30,10,30,10,10,10,10,15,15,15,15};
    int valores[16]={10,10,10,50,80,10,10,20,20,20,20,20,50,50,50,50};
    int combinaciones=pow(CANTNAVIO+1,CANTCONTENEDORES)-1;
    int pesoMaximo=100;
    CalculaCombiOptima(pesos,valores,combinaciones,pesoMaximo);
    return 0;
}

