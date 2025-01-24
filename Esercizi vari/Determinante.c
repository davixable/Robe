//Programma per trovare il determinante di una matrice
#include <stdio.h>
#include <stdlib.h>

void fill_Matrix(int **matrice, int size);
void print_Matrix(int **matrice, int size);
int find_Determinant(int **matrice, int size);
int complemento_Alg(int **matrice, int size, int colonna);

int main() {
    int size =0;
    int **matrice = NULL;
    printf("Inserisci il numero di righe/colonne della matrice: \n");
    scanf("%d", &size);

    matrice = malloc(size * sizeof(int*));
    for (int i=0; i<size; i++) {
    matrice[i] = malloc(size * sizeof(int));
    }

fill_Matrix(matrice, size);
print_Matrix(matrice, size);
int determinante = find_Determinant(matrice, size);

printf("Il determinante della matrice e' %d. \n", determinante);

    for (int i = 0; i < size; i++) {
        free(matrice[i]);
    }
    free(matrice);
    return 0;
}

void fill_Matrix(int **matrice, int size) {
    printf("Inseriamo gli elementi della matrice: \n");
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            printf("Elemento %d, %d: ", i+1,j+1);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void print_Matrix(int **matrice, int size) {
    printf("Ecco la matrice: \n");
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) { 
            printf("%d ", matrice[i][j]);
        }
        printf ("\n");
    }
}

int find_Determinant(int **matrice, int size) {
    int determinante=0;

    if (size==1) {
        determinante = matrice[0][0];
    }
    if (size==2) {
        determinante = (matrice[0][0]*matrice[1][1])-(matrice[0][1]*matrice[1][0]);
    }

//Laplace
    if (size>2) {
    for (int i=0; i<size;i++) {
        if (i%2==0) {
        determinante = determinante + matrice[0][i]*complemento_Alg(matrice, size, i);
        }
        if (i%2==1) {
            determinante = determinante + (-1)*matrice[0][i]*complemento_Alg(matrice, size, i);
        }
    }
    }
    return determinante;
}

int complemento_Alg(int **matrice, int size, int colonna) {
    int **sottomatrice = malloc((size-1) * sizeof(int*));
    for (int i=0; i<size-1; i++) {
    sottomatrice[i] = malloc((size-1) * sizeof(int));
    }
    int sottomatrice_det;
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-1;j++) {
            if (j >= colonna) {
            sottomatrice[i][j]=matrice[i+1][j+1];
            }
            else {
            sottomatrice[i][j]=matrice[i+1][j];
            }
        }
    }
   sottomatrice_det = find_Determinant(sottomatrice, size-1);

   for (int i = 0; i < size-1; i++) {
        free(sottomatrice[i]);
    }
    free(sottomatrice);
   return sottomatrice_det;
}