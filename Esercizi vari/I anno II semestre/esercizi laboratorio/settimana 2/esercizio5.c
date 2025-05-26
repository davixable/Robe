/*

5)Scrivere una funzione ricorsiva che presa in input una stringa restituisca 1 se in
tutte le posizioni pari (0,2,4,…) è presente una vocale, 0 altrimenti.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkVowels(char *stringa, size_t l, size_t r);
int isVowel(char stringa);

int checkVowels(char *stringa, size_t l, size_t r){
    if(l>r){
        return 1;
    }
    if(isVowel(stringa[l])){
        return checkVowels(stringa, l+2, r);
    } else{
        return 0;
    }
}

int isVowel(char lettera){
    lettera=toupper(lettera);
    if((lettera!='A')&&(lettera!='E')&&(lettera!='I')&&(lettera!='O')&&(lettera!='U')){
        return 0;
    }
    return 1;
}

int main(){
    char stringa[]="AbEriop";
    size_t size=sizeof(stringa)/sizeof(char);
    int onlyVowels=checkVowels(stringa, 0, size-2);
    if(onlyVowels){
        printf("La stringa ha solo vocali nelle posizioni pari.\n");
    } else{
        printf("La stringa NON ha solo vocali nelle posizioni pari.\n");
    }
}