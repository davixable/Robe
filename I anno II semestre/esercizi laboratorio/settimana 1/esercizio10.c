/*

10)Risolvere lo stesso problema dell'esercizio precedente avendo come input una stringa
(es: "Adesso" diventa "ossedA")

*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void inverti(float *arr, int index);

void inverti(float *arr, int index){
    if(index>=N/2){
        return;
    }
    float temp=arr[index];
        arr[index]=arr[N-index-1];
        arr[N-index-1]=temp;
    inverti(arr, index+1);
}

int main(){
    char parola[50];
    printf("Inserisci la parola da invertire:\n");
    fgets(49s)

    inverti(parola, 0);

    printf("Array invertito:\n");
    for(int i=0;i<N;i++){
        printf("%.1f ", arr[i]);
    }
    puts("");
}