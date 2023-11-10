#include <iostream>
#include <vector>

const int MAX = 2000000000;
const int MAX_NODES = 20;

int optimalWayLength[1 << MAX_NODES][MAX_NODES];

bool was[1 << MAX_NODES][MAX_NODES];

int cameFrom[1 << MAX_NODES][MAX_NODES];

int distances[MAX_NODES][MAX_NODES];

int n;


int findAns (int last, int mask)
{
    if (mask == (1 << last))
        return 0;

    if (was[mask][last])
        return optimalWayLength[mask][last];
    was[mask][last] = true;

    int optimal = MAX;

    for (int next = 0; next < n; next++)
    {
        if (next == last)
            continue;
        if ((mask & (1 << next)) != 0)
        {
            int distance = distances[next][last] + findAns (next, mask ^ (1 << last));
            if (distance < optimal)
            {
                optimal = distance;
                cameFrom[mask][last] = next;
            }
        }
    }

    optimalWayLength[mask][last] = optimal;

    return optimalWayLength[mask][last];
}

int main()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> distances[i][j];

    int optimal = MAX;
    int last = 0;

    for (int start = 0; start < n; start++)
    {
        int distance = findAns (start, (1 << n) - 1);
        if (distance < optimal)
        {
            optimal = distance;
            last = start;
        }
    }

    int mask = (1 << n) - 1;
    std::vector<int> way;

    while (mask != 0)
    {
        way.push_back(last);

        int previous = cameFrom[mask][last];

        mask ^= 1 << last;

        last = previous;
    }

    std::cout << optimal << '\n';
    for (int i = way.size() - 1; i >= 0; i--)
        std::cout << way[i] + 1 << ' ';
}
