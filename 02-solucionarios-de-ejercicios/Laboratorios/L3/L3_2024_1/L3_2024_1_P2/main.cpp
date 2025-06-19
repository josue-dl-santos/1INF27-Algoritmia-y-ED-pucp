/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 2 de junio de 2025, 10:24
 */

#include <iostream>
#include <iomanip>

using namespace std;

int BuscaCero(int *arreglo,int inicio,int fin){
    if(inicio>fin)return -1;
    if(inicio==fin){
        if(arreglo[inicio]<=0)return inicio;
        else return -1;
    }
    int medio = (inicio + fin)/2;
    if(arreglo[medio]==0){
        if(arreglo[medio+1]<=0 ){
            return BuscaCero(arreglo,medio+1,fin);
        }
        else return medio;
    }
    else return BuscaCero(arreglo,inicio,medio-1);
    

}

int CuentaCeros(int *arreglo,int inicio,int fin){
    // 0,-1,0,-1,0,1,1,2,2,3,2,2,1,1
    // 0  1 2 3 4  5 6 7 8 9 10 11 12 13
    if(inicio>fin)return 0;
    if(inicio==fin){
        if(arreglo[inicio]>=0)return 1;
        return 0;
    }
    int medio= ( inicio + fin )/2;
    if(arreglo[medio]>=0)
        return CuentaCeros(arreglo,inicio,medio-1);
    else{
        return medio - inicio + 1 + CuentaCeros(arreglo,medio+1,fin);
    }
    
}

int BuscaMaximo(int *arreglo,int inicio,int fin){
    if(inicio==fin)return arreglo[inicio];
    int medio=(inicio + fin)/2;
    if(arreglo[medio]<arreglo[medio+1]){
        return BuscaMaximo(arreglo,medio+1,fin);
    }
    else return BuscaMaximo(arreglo,inicio,medio);
    
}

int Oppenheimer(int *elemento,int n){
    int posicion,maximo;
//    posicion=BuscaCero(elemento,0,n);
    posicion=CuentaCeros(elemento,0,n);
    maximo=BuscaMaximo(elemento,posicion,n);
}   


int main(int argc, char** argv) {
    int elemento[]={0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int n=sizeof(elemento)/sizeof(elemento[0]);
    cout<<Oppenheimer(elemento,n-1);
    return 0;
}

