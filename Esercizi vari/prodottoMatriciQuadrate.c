#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int size);
void fillMatrix(int **matrix, int size);
void printMatrix (int **matrix, int size) ;
void prodottoMatrici (int **matrix1, int **matrix2, int **matrix3, int size);
void freeMatrix(int **matrix, int size);

int main ()
{
    int size;
    printf("Inserisci la size della matrice: \n");
    scanf("%d", &size);
    int **matrix1=createMatrix(size);
    int **matrix2=createMatrix(size);
    int **matrix3=createMatrix(size);
    printf("Inseriamo gli elementi della prima matrice: \n");
    fillMatrix(matrix1,size);
    printf("Inseriamo gli elmeenti della seconda matrice: \n");
    fillMatrix(matrix2,size);
    printf("La prima matrice e': \n");
    printMatrix(matrix1, size);
    printf("La seconda matrice e': \n");
    printMatrix(matrix2,size);
    printf("Il prodotto tra le due matrici e': \n");
    prodottoMatrici(matrix1,matrix2,matrix3,size);
    printMatrix(matrix3,size);
    freeMatrix(matrix1,size);
    freeMatrix(matrix2,size);
    freeMatrix(matrix3,size);
}

int** createMatrix(int size)
{   
    int **matrix=NULL;
    matrix=malloc(size*(sizeof(int*)));
    for (int i=0;i<size;i++) {
        *(matrix+i)=malloc(size*(sizeof(int)));
    }
    return matrix;
}
void fillMatrix(int **matrix, int size)
{
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            printf("Elemento di indice %d %d: ",i+1,j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printMatrix (int **matrix, int size) 
{
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++){
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}
void prodottoMatrici (int **matrix1, int **matrix2, int **matrix3, int size)
{   
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            matrix3[i][j]=0;
        }
    }
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            for (int k=0;k<size;k++) {
                matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}
void freeMatrix(int **matrix, int size) 
{
    for (int i=0;i<size;i++) {
        free(matrix[i]);
    }
    free(matrix);
}