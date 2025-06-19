

/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 19 de junio de 2025, 15:08
 */

#include <iostream>
#include <iomanip>

using namespace std;

char BuscaTrio(char *arreglo,int inicio,int fin){
    if(inicio>fin) return '1';
    if(inicio==fin){
        return arreglo[inicio];
    }
    int medio = (inicio + fin)/2;
    if(medio%2==0){
        if(arreglo[medio]==arreglo[medio+1]and arreglo[medio]!=arreglo[medio-1]){
            return BuscaTrio(arreglo,medio+2,fin);
        }
        else
            return BuscaTrio(arreglo,inicio,medio);
    }
    else{
        if(arreglo[medio]==arreglo[medio-1] and arreglo[medio]!=arreglo[medio+1]){
            return BuscaTrio(arreglo,medio+1,fin);
        }
        else
            return BuscaTrio(arreglo,inicio,medio-1);
    
    }
}

int main(int argc, char** argv) {
    //Se coloca 1 como si fuera un espacio en blanco
    char bocaditos[][11]={{'O','O','C','C','A','A','E','E','R','R','R'},
                       {'C','C','A','A','R','R','E','E','B','B','1'},
                       {'R','R','E','E','C','C','F','F','A','A','1'},
                       {'E','E','F','F','A','A','A','B','B','R','R'},
                       {'C','C','C','A','A','R','R','O','O','E','E'},
                       {'O','O','C','C','A','A','R','R','E','E','1'},
                       {'A','A','F','F','R','R','E','E','O','O','1'},
                       {'E','E','A','A','O','O','B','B','F','F','1'}};
    int filas=sizeof(bocaditos)/sizeof(bocaditos[0]);
    char caracter;
    for(int i=0;i<filas;i++){
        int columnas=sizeof(bocaditos[i])/sizeof(bocaditos[i][0]);
        
        caracter=BuscaTrio(bocaditos[i],0,columnas);
        if(caracter!='1')
            cout<<"La fila "<<i+1<<" tiene un "<<caracter<<" adicional"<<endl;
        
    }
    return 0;
}

