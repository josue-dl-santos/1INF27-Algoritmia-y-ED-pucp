/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 20222152 - Josue De los Santos Diaz
 *
 * Created on 3 de mayo de 2025, 09:10 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funcionesLista.h"
#include "Lista.h"
#include <cstring>
/*
 * 
 */
// En el archivo para modificarlo se sigue la estructura de una linea es un elemento
//En el cual el orden es : id , nombre del elemento, el color o equipo que pertence,
//no se le coloca nada mas en el archivo
void IngresoDeDatos(Lista &lista){
    ifstream arch("Datos.txt",ios::in);
    if(!arch){
        cout<<"No se encontró el archivo"<<endl;
        exit(0);
    }
    int id;
    Elemento elemento;
    string cadena;
    while(true){
        arch>>id;
        elemento.numero=id;
        if(arch.eof())break;
        arch>>cadena;
        elemento.nombre=cadena;
        arch>>cadena;
        elemento.color=cadena;
        insertarAlFinal(lista,elemento);
    }
//    Elemento elemento;
//    elemento.numero=17;
//    elemento.nombre="Messala";
//    elemento.color="Rojo";
//    insertarAlFinal(lista,elemento);
//    
//    elemento.numero=4;
//    elemento.nombre="Ben-Hur";
//    elemento.color="Azul";
//    insertarAlFinal(lista,elemento);
//    
//    elemento.numero=12;
//    elemento.nombre="Artax";
//    elemento.color="Verde";
//    insertarAlFinal(lista,elemento);
//    
//    elemento.numero=7;
//    elemento.nombre="Drusus";
//    elemento.color="Negro";
//    insertarAlFinal(lista,elemento);
    
}
int main(int argc, char** argv) {
    Lista Benhur;
    construir(Benhur);
    IngresoDeDatos(Benhur);
    cout<<"Lista inicial:"<<endl;
    imprime(Benhur);
    ReordenarLista(Benhur);
    cout<<"Lista final"<<endl;
    imprime(Benhur);
    return 0;
}

