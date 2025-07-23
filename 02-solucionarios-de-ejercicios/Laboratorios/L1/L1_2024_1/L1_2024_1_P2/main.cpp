
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 4 de abril de 2025, 22:55
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */

int CantidadUnidadesEncontradas(int matriz[][6],int x,int y,int nivel){
    if(x-nivel<0 or y-nivel<0 or x+nivel>=6 or y+nivel>=6)return 0;
    int cont=0;
    
    if(nivel==0){
        if(matriz[x][y]==1)cont++;
    }
    else{
    for(int i=y-nivel;i<y+nivel;i++)
        if(matriz[x-nivel][i]==1)cont++;
    
    for(int i=x-nivel;i<x+nivel;i++)
        if(matriz[i][y+nivel]==1)cont++;
    
    for(int i=y+nivel;i>y-nivel;i--)
        if(matriz[x+nivel][i]==1)cont++;
    
    for(int i=x+nivel;i>x-nivel;i--)
        if(matriz[i][y-nivel]==1)cont++;
    
    }
    nivel++;
    return cont+CantidadUnidadesEncontradas(matriz,x,y,nivel);
}

int main(int argc, char** argv) {
    int matriz[6][6]={{0,0,0,1,0,1},
                      {0,0,1,0,0,0},
                      {0,1,0,0,0,1},
                      {1,0,0,0,0,0},
                      {0,1,0,0,0,0},
                      {0,0,0,0,1,0}};
    int x=3;
    int y=2;
    int cantidad=CantidadUnidadesEncontradas(matriz,x,y,0);
    cout<<cantidad<<" unidades";
    return 0;
}

