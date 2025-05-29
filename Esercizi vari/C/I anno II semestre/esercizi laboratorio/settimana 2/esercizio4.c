/*

4)Scrivere una funzione ricorsiva che presa in input una stringa restituisca 1 se in
tutte le posizioni è presente una vocale, 0 altrimenti

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
        return checkVowels(stringa, ++l, r);
    } else{
        return 0;
    }
}

int isVowel(char stringa){
    stringa=toupper(stringa);
    if((stringa!='A')&&(stringa!='E')&&(stringa!='I')&&(stringa!='O')&&(stringa!='U')){
        return 0;
    }
    return 1;
}

int main(){
    char stringa[]="EAAAAAAqA";
    size_t size=sizeof(stringa)/sizeof(char);
    int onlyVowels=checkVowels(stringa, 0, size-2);
    if(onlyVowels){
        printf("La stringa ha solo vocali.\n");
    } else{
        printf("La stringa NON ha solo vocali.\n");
    }
}