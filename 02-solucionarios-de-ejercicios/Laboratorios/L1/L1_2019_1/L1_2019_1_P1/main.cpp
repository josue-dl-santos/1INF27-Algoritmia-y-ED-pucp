/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 3 de abril de 2025, 16:07
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include <cmath>
#include <climits>
#define M 10
#define ESTADOS 2

void cargabase(int numero,int *cromosoma,int base,int cantidad){
    int i=0;
    for(int j=0;j<cantidad;j++)
        cromosoma[j]=0;
    while(numero>0){
        cromosoma[i]=numero%base;
        numero=numero/base;
        i++;
    }
}

bool verificaPeso(int *cromosoma,int articulos[][M],int peso_max,int cantidad){
    int peso=0;
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1)
            peso+=articulos[1][i];
        if(peso>peso_max)return false;
    }
    return true;
}

int calculaGanancia(int *cromosoma,int articulos[][M],int cantidad){
    int ganancia=0;
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1)
            ganancia+=articulos[2][i];
    }
    return ganancia;
}
void imprimeCombinacion(int combinacion_rpta,int *cromosoma,int ganancia,int cantidad){
    cout<<"Artículos: ";
    cargabase(combinacion_rpta,cromosoma,ESTADOS,cantidad);
    for(int i=0;i<cantidad;i++){
        if(cromosoma[i]==1)
            cout<<i+1<<" ";
    }
    cout<<setw(10)<<' '<<"Ganancia Total: "<<ganancia;
}
void buscaGananciaMaxima(int articulos[][M],int combinaciones,int cantidad,int peso){
    int cromosoma[cantidad+1]{};
    int maximo=INT_MIN;
    int combinacion_rpta,ganancia;
    for(int i=0;i<combinaciones;i++){
        cargabase(i,cromosoma,ESTADOS,cantidad);
        if(verificaPeso(cromosoma,articulos,peso,cantidad)){
            ganancia=calculaGanancia(cromosoma,articulos,cantidad);
            if(ganancia>maximo){
                maximo=ganancia;
                combinacion_rpta=i;
            }
                
        }
    }
    imprimeCombinacion(combinacion_rpta,cromosoma,maximo,cantidad);
}

int main(int argc, char** argv) {
    int articulos[3][10]={{1,2,3,4,5,6},
                          {8,2,10,10,5,5},
                          {15,20,5,10,8,5}};
    int cantidad=6;
    int peso_max=25;
    int combinaciones = pow(ESTADOS,cantidad+1)-1;
    buscaGananciaMaxima(articulos,combinaciones,cantidad,peso_max);
    
    return 0;
}

