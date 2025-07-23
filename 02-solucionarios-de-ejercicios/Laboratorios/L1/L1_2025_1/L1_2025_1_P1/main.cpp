/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 5 de abril de 2025, 09:07 AM
 */

//Es una solución para un caso en específico, no es paramétrico para cualquier dato de entrada

#include <iostream>
#include <iomanip>

using namespace std;
#include <cmath>
#include <climits>
#define ESTADOS 3;
#define NTABLAS 6;

void cargabase(int numero,int base,int *cromosoma){
    int i=0;
    for (int j=0;j<6;j++)
        cromosoma[j]=0;
    while(numero>0){
        cromosoma[i]=numero%base;
        numero=numero/base;
        i++;
    }
}

int CalMenorVeloc(int *cromosoma,int *tablas,int *disco,int &menorveloc){
    int auxdisco[4]{};
    int menorvalor=INT_MAX;
    bool bandera=false;
    for(int i=0;i<3;i++){
        auxdisco[i]=disco[i];
    }
    for(int j=0;j<6;j++){
        if(cromosoma[j]==0)
            auxdisco[0]=auxdisco[0]-tablas[j];
        if(cromosoma[j]==1)
            auxdisco[1]=auxdisco[1]-tablas[j];
        if(cromosoma[j]==2)
            auxdisco[2]=auxdisco[2]-tablas[j];
    }
    for(int i=0;i<3;i++){
        if(auxdisco[i]<menorvalor){
            menorvalor=auxdisco[i];
        }
    }
    if(menorvalor<=0)return false;
    for(int i=0;i<3;i++){
        if(auxdisco[i]==disco[i]){
            bandera=true;
            break;
        }
        
    }
    if(bandera)return false;
    else {
        menorveloc=menorvalor;
        return true;
    }
}

int CalculaMin(int a,int b,int c,int &posicion){
    if(a<=b and a<=c){
        posicion=1;
        return a;
    }
    if(b<=a and b<=c){
        posicion=2;
        return b;
    }
    if(c<=b and c<=a){
        posicion=3;
        return c;
    }
}

void ImprimirCombi(int combinacion,int *cromosoma,int *disco,int *tablas){
    int respuestas[3][6]{};
    int velocidad[3]{};
    velocidad[0]=disco[0];
    velocidad[1]=disco[1];
    velocidad[2]=disco[2];
    for(int i=0;i<3;i++)
        for(int j=0;j<6;j++)
            respuestas[i][j]=-1;
    int a=0,b=0,c=0;
    cargabase(combinacion,3,cromosoma);
    for(int i=0;i<6;i++){
        if(cromosoma[i]==0){
            respuestas[0][a]=i+1;
            velocidad[0]-=tablas[i];
            a++;
//            cout<<"Disco 1 : Tabla "<<i+1<<endl;
        }
        if(cromosoma[i]==1){
            respuestas[1][b]=i+1;
            velocidad[1]-=tablas[i];
            b++;
//            cout<<"Disco 2 : Tabla "<<i+1<<endl;
        }
        if(cromosoma[i]==2){
            respuestas[2][c]=i+1;
            velocidad[2]-=tablas[i];
            c++;
//            cout<<"Disco 3 : Tabla "<<i+1<<endl;
        }
    }
    int ndisco;
    int velocidadMinima=CalculaMin(velocidad[0],velocidad[1],velocidad[2],ndisco);
    cout<<"Disco      |     Tablas"<<endl;
    for(int i=0;i<3;i++){
        cout<<i+1<<setw(10)<<" "<<"|"<<setw(5)<<" ";
        for(int j=0;j<6;j++){
            if(respuestas[i][j]!=-1){
                cout<<respuestas[i][j];
                if(respuestas[i][j+1]!=-1)cout<<",";
            }
        }
        cout<<endl;
    }
    cout<<"Esta solución tiene una velocidad mínima de grupo de "<<velocidadMinima<<
            " IOPs que se da en el disco "<<ndisco<<endl;
}

void CalculaSoluOptima(int *tablas,int *disco,int combinaciones){
    int cromosoma[7];
    int combinacion_respuesta=-1;
    int minimo=INT_MIN;
    int menorVeloc=INT_MAX;
    bool bandera=false;
    for(int i=0;i<combinaciones;i++){
        cargabase(i,3,cromosoma);
        if(CalMenorVeloc(cromosoma,tablas,disco,menorVeloc))
            if(menorVeloc>minimo){
                combinacion_respuesta=i;
                bandera=true;
                minimo=menorVeloc;
            }
    }
    if(!bandera){
        cout<<"No hubo solución optima";
    }
    else{
//        cout<<combinacion_respuesta<<endl;
        ImprimirCombi(combinacion_respuesta,cromosoma,disco,tablas);
    }
}

int main(int argc, char** argv) {
    int tablas[7]={150,100,80,50,120,10};
    int disco[4]={250,200,200};
    int base=ESTADOS;
    int narma=NTABLAS+1;
    int combinaciones=pow(base,narma)-1;
    CalculaSoluOptima(tablas,disco,combinaciones);
    return 0;
}

