#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

#define MAX_EGGS 100
#define MAX_FLOORS 100
#define INF 1000000000

int memo[MAX_EGGS][MAX_FLOORS];

int 
eggDrop(int n, int k)
{    
    if (k == 0)
        return (0); 
    if (k == 1)
        return (1); 
    if (n == 1)
        return (k); 

    if (memo[n][k] > -1) 
        return (memo[n][k]); 

    int ans = INF, h;
    
    for (h = 1; h <= k; ++h)
        ans = min(ans, max(eggDrop(n - 1, h - 1), eggDrop(n, k - h)));

    return (memo[n][k] = ans + 1); 
}

int 
main()
{    
    memset(memo, -1, sizeof(memo));

    int n, k;
    printf("Enter number of eggs: ");
    scanf("%d", &n);
    printf("Enter number of floors: ");
    scanf("%d", &k);

    printf("Minimum Number of attempts required in Worst case = %d \n", eggDrop(n,k));

    return (0);
}
