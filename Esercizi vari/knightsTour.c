//Knight's tour simulation using Warnsdorff's Heuristics

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 8

const int move_x[8]={-2, -2, -1, 1, 2, 2, 1, -1};
const int move_y[8]={1, -1, -2, -2, -1, 1, 2, 2};
int board[N][N];
int heuristic[N][N];

void initializeBoard();
void createHeuristic();
int knightsTour(int moves_count, int x, int y);
int legalMove(int x, int y);
int bestMove(int x, int y, int next_x, int next_y);
void printBoard();

void initializeBoard(){
    for (int i=0;i<N;i++){
        for (int j=0; j<N;j++){
            board[i][j]=-1;
        }
    }
}

void createHeuristic(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(board[i][j] == -1){ 
                int count = 0;
                for (int k = 0; k < N; k++){
                    int new_x = i + move_x[k];
                    int new_y = j + move_y[k];
                    if(legalMove(new_x, new_y)){
                        count++;
                    }
                }
                heuristic[i][j] = count;
            } else {
                heuristic[i][j] = -1;
            }
        }
    }
}

int knightsTour(int moves_count, int x, int y){
    
    if (moves_count==1+N*N){
        return 1;
    }
    for (int i=0;i<N;i++){
        createHeuristic();
        int next_x=x+move_x[i];
        int next_y=y+move_y[i];
        if(bestMove(x, y, next_x, next_y)){
            board[next_x][next_y]=moves_count;
            printBoard();
            usleep(200000);
            if(knightsTour(moves_count+1, next_x, next_y)){
                return 1;
            }
            board[next_x][next_y]=-1;
        }
    }
    return 0;
}

int legalMove(int x, int y){
    if (x>= 0 && x<N && y>=0 && y<N && board[x][y]==-1){
        return 1;
    } else{
        return 0;
    }
}

int bestMove(int x, int y, int next_x, int next_y){
    if(legalMove(next_x, next_y)){
        int nextMoveHeuristic=heuristic[next_x][next_y];
            for (int i=0;i<N;i++){
            int other_x=x+move_x[i];
            int other_y=y+move_y[i];
            if(legalMove(other_x, other_y)){
                if(heuristic[next_x][next_y]>heuristic[other_x][other_y]){
                    return 0;
                }
            }
        }
        return 1;
    } else{
        return 0;
    }
}

void printBoard(){
    puts("");
    for(int i=0;i<4*N;i++){
        printf("#");
    }
    puts("");
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            printf("%3d ", board[i][j]);
        }
        puts("");
    }
    for(int i=0;i<4*N;i++){
        printf("#");
    }
    puts("");
}

int main (){
    initializeBoard();
    int moves_count=1, x, y;
    printf("Inserisci coordinate iniziali (x,y):\n");
    scanf("%d%d", &x, &y);
    board[x][y]=1;
    if(knightsTour(moves_count+1, x, y)){
        printf("Soluzione trovata.\n");
    } else{
        printf("Soluzione non trovata.\n");
    }
}
