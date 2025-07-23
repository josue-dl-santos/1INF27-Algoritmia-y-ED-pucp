
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 3 de abril de 2025, 16:37
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//Versión para C++
void PopulateGameBoard(int tamano,char **&tablero){
    tablero = new char*[tamano];
    for(int i=0;i<tamano;i++)
        tablero[i]=new char[tamano];
    srand(time(NULL));
    
    for(int i=0;i<tamano;i++)
        for(int j=0;j<tamano;j++){
            int caracter =  65 + rand() %(26);
            tablero[i][j] = static_cast<char>(caracter);
        }
            
    
}

void ShowGameBoard(int tamano,char **tablero){
    cout<<"Bienvenido al juego sopa de letras"<<endl<<endl;
    for(int i=0;i<tamano;i++){
        for(int j=0;j<tamano;j++){
            cout<<setw(1)<<tablero[i][j];
            if(j!=tamano-1)cout<<" | ";
        }
        cout<<endl;
    }
}

void SearchWord(char word[],int t,char **tablero,char res[3]){
                       
    int direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
    char code[4]={'U','R','D','L'};
    
    int cont;
    int x,y;
    bool bandera=false;
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            cont=0;
            if(tablero[i][j]==word[cont]){
                cont++;
                for(int a=0;a<4;a++){
                    x=i+direction[a][0];
                    y=j+direction[a][1];
                    if(x>=0 and x<t and y>=0 and y<t){
                        if(tablero[x][y] == word[cont]){
                            cont++;
                            while(cont<strlen(word)){
                                x=x+direction[a][0];
                                y=y+direction[a][1];
                                if(x>=t and x<0 and y>=t and y<0)break;
                                if(tablero[x][y]!=word[cont])break;
                                cont++;

                            }
                            if(cont==strlen(word)){
                                res[0]=(char)i;
                                res[1]=(char)j;
                                res[2]=code[a];
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    res[0]=-1;
    res[1]=-1;
    res[2]=-1;
    return;
    
}

void CalcularDireccion(char caracter,string &direccion){
    if(caracter=='U')direccion="arriba";
    if(caracter=='R')direccion="derecha";
    if(caracter=='D')direccion="abajo";
    if(caracter=='L')direccion="izquierda";
}

int main(int argc, char** argv) {
    
    int tamano,cantidad;
    char **tablero;
//    char tablero[5][5]={{'H','G','A','F','Y'},
//                        {'D','Q','G','Z','R'},
//                        {'A','M','E','N','H'},
//                        {'O','G','O','R','F'},
//                        {'T','R','W','I','P'}};
    cout<<"Ingrese el tamaño de la cuadricula:"<<endl;
    cin>>tamano;
    PopulateGameBoard(tamano,tablero);
    ShowGameBoard(tamano,tablero);
    cout<<"Ingrese la cantidad de palabras a buscar"<<endl;
    cin>>cantidad;
    char palabra[cantidad][tamano];
    for(int i=0;i<cantidad;i++){
        cout<<"Palabra "<<i+1<<": ";
        cin>>palabra[i];
    }
    char res[3];
    for(int i=0;i<cantidad;i++){
        SearchWord(palabra[i],tamano,tablero,res);
        if(res[0]!=-1){
        int fila=(int)res[0]+1;
        int columna=(int)res[1]+1;
        string direccion;
        CalcularDireccion(res[2],direccion);
        cout<<"Palabra 1 - "<<palabra[i]<<" encontrada en ("<<fila<<","<<columna<<
                ") - "<<direccion<<endl;
        }
        else
            cout<<"Palabra 1 - "<<palabra[i]<<" no encontrada"<<endl;
    }
    
    
    return 0;
}

