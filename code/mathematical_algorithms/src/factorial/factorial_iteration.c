#include <stdio.h>
#include <stdlib.h>

long long factorial(int n);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: factorial_iteration n\n");
        return (1);
    }
    if (atoi(argv[1]) == 0) {
        printf("Arg n most bigger then 0\n");
        return (1);
    }
    printf("Ans: %lli\n", factorial(atoi(argv[1])));
}

long long factorial(int n)
{
    long long ans = 1;
  
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}
