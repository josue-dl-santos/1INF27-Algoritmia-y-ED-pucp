/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 21 de junio de 2025, 09:15 AM
 */

#include <iostream>
#include <iomanip>

using namespace std;

void merge(char *arreglo,int inicio,int medio,int fin,int n){
    int aux[n+1]{};
    int p,q,m;
    for(p=inicio,q=medio+1,m=inicio;p<=medio and q<=fin;m++){
        if(arreglo[p]<arreglo[q]){
            aux[m]=arreglo[p];
            p++;
        }
        else{
            aux[m]=arreglo[q];
            q++;
        }
    }
    while(p<=medio)aux[m++]=arreglo[p++];
    while(q<=fin)aux[m++]=arreglo[q++];
    
    for(int i=inicio;i<=fin;i++)arreglo[i]=aux[i];
}

void mergesort(char *arreglo,int inicio,int fin,int n){
    if(inicio==fin)return;
    int medio=(inicio + fin)/2;
    mergesort(arreglo,inicio,medio,n);
    mergesort(arreglo,medio+1,fin,n);
    merge(arreglo,inicio,medio,fin,n);
}

int CuentaChar(char *lotes,int inicio,int fin,char valor){
    // ' ' ' ' C C F F F
    if(inicio>fin)return 0;
    if(inicio==fin){
        if(lotes[inicio]==valor)return 1;
        return 0;
    }
    int medio = (inicio + fin)/2;
    
    if(lotes[medio]==valor){
        return medio-inicio+1+CuentaChar(lotes,medio+1,fin,valor);
    }
    else
        return CuentaChar(lotes,inicio,medio,valor);
    
}

void funcionClasificatorio(char lotes[6][8],int m,int n,double p){
    int inicio,correctos,total;
    double porcentaje;
    //Esto le añade una complejidad x m 
    for(int i=0;i<m;i++){
//        for(int j=0;j<8;j++)
//            cout<<lotes[i][j]<<" ";
//        cout<<endl;
        //Primero se ordena con el objetivo de contar el char que desea
        //Complejidad n*log(n)
        mergesort(lotes[i],0,n-1,n);
//        for(int j=0;j<8;j++)
//            cout<<lotes[i][j]<<" ";
//        cout<<endl;
        //Complejidad O(log n)
        inicio=CuentaChar(lotes[i],0,n-1,' ');
        //Complejidad O(log n)
        correctos=CuentaChar(lotes[i],inicio,n-1,'C');
        
        total=n-inicio;
        
        porcentaje=(double)correctos/total;
        
        cout<<i+1;
        if(porcentaje>=p)
            cout<<" Aprobado"<<endl;
        else
            cout<<" Rechazado"<<endl;
                   
    }
}

int main(int argc, char** argv) {
    char lotes[6][8]={{'F','F','F','C','C','F',' ',' '},
                    {'C','F','C','C','C','F','C','F'},
                    {'F','C','C','C','C','C','C','C'},
                    {'C','C','C','C','C','F','C',' '},
                    {'C','F','F','F','F','C',' ',' '},
                    {'C','C','F','C','F','C','C',' '}};
    int filas=sizeof(lotes)/sizeof(lotes[0]);
    int m=6,n=8;
    double p=0.7;
    //F=70 C=67 y ' '=32
//    cout<<filas;
    funcionClasificatorio(lotes,m,n,p);
    return 0;
    
}

