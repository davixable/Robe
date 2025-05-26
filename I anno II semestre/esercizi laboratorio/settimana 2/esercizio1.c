/*

1)Scrivere una funzione ricorsiva che, dato un vettore D di dimensione N, calcoli il
minimo valore tra la differenza di ogni elemento con il precedente (escluso il
primo).

*/

#include <stdlib.h>
#include <stdio.h>


int trovaDifferenzaMinima(int *arr, int l, int r, int differenza); 

int trovaDifferenzaMinima(int *arr, int l, int r, int differenza){
    if(l>r){
        return differenza;
    }
    int tempDiff=arr[l]-arr[l-1];
    if(tempDiff<differenza){
        differenza=tempDiff;
    }
    trovaDifferenzaMinima(arr, l+1, r, differenza);

}

int main(){
    int arr[]={-1,5,7,18,9,1,5,7,90};
    int size=sizeof(arr)/sizeof(int);
    int differenzaMinima=arr[1]-arr[0];
    differenzaMinima=trovaDifferenzaMinima(arr, 2, size-1, differenzaMinima);
    printf("La differenza minima tra due elementi dell'array e': %d.\n", differenzaMinima);
}