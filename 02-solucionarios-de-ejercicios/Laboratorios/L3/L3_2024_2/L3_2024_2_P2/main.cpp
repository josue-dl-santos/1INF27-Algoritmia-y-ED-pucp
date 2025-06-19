
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 19 de junio de 2025, 16:35
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <climits>

int SubeYBaja(int *arreglo,int inicio,int fin){
    if(inicio==fin)return arreglo[inicio];
    int medio = (inicio + fin)/2;
    if(arreglo[medio]<arreglo[medio+1])
        return SubeYBaja(arreglo,medio+1,fin);
    else return SubeYBaja(arreglo,inicio,medio);
}

int CuentaCerosIzq(int *arreglo,int inicio,int fin){
    if(inicio>fin)return 0;
    if(inicio==fin){
        if(arreglo[inicio]==0)return 1;
        return 0;
    }
    int medio=(inicio + fin )/2;
    
    if(arreglo[medio]==0)
        return medio-inicio+1+CuentaCerosIzq(arreglo,medio+1,fin);
    else
        return CuentaCerosIzq(arreglo,inicio,medio);
}   

int CuentaCerosDer(int *arreglo,int inicio,int fin){
    if(inicio>fin)return 0;
    if(inicio==fin){
        if(arreglo[inicio]==0)return 1;
        return 0;
    }
    int medio=(inicio + fin )/2;
    if(arreglo[medio]==0)
        return fin-medio+1+CuentaCerosDer(arreglo,inicio,medio-1);
    
    else
        return CuentaCerosDer(arreglo,medio+1,fin);
}

int CuentaCerosDoble(int *arreglo,int inicio,int fin){
    if(arreglo[inicio]==0)return CuentaCerosIzq(arreglo,inicio,fin);
    return CuentaCerosDer(arreglo,inicio,fin);
}

int main(int argc, char** argv) {
    int muestras[][10]={{0,0,0,3,3,7,5,5,1,1},
                        {8,8,10,9,9,5,4,4,2,0},
                        {3,5,8,9,7,6,4,2,0,0},
                        {9,7,7,4,4,4,2,0,0,0},
                        {0,2,2,3,3,4,4,5,3,3},
                        {0,0,0,0,0,0,2,3,4,5},
                        {1,2,2,3,3,4,3,2,0,0},
                        {0,0,0,0,0,0,3,5,5,7},
                        {6,5,5,2,2,1,0,0,0,0},
                        {3,2,2,0,0,0,0,0,0,0}};
    int filas=sizeof(muestras)/sizeof(muestras[0]);
    int maximaPureza=INT_MIN,maximaCantidad=INT_MIN;
    int arregloMaximaCant[9]{};
    int cont=0,cantidad;
    int pureza;
    for(int i=0;i<filas;i++){
        pureza=SubeYBaja(muestras[i],0,9);
        if(pureza>maximaPureza)maximaPureza=pureza;
        cantidad=10-CuentaCerosDoble(muestras[i],0,9);
        if(cantidad==maximaCantidad){
            arregloMaximaCant[cont]=i+1;
            cont++;
        }
        if(cantidad>maximaCantidad){
            maximaCantidad=cantidad;
            cont=0;
            arregloMaximaCant[cont]=i+1;
            cont++;
        }
        
    }
    cout<<"La máxima pureza de las muestras es "<<maximaPureza<<endl;
    cout<<"Las muestras con mayor cantidad de niveles con minerales son: ";
    for(int i=0;i<cont;i++)
        cout<<arregloMaximaCant[i]<<" ";
    cout<<"con "<<maximaCantidad<<" estratos de minerales"<<endl;
    return 0;
}

