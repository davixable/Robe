/*

8)Scrivere una funzione ricorsiva che, dato un array di interi e un intero K, restituisca la posizione
dell'ultima occorrenza di K nell'array, -1 se K non è presente nell'array.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ricerca_num(int *arr, int index, int target);

int ricerca_num(int *arr, int index, int target){
    if(index<0){
        return -1;
    }
    if(arr[index]==target){
        return index;
    }
    return ricerca_num(arr, index-1, target);
    
}

int main (){
    srand(time(NULL));
    int arr[10];
    printf("Array generato:\n");
    for (int i=0;i<10;i++){
        arr[i]=rand()%10;
        printf("%d ", arr[i]);
    }
    puts("");
    int k;
    printf("Quale numero vuoi cercare?\n");
    scanf("%d", &k);
    int size=sizeof(arr)/sizeof(int);
    int trovato=ricerca_num(arr, size-1, k);
    
    if(trovato==-1){
        printf("Il numero %d non e' presente nell'array.\n", k);
    } else{
        printf("L'ultima occorrenza del numero %d nell'array e' all'indice %d.\n", k, trovato);
    }
}