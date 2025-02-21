#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
void bubbleSort(int *arr, int size);
void insertionSort(int *arr, int size);

void mergeSort(int *arr, int l, int r){
    if (l<r){
        int m=(l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(int *arr, int l, int m, int r){
    int size1=m-l+1;
    int size2=r-m;
    int *arr1=calloc(size1, sizeof(int));
    int *arr2=calloc(size2, sizeof(int));

    for (int i=0;i<size1;i++){
        arr1[i]=arr[l+i];
    }
    for (int i=0;i<size2;i++){
        arr2[i]=arr[m+i+1];
    }
    
    int i=0, j=0, k=l;
    while (i<size1 && j<size2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        } else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while (i<size1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while (j<size2){
        arr[k]=arr2[j];
        j++;
        k++;
    }

    free(arr1);
    free(arr2);
}
void bubbleSort(int *arr, int size){
    for (int i=0;i<size-1; i++){
        for (int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void insertionSort(int *arr, int size){
    for (int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main(){
    clock_t start, end;
    srand(time(NULL));
    int size;
    printf("Inserisci dimensione dell'array:\n");
    scanf("%d", &size);
    int *arr=calloc(size, sizeof(int));
    printf("Array originale:\n");
    for (int i=0;i<size;i++){
        arr[i]=rand()%100000;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    start=clock();
/*
    mergeSort(arr, 0, size-1);
    printf("Array dopo aver usato mergeSort:\n"); 
    bubbleSort(arr, size);
    printf("Array dopo aver usato bubbleSort:\n");
    insertionSort(arr, size);
    printf("Array dopo aver usato insertionSort:\n");
*/
    end=clock();
    for (int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int ordinato=1;
    for (int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            ordinato=0;
            break;
        }
    }
    if(ordinato){
        printf("L'array e' ordinato.\n");
    } else{
        printf("L'array non e' ordinato.\n");
    }
    printf("Tempo di esecuzione (stampa esclusa): %.3f secondi.\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
}