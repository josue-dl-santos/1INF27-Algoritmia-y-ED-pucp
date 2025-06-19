
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 10 de junio de 2025, 16:17
 */

#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int max(int a,int b,int c){
    if(a>=b and a>=c)return a;
    if(b>=c and b>=a)return b;
    if(c>=b and c>=a)return c;
}
int CantidadMaxCentro(int *arreglo,int inicio,int medio,int fin,int max){
    int cuentaIzquieda=0,cuentaDerecha=0;
    for(int i=medio;i>=inicio;i--){
        if(arreglo[i]==max){
            cuentaIzquieda++;
        }
        else 
            break;
    }
    for(int i=medio+1;i<=fin;i++){
        if(arreglo[i]==max){
            cuentaDerecha++;
        }
        else 
            break;
    }
    if(arreglo[medio]==max and arreglo[medio+1]==max)return cuentaIzquieda+cuentaDerecha;
    if(cuentaDerecha>=cuentaIzquieda)return cuentaDerecha;
    else return cuentaIzquieda;
            
}

int cantidadMaximaHoras(int *arreglo,int inicio,int fin,int maximo){
    if(inicio==fin){
        if(arreglo[inicio]==maximo)return 1;
        else return 0;
    }
        
    int medio=(inicio + fin)/2;
    int izquierda,derecha,centro;
    izquierda=cantidadMaximaHoras(arreglo,inicio,medio,maximo);
    derecha=cantidadMaximaHoras(arreglo,medio+1,fin,maximo);
    centro=CantidadMaxCentro(arreglo,inicio,medio,fin,maximo);
    return max(izquierda,derecha,centro);
}
int ValorMaximo(int *arreglo,int cantidad){
    int max=INT_MIN;
    for(int i=0;i<=cantidad;i++)
        if(arreglo[i]>max)max=arreglo[i];
    return max;
}

int cantidadMaximaHorasPico(int *arreglo,int cantidad){
    int max;
    max=ValorMaximo(arreglo,cantidad);
    return cantidadMaximaHoras(arreglo,0,cantidad,max);
    
}

int main(int argc, char** argv) {
    int empresas[10][10]={{15,12,10,17,15,18,18,18,12,16},
                          {14,17,17,17,17,12,14,14,12,12},
                          {16,18,20,20,15,18,16,18,18,16}
    };
    int columnas=10;
    int cantidad;
    int Minimo=INT_MAX,empresa;
    int filas=3;
    for(int i=0;i<filas;i++){
        cantidad=cantidadMaximaHorasPico(empresas[i],columnas-1);
        if(cantidad<=Minimo){
            Minimo=cantidad;
            empresa=i;
        }
    }
    cout<<"La empresa elegida es "<<empresa+1<<" con un cantidad de horas de "<<Minimo;
    
    return 0;
}

