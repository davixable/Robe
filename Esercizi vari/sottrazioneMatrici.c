#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampaMatrice(int **matrix, int size);
void sottrazioneMatrici(int **matrix1, int **matrix2, int **matrix3, int size);

int main () 
{
    int **matrix1=NULL;
    int **matrix2=NULL;
    int **matrix3=NULL;
    int size;
    srand(time(NULL));
    printf("Inserisci la size delle matrici: \n");
    scanf("%d", &size);
    matrix1=malloc(size*(sizeof(int*)));
    matrix2=malloc(size*(sizeof(int*)));
    matrix3=malloc(size*(sizeof(int*)));
    for (int i=0;i<size;i++) {
        *(matrix1+i)=malloc(size*(sizeof(int)));
        *(matrix2+i)=malloc(size*(sizeof(int)));
        *(matrix3+i)=malloc(size*(sizeof(int)));
    }
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
        matrix1[i][j]=rand()%10;
        matrix2[i][j]=rand()%10;
        matrix3[i][j]=0;
        }
    }
    printf("Matrice 1: \n");
    stampaMatrice(matrix1, size);
    printf("Matrice 2: \n");
    stampaMatrice(matrix2, size);
    printf("Matrice 3 prima della sottrazione: \n");
    stampaMatrice(matrix3, size);
    sottrazioneMatrici(matrix1, matrix2, matrix3,size);
    printf("Matrice 3 che contiene i risultati della sottrazione: \n");
    stampaMatrice(matrix3, size);

    for (int i=0;i<size;i++) {
        free(*(matrix1+i));
        free(*(matrix2+i));
        free(*(matrix3+i));
    }

    free(matrix1);
    free(matrix2);
    free(matrix3);
}
void stampaMatrice(int **matrix, int size)
{
    for (int i=0; i<size;i++) {
        for (int j=0; j<size; j++) {
            printf("%2d ",matrix[i][j]);
        }
        puts("");
    }
}

void sottrazioneMatrici(int **matrix1, int **matrix2, int **matrix3,int size)
{
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            matrix3[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }
}
