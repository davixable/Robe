/*

8)Scrivere una funziona ricorsiva restituisce il valore 1 se una matrice R possiede
due righe consecutive uguali, 0 altrimenti.

*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3

int checkIdenticalRows(int matrix[][N], int index);

int checkIdenticalRows(int matrix[][N], int row){
    if(row>=N-1){
        return 0;
    }
    int identical=1;
    for(int col=0;col<N;col++){
        if(matrix[row][col]!=matrix[row+1][col]){
            identical=0;
            break;
        }
    }
    if(identical){
        return 1;
    }
    return checkIdenticalRows(matrix, row+1);
}

int main (){
    int matrix[N][N]={{3,3,3},{3,3,3},{3,0,3}};
    int whatMyFunctionReturned=checkIdenticalRows(matrix, 0);
    printf("My function returned %d.\n", whatMyFunctionReturned);
}