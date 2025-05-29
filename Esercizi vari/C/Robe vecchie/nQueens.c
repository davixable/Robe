#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

wchar_t **initializeBoard(int N);
int nQueens(wchar_t **board, int N, int row);
void shuffleCols(int *cols, int N);
int legalMove(wchar_t **board, int N, int row, int col);
void printBoard(wchar_t **board, int N);
void exitGame(wchar_t **board, int N);

wchar_t **initializeBoard(int N) {
    wchar_t **board = malloc(N * sizeof(wchar_t *));
    for (int i = 0; i < N; i++) {
        board[i] = malloc(N * sizeof(wchar_t));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = L'.';
        }
    }
    return board;
}

int nQueens(wchar_t **board, int N, int row) {
    if (row == N) {
        return 1;
    }
    int *cols = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        cols[i] = i;
    }
    shuffleCols(cols, N);
    for (int k = 0; k < N; k++) {
        int col = cols[k];
        if (legalMove(board, N, row, col)) {
            board[row][col] = L'♕';
            printBoard(board, N);
            usleep(250000);
            if (nQueens(board, N, row + 1)) {
                free(cols);
                return 1;
            }
            board[row][col] = L'.';
        }
    }
    free(cols);
    return 0;
}

void shuffleCols(int *cols, int N) {
    for (int i = 0; i < N - 1; i++) {
        int j = i + rand() % (N - i);
        int temp = cols[j];
        cols[j] = cols[i];
        cols[i] = temp;
    }
}

int legalMove(wchar_t **board, int N, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == L'♕') {
            return 0;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == L'♕') {
            return 0;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == L'♕') {
            return 0;
        }
    }
    return 1;
}

void printBoard(wchar_t **board, int N) {
    for (int i = 0; i < 2 * N + 2; i++) {
        wprintf(L"#");
    }
    wprintf(L"\n");
    for (int i = 0; i < N; i++) {
        wprintf(L"#");
        for (int j = 0; j < N; j++) {
            wprintf(L"%2lc", board[i][j]);
        }
        wprintf(L"#\n");
    }
    for (int i = 0; i < 2 * N + 2; i++) {
        wprintf(L"#");
    }
    wprintf(L"\n");
}

void exitGame(wchar_t **board, int N) {
    for (int i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);
    exit(0);
}

int main(){
    setlocale(LC_ALL, ""); 
    srand(time(NULL));
    int N;
    wprintf(L"Benvenuto nella sfida delle N regine. "
            L"In una scacchiera NxN andremo a piazzare N regine.\n"
            L"Nessuna di esse dovrà attacarne un'altra!\n");
    wprintf(L"Scegli il numero N: ");
    scanf("%d", &N);
    wchar_t **board = initializeBoard(N);
    int gameSolved = nQueens(board, N, 0);
    if (gameSolved) {
        wprintf(L"Soluzione trovata.\n");
    } else {
        wprintf(L"Soluzione non trovata.\n");
    }
    exitGame(board, N);
}