/*
1)Scrivere una funzione ricorsiva che, presi in input due interi M ed N, restituisca la somma di tutti gli interi 
compresi tra M ed N.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somma_num(int M, int N);

int somma_num(int M, int N){
    if(M==N){
        return N;
    }
    if(M>N){
        return 0;
    }
    return M+somma_num(M+1,N);
}

int main (){
    int M,N;
    printf("Inserisci i due numeri:\n");
    scanf("%d%d",&M, &N);
    int somma = somma_num(M,N);
    printf("La somma dei numeri compresi tra %d e %d e': %d.\n", M, N, somma);
}