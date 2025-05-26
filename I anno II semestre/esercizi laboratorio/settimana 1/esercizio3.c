/*
    
3)Scrivere una funzione ricorsiva per la stampa degli elementi di un array ricevuto in input
(nell'ordine in cui compaiono nell'array).

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somma(int *arr, int index, int size);

int somma(int *arr, int index, int size){
    if(index==size){
        return arr[index];
    }
    return arr[index]+somma(arr, index+1, size);
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

    int somma_num=somma(arr, 0, 9);
    printf("La somma dei numeri contenuti nell'array e': %d.\n", somma_num);
}