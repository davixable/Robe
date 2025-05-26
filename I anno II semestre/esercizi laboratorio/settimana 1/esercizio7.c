/*

7)Scrivere una funzione ricorsiva che, dato un array di interi restituisca 1 se tutti i suoi elementi sono pari,
0 altrimenti.

*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ricercapari(int *arr, int index, int size);

int ricercapari(int *arr, int index, int size){
    if (index>size){
        return 1;
    }
    if (arr[index]%2==1){
        return 0;
    }
    return ricercapari(arr, index+1, size);
}

int main(){
    int arr[10]={2,4,2,2,8,10,4,14,20,7};
    int size=sizeof(arr)/sizeof(int);
    int pari=ricercapari(arr, 0, size-1);
    if(pari){
        printf("Tutti i numeri presenti nell'array sono pari.\n");
    } else{
        printf("NON tutti gli elementi dell'array sono pari.\n");
    }
} 