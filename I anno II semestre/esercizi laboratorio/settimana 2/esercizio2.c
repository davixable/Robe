/*

2)Scrivere una funzione ricorsiva che dato un vettore di float di dimensione N
restituisca il massimo tra le somme degli elementi simmetrici. Se il vettore ha
dimensione 1 la funzione ritorna l’elemento del vettore.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float trovaSommaMax(float arr[], int l, int r, float somma);

float trovaSommaMax(float arr[], int l, int r, float somma){
    if(r==0){
        return arr[r];
    }
    if(r<=l){
        return somma;
    }
    float sommaTemp=arr[l]+arr[r];
    if(sommaTemp > somma){
        somma=sommaTemp;
    }
    return trovaSommaMax(arr, ++l, --r, somma);
}

int main(){
    srand(time(NULL));
    int size;
    scanf("%d",&size);
    float *arr=malloc(size*sizeof(float));
    printf("Array originale:\n");
    for(int i=0;i<size;i++){
        arr[i]=rand()%120;
        printf("%f ", arr[i]);
    }
    float sommaMax=0;
    sommaMax=trovaSommaMax(arr, 0, size-1, sommaMax);
    printf("La somma max tra 2 elementi del'array e': %.1f.\n", sommaMax);
    free(arr);
}