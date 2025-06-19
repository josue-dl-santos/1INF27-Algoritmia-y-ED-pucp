
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 9 de junio de 2025, 19:23
 */

#include <iostream>
#include <iomanip>
#include <climits>

using namespace std;



int min(int a,int b,int c){
    if(a<=b and a<=c)return a;
    if(b<=a and b<=c)return b;
    if(c<=a and c<=b)return c;
}


int MaximaDiferenciaCentro(int *arreglo,int inicio,int medio,int fin){
    int resta=0,minDerecha=INT_MAX,minIzquierda=INT_MAX,minCentro=INT_MAX;
    for(int i=medio;i>=inicio;i--){
        resta=resta+arreglo[i];
        if(resta<minIzquierda){
            minIzquierda=resta;
        }
    }
    resta=0;
    for(int i=medio+1;i<=fin;i++){
        resta=resta+arreglo[i];
        if(resta<minDerecha){
            minDerecha=resta;
        }
    }
    minCentro=minIzquierda+minDerecha;
    return min(minIzquierda,minDerecha,minCentro);
}


int MaximaDiferencia(int *elemento,int inicio,int fin){
    if(inicio==fin)return elemento[inicio];
    int medio=(inicio + fin)/2;
    int minIzquierda=MaximaDiferencia(elemento,inicio,medio);
    int minDerecha=MaximaDiferencia(elemento,medio+1,fin);
    int minCentro=MaximaDiferenciaCentro(elemento,inicio,medio,fin);
    return min(minIzquierda,minDerecha,minCentro);
}

int main(int argc, char** argv) {
//    int elemento[]={2,-3,4,-5,-7};
    int elemento[]={2,5,-6,2,3,-1,-5,6};
//    int elemento[]={-4,5,6,-4,3,-1,-5,6};
    int n=sizeof(elemento)/sizeof(elemento[0]);
    cout<<MaximaDiferencia(elemento,0,n-1);
    return 0;
}

