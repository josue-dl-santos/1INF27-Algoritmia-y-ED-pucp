
/* 
 * File:   main.cpp
 * Author: josue
 *
 * Created on 19 de abril de 2025, 13:35
 */

#include <iostream>
#include <iomanip>
#define N 5
#define M 5
using namespace std;
#include <climits>
//void ReponeStock(int matriz[][M],int fila,int columna,int x,int y,int &mayor){
//    if(x==fila and y==columna){
//        return;
//    }
//    if(matriz[x][y]>=mayor)mayor=matriz[x][y];
//    
//    if(y<columna-1){
//        ReponeStock(matriz,fila,columna,x,y+1,mayor);
//    }
//    if(x<fila-1){
//        ReponeStock(matriz,fila,columna,x+1,y,mayor);
//    }
////    matriz[x][y]=mayor-matriz[x][y];
//}
void ReponeStock(int matriz[][M],int fila,int columna,int i,int &mayor){
    if(i==N*M) return;
    if(matriz[i/M][i%M]>=mayor)mayor=matriz[i/M][i%M];
    ReponeStock(matriz,fila,columna,i+1,mayor);
    matriz[i/M][i%M]=mayor-matriz[i/M][i%M];
        
}

int main(int argc, char** argv) {
    int matriz[N][M]={{4,3,6,8,7},
                      {6,3,8,4,10},
                      {2,15,1,2,13},
                      {5,1,10,11,2},
                      {10,4,7,9,4}};
    int mayor=INT_MIN;
    ReponeStock(matriz,N-1,M-1,0,mayor);
    cout<<mayor<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
        cout<<setw(2)<<matriz[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

