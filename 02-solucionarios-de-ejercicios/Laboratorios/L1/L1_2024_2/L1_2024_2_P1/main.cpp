

/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 24 de marzo de 2025, 11:33
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 * 
 */
void cargabin(int numero,int *cromosoma,int estado){
    int i=0;
    for(int j=0;j<10;j++)
        cromosoma[j]=0;
    while(numero>0){
        cromosoma[i]=numero%estado;
        numero=numero/2;
        i++;
    }
}
bool verificaletra(int *cromosoma,char *palabra,char* letras,int sizepalabra){
    char auxletras[10]{};
    int k=0,cant=0;
    for(int i=0;i<10;i++){
        if(cromosoma[i]==1){
            auxletras[k]=letras[i];
            k++;
        }
    }
    for(int j=0;j<sizepalabra;j++){
        for(int l=0;l<10;l++){
            if(auxletras[l]==palabra[j]){
                auxletras[l]=' ';
                cant++;
                break;
            }
        }
    }
    if(cant==sizepalabra)return true;
    else return false;
}
//int calcombinaciones(int *cromosoma,char *palabra,char *letras,int tamaño,int max){
//    int cantletras=4;
//    int cant=0;
//    for(int i=0;i<max;i++){
//        cargabin(i,cromosoma,2);
//        for(int j=0;j<cantletras;j++)
//            if(cromosoma[j]==1)
//                cant++;
//    }
//    if(cant==cantletras)
//        for
//}
int calculacombi(int sizepalabra,char *palabra,int combinaciones,int *cromosoma,
        char *letras){
    int cant=0,cantletras;
    bool bandera;
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromosoma,2);
        cantletras=0;
        for(int j=0;j<10;j++){
            cantletras+=cromosoma[j];
        }
        if(cantletras==sizepalabra){
                bandera=verificaletra(cromosoma,palabra,letras,sizepalabra);
                if(bandera){
//                    cout<<"La palabra se forma con: "<<i<<" ";
//                    for(int j=0;j<10;j++){
//                        if(cromosoma[j]==1)
//                            cout<<letras[j]<<' ';
//                    }
//                    cout<<endl;
//                    for(int k=0;k<10;k++)
//                        cout<<cromosoma[k]<<' ';
//                    cout<<endl;
                    cant++;
                }
            }
    }
    return cant;
}
int main(int argc, char** argv) {
    int cromosoma[10]{};
    char letras[8]={'G','A','L','A','O','G','L','M'};
    char palabra[8][5]={{'G','O','L'},
                        {'G','A','L','A'},
                        {'A','L','A'},
                        {'L','O','M','A'}};
    int tamano[8]={3,4,3,4},i=0;
    int combinaciones=pow(2,10)-1;
    int ncant;
    while(i<4){
        ncant=calculacombi(tamano[i],palabra[i],combinaciones,cromosoma,letras);
        cout<<"La cantidad de combinaciones para "<<palabra[i]<<" es "<<ncant<<endl;
        i++;
    }
    
    return 0;
    
}

