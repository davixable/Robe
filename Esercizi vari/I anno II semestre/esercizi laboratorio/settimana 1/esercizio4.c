/*
4)Scrivere una funzione ricorsiva che, avendo in input un array di N interi, 
dia in output il numero degli elementi positivi.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int conta_positivi(int *arr, int index, int size);

int conta_positivi(int *arr, int index, int size){
    int positivi=0;
    if(index>size){
        return 0;
    }
    if(arr[index]>=0){
        positivi++;
    }
    return positivi+conta_positivi(arr, index+1,size);
    
}

int main(){
    int arr[5]={4,0,-3,-2,1};
    int size=sizeof(arr)/sizeof(int);
    int positivi=conta_positivi(arr, 0, size-1);
    printf("Nell'array ci sono %d numeri positivi.\n", positivi);
}