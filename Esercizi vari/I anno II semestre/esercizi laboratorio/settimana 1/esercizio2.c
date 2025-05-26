/*

2)Scrivere una funzione ricorsiva che, dato un numero naturale N calcoli il numero di cifre in base 10 necessarie
per rappresentare N.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numerocifre(int N);

int numerocifre(int N){
    if (N<10){
        return 1;
    }
    return 1+numerocifre(N/10);
}

int main (){
    int N;
    printf("Inserisci il numero:\n");
    scanf("%d",&N);
    int numero_cifre=numerocifre(N);
    printf("Il numero di cifre necessarie per rappresentare %d in base 10 e': %d.\n", N, numero_cifre);
}