/*

3)Scrivere una funzione ricorsiva che verifica se un array dato in input è ordinato in
modo non decrescente. Un vettore nullo o di dimensione 1 è non decrescente.

*/

#include <stdio.h>
#include <stdlib.h>

int checkDescending(int *arr, int l, int r){
    if(r==0){
        return 0;
    }
    if(l==r){
        return 1;
    }
    if(arr[l]>arr[l+1]){
        return checkDescending(arr, ++l, r);
    } else{
        return 0;
    }

}
int main(){
    int arr[]={5,4,3,2};
    int size=sizeof(arr)/sizeof(int);
    int decrescente=checkDescending(arr, 0, size-1);
    if(decrescente){
        printf("L'array e' ordinato in modo descrescente.\n");
    } else{
        printf("L'array NON e' ordinato in modo decrescente.\n");
    }
}