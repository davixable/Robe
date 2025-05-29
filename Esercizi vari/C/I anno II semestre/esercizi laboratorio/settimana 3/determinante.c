#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int size);
void freeMatrix(int **matrix, int size);
void fillMatrix(int **matrix, int size);
int findDeterminant(int **matrix, int size);
int** createSubMatrix(int **matrix, int size, int col);

int** createMatrix(int size){
    int **matrix=malloc(size*sizeof(int*));
    for(int i=0;i<size;i++){
        matrix[i]=malloc(size*sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int size){
    for(int i=0;i<size;i++){
        free(matrix[i]);
    }
    free(matrix);
}

void fillMatrix(int **matrix, int size){
    for(int i=0;i<size;i++){
        printf("Riga #%d\n", i);
        for(int j=0;j<size;j++){
            printf("Inserisci elemento di indice %d,%d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        puts("");
    }
}

int findDeterminant(int **matrix, int size){
    if (size==1){
        return matrix[0][0];
    }

    if (size==2){
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    }

    int determinant=0;

    if(size>2){
        for (int col=0;col<size;col++){
            int **submatrix = createSubMatrix(matrix, size-1, col);
            if(col%2==0){
                determinant = determinant + matrix[0][col]*findDeterminant(submatrix, size-1);
                freeMatrix(submatrix, size-1);
            }
            if(col%2==1){
                determinant = determinant + -1*matrix[0][col]*findDeterminant(submatrix, size-1);
                freeMatrix(submatrix, size-1);
            }
        }
    }
    return determinant;
}

int** createSubMatrix(int **matrix, int size, int col){
    int **submatrix = createMatrix(size);

    for(int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if(j>=col){
                submatrix[i][j]=matrix[i+1][j+1];
            } else{
                submatrix[i][j]=matrix[i+1][j];
            }
        }
    }
    return submatrix;
}

int main (){
    int size = -1;
    printf("Inserisci la dimensione della matrice:\n");
    scanf("%d", &size);

    int **matrix = createMatrix(size);
    fillMatrix(matrix, size);

    int determinant = findDeterminant(matrix, size);
    printf("Il determinante della matrice fornita e': %d.\n", determinant);

    freeMatrix(matrix, size);
}