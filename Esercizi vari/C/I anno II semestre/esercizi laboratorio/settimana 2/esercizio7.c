/*

7)Scrivere una funzione ricorsiva che restituisce 1 se tutti gli elementi della
diagonale di una matrice quadrata Q sono positivi e gli altri nulli.

*/

#include <stdlib.h>
#include <stdio.h>
#define N 3

int isDiagonal(int arr[][N], int row);

int isDiagonal(int arr[][N], int row){
    if(row>N-1){
        return 1;
    }
    for(int col=0;col<N;col++){
        if(row==col){
            if (arr[row][col]<0){
                return 0;
            }
        } else{
            if(arr[row][col]!=0){
                return 0;
            }
        }
    }
    return isDiagonal(arr, row+1);
}

int main(){
    int arr[N][N]={
                    {3,0,0},
                    {0,-1,0},
                    {0,0,1}};
    int diagonalePositiva=isDiagonal(arr, 0);
    if(diagonalePositiva){
        printf("La matrice e' diagonale positiva\n");
    } else{
        printf("La matrice NON e' diagonale positiva.\n");
    }
}