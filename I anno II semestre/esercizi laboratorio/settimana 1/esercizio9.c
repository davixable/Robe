/*

9)Scrivere una funzione che, dato un array di N float, lo inverta.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

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
    float arr[N]={5.0,4.0,3.0,2.0,0.0,-2.5,8.5,-15.0,-11.0,-1.0};
    printf("Array originale:\n");
    for(int i=0;i<N;i++){
        printf("%.1f ", arr[i]);
    }
    puts("");

    inverti(arr, 0);

    printf("Array invertito:\n");
    for(int i=0;i<N;i++){
        printf("%.1f ", arr[i]);
    }
    puts("");
}