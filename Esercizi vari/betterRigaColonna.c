#include <stdio.h>
#include <stdlib.h>

int** createMatrix (int row, int col);
void fillMatrix(int **matrix, int row, int col);
void printMatrix(int **matrix, int row, int col);
void rowcolProd(int **matrix1, int **matrix2, int **matrix3, int row1, int col1, int row2, int col2);
void freeMatrix(int **matrix, int row);

int main ()
{
    int row1, col1;
    int row2, col2;
    printf("Questo programma ti permette di effettuare il prodotto riga colonna tra matrici. \n");
    printf("Ti ricordo che il numero di colonne della prima matrice deve essere uguale al numero di righe della seconda\n");

    printf("Inserisci il numero di righe della prima matrice:\n");
    scanf("%d", &row1);
    printf("Inserisci il numero di colonne della prima matrice: \n");
    scanf("%d", &col1);

    printf("Inserisci il numero di righe della seconda matrice:\n");
    scanf("%d", &row2);
    printf("Inserisci il numero di colonne dela seconda matrice: \n");
    scanf("%d", &col2);

    if (col1!=row2) {
        printf("La prima matrice ha un numero di colonne differente dalle righe della seconda.\n");
        printf("Non e' possibile effettuare la moltiplicazione.\n");
        return 1;
    }
    int row3=row1;
    int col3=col2;

    int **matrix1=createMatrix(row1, col1);
    int **matrix2=createMatrix(row2, col2);
    int **matrix3=createMatrix(row3, col3);

    printf("Inseriamo gli elementi della prima matrice:\n");
    fillMatrix(matrix1, row1, col1);
    printf("Inseriamo gli elementi della seconda matrice: \n");
    fillMatrix(matrix2,row2,col2);

    printf("Questa e' la prima matrice: \n");
    printMatrix(matrix1, row1, col1);
    printf("Questa e' la seconda matrice: \n");
    printMatrix(matrix2, row2, col2);

    rowcolProd(matrix1, matrix2, matrix3, row1, col1, row2, col2);
    printf("Il prodotto tra le due matrici e': \n");
    printMatrix(matrix3, row3, col3);
    
    freeMatrix(matrix1, row1);
    freeMatrix(matrix2, row2);
    freeMatrix(matrix3, row3);
}

int** createMatrix (int row, int col)
{   
    int **matrix=NULL;
    matrix=malloc(row*sizeof(int*));
    for (int i=0;i<row;i++) {
        matrix[i]=calloc(col*sizeof(int));
    }
    return matrix;
}

void fillMatrix(int **matrix, int row, int col)
{
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            printf("Elemento di indice %d %d :", i+1,j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int row, int col)
{
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

void rowcolProd(int **matrix1, int **matrix2, int **matrix3, int row1, int col1, int row2, int col2)
{
    for (int i=0;i<row1;i++) {
        for (int j=0;j<col2;j++) {
            for (int k=0;k<row2;k++) {
                matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}

void freeMatrix(int **matrix, int row)
{
    for (int i=0; i<row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}