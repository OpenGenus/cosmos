/// Part of Cosmos by OpenGenus Foundation
#include <stdio.h>
#include <vector>
void backtrack(int level);
void print_sol(int length);
std::vector<int> solution;
int N, S = 0;
int solsFound = 0;
int main()
{
    scanf("%d", &N);
    solution.reserve(N + 1);
    solution[0] = 1;
    backtrack(1);
    return 0;
}
void backtrack(int level)
{
    if (S == N)
        print_sol(level - 1);
    else
        for (int i = solution[level - 1]; i <= N - S; i++)
        {
            solution[level] = i;
            S += i;
            backtrack(level + 1);
            S -= i;
        }
}
void print_sol(int length)
{
    printf("SOLUTION %d\n", ++solsFound);
    printf("%d=", N);
    for (int i = 1; i <= length - 1; i++)
        printf("%d+", solution[i]);
    printf("%d\n", solution[length]);
}
