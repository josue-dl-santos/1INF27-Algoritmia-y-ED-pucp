
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 19 de junio de 2025, 16:14
 */

#include <iostream>
#include <iomanip>

using namespace std;

void merge(int *datos,int inicio,int medio,int fin,int n){
    int aux[n]{},p,q,m;
    for(p=inicio,q=medio+1,m=inicio;p<=medio and q<=fin;m++){
        if(datos[p]<datos[q])
            aux[m]=datos[p++];
        else
            aux[m]=datos[q++];
    }
    while(p<=medio)aux[m++]=datos[p++];
    while(q<=fin)aux[m++]=datos[q++];
    
    for(int i=inicio;i<=fin;i++)
        datos[i]=aux[i];
}

void mergeSort(int *datos,int inicio,int fin,int n){
    if(inicio==fin)return;
    int medio=(inicio+fin)/2;
    mergeSort(datos,inicio,medio,n);
    mergeSort(datos,medio+1,fin,n);
    merge(datos,inicio,medio,fin,n);
        
}

int BuscaTrio(int *datos,int inicio,int fin){
    //1 1 3 3 3 4 4 5 5 6 6 7 7
    if(inicio==fin)return datos[inicio];
    int medio= (inicio + fin)/2;
    
    if(medio%2==0){
        if(datos[medio]==datos[medio+1] and datos[medio]!=datos[medio-1]){
            return BuscaTrio(datos,medio+2,fin);
        }
        else
            return BuscaTrio(datos,inicio,medio);
    }
    else{
        if(datos[medio]==datos[medio-1] and datos[medio]!=datos[medio+1]){
            return BuscaTrio(datos,medio+1,fin);
        }
        else
            return BuscaTrio(datos,inicio,medio-1);
    }
    
}

int main(int argc, char** argv) {
    int datos[]={1,6,3,4,5,6,3,7,5,4,3,1,7};
    int n=sizeof(datos)/sizeof(datos[0]);
    mergeSort(datos,0,n-1,n);
    int dato=BuscaTrio(datos,0,n-1);
    cout<<"El empleado "<<dato<<" ingresó y no volvió a salir"<<endl;
//    for(int i=0;i<n;i++)cout<<datos[i]<<" ";
    return 0;
}

