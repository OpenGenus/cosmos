#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    scanf("%d %d", & n, & m);
    char * topic[n];
    int topic_i;
    for (topic_i = 0; topic_i < n; ++topic_i)
    {
        topic[topic_i] = (char * ) malloc(1024 * sizeof(char));
        scanf("%s", topic[topic_i]);
    }
    int highest = -1;
    int bestTeam = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int know = 0;
            for (int x = 0; x < m; ++x)
            {
                know += (topic[i][x] == '1' || topic[j][x] == '1') ? 1 : 0;
            }
            if (know > highest)
            {
                highest = know;
                bestTeam = 1;
            }
            else if (know == highest)
            {
                ++bestTeam;
            }
        }
    }
    printf("%d\n%d\n", highest, bestTeam);
    return 0;
}
