#include <iostream>
#include <ctime>

#define N 8

unsigned t0, t1;

using namespace std;

double solveKTUtil(int x, int y, int movei, double sol[N][N],
                int xMove[], int yMove[]);

int isSafe(int x, int y, double sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N
            && sol[x][y] == -1);
}

double horse() {
    //clock_t tStart = clock();
    time_t start, finish;
    double sol[N][N];
    time(&start);
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    sol[0][0] = 0;
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0) {
        cout << "no hay solucion";
    }
    time(&finish);
    double time = ((double)difftime(finish, start)*1000)/CLOCKS_PER_SEC;
    return time;
}

double solveKTUtil(int x, int y, int movei, double sol[N][N],
                int xMove[8], int yMove[8])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    for (k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove)
                == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
