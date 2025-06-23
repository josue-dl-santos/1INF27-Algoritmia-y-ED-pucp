/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 21 de junio de 2025, 09:04 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int VentasMaxima(int *arreglo,int inicio,int fin,int &dia){
    // 20,50,80,120,200,150,90
    // 0   1 2   3 4    5   6
    if(inicio==fin){
        dia=inicio;
        return arreglo[inicio];
    }
    int medio=(inicio + fin)/2;
    if(arreglo[medio]<arreglo[medio+1])
        return VentasMaxima(arreglo,medio+1,fin,dia);
    return VentasMaxima(arreglo,inicio,medio-1,dia);
        
}

int VentasMinima(int *arreglo,int inicio,int fin,int &dia,int maximo){
    //Asumiendo que está ordenando crecientemente
    //Busqueda binaria
    // 10,20,30,80,150,220,250
    //  0 1  2  3   4   5   6  
    if(inicio==fin){
        dia=inicio;
        return arreglo[inicio];
    }
    int medio=(inicio + fin)/2;
//    if(arreglo[medio]<arreglo[fin]){
        if(arreglo[medio]<maximo){
            return VentasMinima(arreglo,medio+1,fin,dia,maximo);
        }
        else
            return VentasMinima(arreglo,inicio,medio,dia,maximo);
//    }
//    else{
//        if(arreglo[medio]>=maximo){
//            return VentasMinima(arreglo,medio,fin,dia,maximo);
//        }
//        else
//            return VentasMinima(arreglo,inicio,medio-1,dia,maximo);
//    }
        
}

int main(int argc, char** argv) {
//    int ventas_original[]={20,50,80,120,200,150,90};
    int ventas_original[]={50,80,120,160,210,180,140};
    int noriginal=sizeof(ventas_original)/sizeof(ventas_original[0]);
//    int ventas_nueva[]={10,20,30,80,150,220,250};
    int ventas_nueva[]={300,380,450,570,620,740,860};
    int nnueva=sizeof(ventas_nueva)/sizeof(ventas_nueva[0]);
    int dia;
    //Se busca el valor maximo y se busca tambien el día
    int maximooriginal=VentasMaxima(ventas_original,0,noriginal-1,dia);
    cout <<"Pico de ventas_original: dia "<<dia<<" - valor "<<maximooriginal<<endl;
    int primerdia;
    //Se busca el valor minimo y se busca tambien el dia
    int primeraventa=VentasMinima(ventas_nueva,0,noriginal-1,primerdia,maximooriginal);
    cout <<"Primer dia en ventas_nueva que supera el pico: dia "<<primerdia<<
            " - valor "<<primeraventa;
    return 0;
}

