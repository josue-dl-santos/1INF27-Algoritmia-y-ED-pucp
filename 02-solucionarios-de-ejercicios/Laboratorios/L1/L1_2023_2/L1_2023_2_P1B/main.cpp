
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 30 de marzo de 2025, 20:26
 */

#include <iostream>
#include <iomanip>

using namespace std;
#define FILAS 4
#define COLUMNAS 10
bool buscasiguientes(int fila,int columna,int ndireccion,int posicionHallada,
        char pupiletras[][COLUMNAS],char *formula,int direccion[][2],int k){
    int filaComp,columnaComp;
    int cantVeri=0;
    for(int i=1;i<3;i++){
        filaComp=fila+direccion[ndireccion][0]*i;
        columnaComp=columna+direccion[ndireccion][1]*i;
        for(int j=0;j<3;j++)
            if(j!=posicionHallada and j!=k)
                if(pupiletras[filaComp][columnaComp]==formula[j]){
                    cantVeri++;
                    break; 
                }
        if(cantVeri==1)
            return true;
        else
            return false;
    }
}
void encuentraFormula(char pupiletras[][COLUMNAS],int fila,int columna,
        int direcciones[][2]){
    char formula[3]={'H','S','O'};
    int filaComp,columnaComp,k;
    bool bandera=false;;
    for(int j=0;j<3;j++){
        if(pupiletras[fila][columna]==formula[j]){
            bandera=true;
            k=j;
            break;
        }
    }
    if(bandera)
        for(int i=0;i<8;i++){
            filaComp=fila+direcciones[i][0];
            columnaComp=columna + direcciones[i][1];
            if(filaComp>=0 and filaComp<4 and columnaComp>=0 and columnaComp<10)
                for(int j=0;j<3;j++)
                    if(j!=k)
                        if(pupiletras[filaComp][columnaComp]==formula[j])
                            if(buscasiguientes(filaComp,columnaComp,i,j,
                                pupiletras,formula,direcciones,k))
                                cout<<fila<<","<<columna<<"  ";

        }
    
}
void BuscaPupiletra(char pupiletras[][COLUMNAS],int direcciones[][2]){
    for(int i=0;i<FILAS;i++)
        for(int j=0;j<COLUMNAS;j++)
            encuentraFormula(pupiletras,i,j,direcciones);      
}
int main(int argc, char** argv) {
    int direcciones[8][2]={{-1,0},
                           {-1,1},
                           {0,1},
                           {1,1},
                           {1,0},
                           {1,-1},
                           {0,-1},
                           {-1,-1}};
    char pupiletras[FILAS][COLUMNAS]={{'H','C','H','B','Y','S','O','S','O','H'},
                                      {'S','C','S','S','Y','Q','O','S','Z','K'},
                                      {'O','P','N','Y','O','K','F','H','C','K'},
                                      {'O','B','N','I','Y','S','P','O','O','K'}};
    BuscaPupiletra(pupiletras,direcciones);
    return 0;
}

