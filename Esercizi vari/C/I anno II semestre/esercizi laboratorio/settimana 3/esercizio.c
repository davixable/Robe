/*

Scrivere un programma che :
1)Allochi dinamicamente e restituisca una matrice A di interi con numero di righe N e
colonne M inserite dall'utente.

2)Richieda l'inserimento degli elementi all'utente e li inserisca nella matrice A.

3)Visualizzi la matrice A.

4)Allochi dinamicamente una matrice quadrata  avente per dimensione la minima tra N e M e per elementi i
corrispondenti elemneti di A.

5)Attraverso un'opportuna funzione ricorsiva o iterativa, restituisca 1 se la matrice Q è a righe costanti, ovvero
se tutti gli elementi della stessa riga sono uguali, 0 altrimenti.

6)Se la matrice A ha almeno 3 righe e 3 colonne, stampi la sottomatrice quadrata di dimensione 3x3 per cui 
la somma degli elemneti sia massima. 

7)Chiuda il programma effettuando la deallocazione di A e Q 

*/

#include <stdio.h>
#include <stdlib.h>


int **getMatrix(int rows, int cols);
int checkMatrix(int **matrix, int size);
void printSubMatrix(int **matrix, int size, int cols);

int checkMatrix(int **matrix, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size-1; j++){
            if(matrix[i][j] != matrix[i][j+1]){
                return 0;
            }
        }
    }
    return 1;
}

int **getMatrix(int rows, int cols){
    int **matrix = malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++){
        matrix[i] = malloc(cols*sizeof(int));
    }
    printf("Inserisci gli elementi della matrice:\n");
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Elemento [%d, %d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        puts("");
    }
    return matrix;
}

void printSubMatrix(int **matrix, int rows, int cols){
    int x = 0, y = 0;
    int somma = matrix[0][0] + matrix[0][1] + matrix[0][2]
              + matrix[1][0] + matrix[1][1] + matrix[1][2]
              + matrix[2][0] + matrix[2][1] + matrix[2][2];

    for (int i = 0; i < rows - 2; i++){
        for (int j = 0; j < cols - 2; j++){
            int sommaTemp = matrix[i][j] + matrix[i][j+1] + matrix[i][j+2]
                        + matrix[i+1][j] + matrix[i+1][j+1] + matrix[i+1][j+2]
                        + matrix[i+2][j] + matrix[i+2][j+1] + matrix[i+2][j+2];
            if (sommaTemp > somma){
                somma = sommaTemp;
                x = i;
                y = j;
                }
        }
    }

    printf("\nLa sottomatrice con somma massima e':\n");
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", matrix[i+x][j+y]);
        }
        puts("");
    }
}


int main(){
    int rows, cols;
    printf("Inserisci numero di righe:\n");
    scanf("%d", &rows);
    printf("Inserisci numero di colonne:\n");
    scanf("%d", &cols);
    int **matrixA = getMatrix(rows, cols);

    printf("Ecco la matrice:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", matrixA[i][j]);
        }
        puts("");
    }

    int minore = rows;
    if(cols < rows){
        minore = cols;
    }
    int **matrixQ = malloc(minore*sizeof(int*));
    for (int i = 0; i < minore; i++){
        matrixQ[i] = malloc(minore*(sizeof(int)));
    }

    for (int i = 0; i < minore; i++){
        for (int j = 0; j < minore; j++){
            matrixQ[i][j] = matrixA[i][j];
        }
    }

    int costanti = checkMatrix(matrixQ, minore);

    if(rows >= 3 && cols >= 3){
        printSubMatrix(matrixA, rows, cols);
    }
    free(matrixA);
    free(matrixQ);
}