
/* A simple C program to create Jaccard’s indices adjusted for differences in species richness across site  */
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <float.h>
#define R 524
#define C 46
#define MAX 100
void main()
{
    time_t toc;
    int M[R][C], B[R][C], S[C];
    int i,j,k, in, un, b;
    float Jaccard[C][C], q;
    FILE *fpi, *fpo;
    time(&toc);                   /* random number seed */
    srand((int)toc);                     /* generate pseudorandom number */
    fpi = fopen("Africa.txt", "r");                     /* open input file (maybe altered) */
    fpo = fopen("foo.txt", "w");                     /* standard output file (ditto) */
    for (i = 0; i < R; i++)                 /* read presence–absence data */
        for (j = 0; j < C; ++j)
            fscanf(fpi, "%d", &M[i][j]);
    for (b = 0; b < MAX; ++b)                             /* initialize Jaccard matrix to zero */
    {
        for (j = 0; j < C; ++j) 
             S[j] = 0;
        for (i = 0; i < C; ++i)
            for (j = 0; j < C; ++j) 
                 Jaccard[i][j] = 0.0;
    i = 0;
    for (i = 0; i < R ; ++i)                            /* obtain species data from input */
    {
        k = (int)((float)(rand()/32767.0*(R-1)));
        for (j = 0; j < C; ++j)
            B[i][j] = M[k][j];
    }
    for (j = 0; j < C; ++j)                             /* sum species */
        for (i = 0; i < R; ++i)
            S[j] += B[i][j];
    for (k = 0; k < C-1; ++k)                         /* calculated Jaccard’s index */
        for (j = k+1; j < C; ++j) 
        {
            in = un = 0;
            for (i = 0; i < R; ++i) 
            {
                un += (B[i][k] || B[i][j]);
                in += (B[i][k] && B[i][j]);
            }
            q = S[k]<S[j] ? (float)S[j]/S[k] :(float)S[k]/S[j];           /* adjust index. . . */
            Jaccard[k][j] = (float)in/un*q*100.0;             /* by diff. richness */
        }
    for (j = 1; j < C; ++j)  /* output adjusted Jaccard’s */
    {
        fprintf(fpo, "\n");
        for (k = 0; k < j; ++k)
            fprintf(fpo, "%.1f ", 100.0-Jaccard[k][j]);
    }
}
