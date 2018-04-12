/* Part of Cosmos by OpenGenus Foundation */

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define NUM_V 100005

vector<int> adjList[NUM_V + 5];
int inDegree[NUM_V + 5];
int vertex;

vector<int> toposort()
{
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= vertex; i++)
        // if no incoming degree, add to queue
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // add into toposort result
        result.push_back(front);

        for (size_t i = 0; i < adjList[front].size(); i++)
        {
            int neighbor = adjList[front][i];
            inDegree[neighbor]--;

            // if already no incoming degree, then ready to put in toposort list
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return result;
}

int main()
{


    /* consider following graph
     * 1----->2----->5
     * |     ^^
     * |    / |
     * |   /  |
     * |  /   |
     * v /    |
     * 4----->3
     * one of the solution would be
     * 1 -> 4 -> 3 -> 2 -> 5
     */

    vertex = 5;
    adjList[1].push_back(2);
    adjList[1].push_back(4);
    adjList[2].push_back(5);
    adjList[3].push_back(2);
    adjList[4].push_back(2);
    adjList[4].push_back(3);

    inDegree[1] = 0;
    inDegree[2] = 3;
    inDegree[3] = 1;
    inDegree[4] = 1;
    inDegree[5] = 1;
    vector<int> toposortResult = toposort();

    printf("toposort :");
    for (size_t i = 0; i < toposortResult.size(); i++)
        printf(" %d", toposortResult[i]);
    printf("\n");
}
