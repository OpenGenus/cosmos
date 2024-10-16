#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_N 21
#define MAX_E (MAX_N * (MAX_N - 1)) / 2
#define MAX_MASK (1 << MAX_N)
#define MAX_W 100
#define NB_ITER 20

int N, fullmask, dp[MAX_N][MAX_MASK];
int G[MAX_N][MAX_N];

/* Result of PVC is stored here. Each element correspond to a
   vertice and points to the next vertice in the cycle. */
int cycle[MAX_N];

/* Used to optimize bits operations */
const int BITS_MAP[] = {
    32, 0, 1, 26, 2, 23, 27, 0, 3, 16, 24, 30, 28, 11,
    0, 13, 4, 7, 17, 0, 25, 22, 31, 15, 29, 10, 12, 6,
    0, 21, 14, 9, 5, 20, 8, 19, 18};

/*
 * u is the current vertex.
 * mask is the current mask.
 *
 * Return the cost of the minimum path that goes from u
 * to 0 without revisiting already visited vertices.
 * Visited vertices are marked with 1 in mask. 
 */
int DFS(int u, int mask)
{
    if (mask == fullmask)
        return dp[u][mask] = G[u][0];

    if (dp[u][mask] != -1)
        return dp[u][mask];

    int v, _v, tmp, cpm = ~mask & fullmask;
    dp[u][mask] = INT_MAX;

    while (cpm != 0) {
        _v = cpm & -cpm;
        cpm -= _v;
        v = BITS_MAP[_v % 37];

        tmp = DFS(v, mask | _v);

        if (tmp + G[u][v] < dp[u][mask])
            dp[u][mask] = tmp + G[u][v];
    }

    return dp[u][mask];
}

/*
 * Return the weight of the optimal cycle, and 
 * fill the array cycle (see above).
 */
int PVC()
{
    int i, j, ret;

    /* Init DP table */
    fullmask = (1 << N) - 1;

    for (i = 0; i < N; ++i)
        for (j = 0; j <= fullmask; ++j)
            dp[i][j] = -1;

    /* Fill DP table */
    ret = DFS(0, 1);

    /* Look for the solution */
    int u = 0, v = 0, mask = 1, nmask, w, x;

    while (mask != fullmask) {
        w = INT_MAX;
        for (x = 0; x < N; ++x) {
            if ((mask & (1 << x)) != 0)
                continue;

            nmask = mask | (1 << x);
            if (dp[x][nmask] + G[u][x] < w) {
                v = x;
                w = dp[x][nmask] + G[u][x];
            }
        }

        mask |= (1 << v);
        cycle[u] = v;
        u = v;
    }

    cycle[u] = 0;
    return ret;
}

int main()
{
    srand(time(NULL));

    int i, j, cpt;
    double time_spent;
    clock_t begin, end;

    /* Execute some benchmarks on different randomly initialized graphs */
    for (N = 3; N <= MAX_N; ++N) {
        time_spent = 0.f;

        for (cpt = 0; cpt < NB_ITER; ++cpt) {
            for (i = 0; i < N; ++i) {
                for (j = 0; j < N; ++j) {
                    G[i][j] = rand() % MAX_W + 1;
                    G[j][i] = G[i][j];
                }

                G[i][i] = INT_MAX;
            }

            begin = clock();
            PVC();
            end = clock();

            time_spent += ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
        }

        printf("%d %lf\n", N, time_spent / NB_ITER);
    }

    return 0;
}
