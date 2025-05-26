/*

5)Scrivere una funzione ricorsiva che dato un array di interi e due interi x e y, restituisca la somma degli
elementi dell'array che si trovano dalla posizione x alla posizione y

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somma_num(int *arr, int x, int y);

int somma_num(int *arr, int x, int y){
    if(x==y){
        return arr[x];
    }
    return arr[x]+somma_num(arr,x+1,y);
}

int main(){
    srand(time(NULL));
    int arr[10];
    printf("Array generato:\n");
    for (int i=0;i<10;i++){
        arr[i]=rand()%10;
        printf("%d ", arr[i]);
    }
    puts("");
    int size=sizeof(arr)/sizeof(int);
    int x, y;
    printf("Da che indice vuoi cominciare a sommare? (max. 9)\n");
    scanf("%d", &x);
    printf("A quale indice vuoi fermarti? (max.9)\n");
    scanf("%d", &y);
    int somma=somma_num(arr, x, y);
    printf("La somma delle cifre che vanno dall'indice %d all'indice %d e' : %d.\n", x,y, somma);
}