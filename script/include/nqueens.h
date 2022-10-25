#include <iostream>
#include <ctime>
#define M 7

unsigned t2, t3;

using namespace std;

bool isSafe(int board[M][M], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < M; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[M][M], int col)
{
    if (col >= M)
        return true;

    for (int i = 0; i < M; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

double nqueens() {
    clock_t tStart2 = clock();
    time_t start, finish;
    int board[M][M] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
    }
    double time = ((double)difftime(finish, start)*1000)/CLOCKS_PER_SEC;
    return time;
}
