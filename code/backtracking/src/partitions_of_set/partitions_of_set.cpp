/// Part of Cosmos by OpenGenus Foundation
#include <stdio.h>
#include <vector>
void backtrack(int level);
void print_sol();
std::vector<int> v;
std::vector<int> solution;
int maxfromSol = 0;
int N;
int solsFound = 0;
int main()
{
    scanf("%d", &N);
    v.reserve(N + 1);
    solution.reserve(N + 1);
    for (int i = 1; i <= N; i++)
        scanf("%d", &v[i]);
    backtrack(1);
    return 0;
}
void backtrack(int level)
{
    if (level == N + 1)
        print_sol();
    else
    {
        for (int i = 1; i <= maxfromSol; i++)
        {
            solution[level] = i;
            backtrack(level + 1);
        }
        solution[level] = maxfromSol + 1;
        maxfromSol++;
        backtrack(level + 1);
        maxfromSol--;
    }
}
void print_sol()
{
    printf("SOLUTION %d\n", ++solsFound);
    for (int i = 1; i <= maxfromSol; i++)
    {
        printf("Partition %d:", i);
        for (int j = 1; j <= N; j++)
            if (solution[j] == i)
                printf("%d ", v[j]);

        printf("\n");
    }
}
