#include <bits/stdc++.h>
using namespace std;

// number of total nodes
#define N 5
#define INF INT_MAX

class Node
{
public:
    vector<pair<int, int>> path;
    int matrix_reduced[N][N];
    int cost;
    int vertex;
    int level;
};

Node* newNode(int matrix_parent[N][N], vector<pair<int, int>> const &path,int level, int i, int j)
{
    Node* node = new Node;
    node->path = path;
    if (level != 0)
        node->path.push_back(make_pair(i, j));
    memcpy(node->matrix_reduced, matrix_parent,
        sizeof node->matrix_reduced);
    for (int k = 0; level != 0 && k < N; k++)
    {
        node->matrix_reduced[i][k] = INF;
        node->matrix_reduced[k][j] = INF;
    }

    node->matrix_reduced[j][0] = INF;
    node->level = level;
    node->vertex = j;
    return node;
}

void reduce_row(int matrix_reduced[N][N], int row[N])
{
    fill_n(row, N, INF);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] < row[i])
                row[i] = matrix_reduced[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] != INF && row[i] != INF)
                matrix_reduced[i][j] -= row[i];
}

void reduce_column(int matrix_reduced[N][N], int col[N])
{
    fill_n(col, N, INF);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] < col[j])
                col[j] = matrix_reduced[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (matrix_reduced[i][j] != INF && col[j] != INF)
                matrix_reduced[i][j] -= col[j];
}

int cost_calculation(int matrix_reduced[N][N])
{
    int cost = 0;

    int row[N];
    reduce_row(matrix_reduced, row);

    int col[N];
    reduce_column(matrix_reduced, col);

    for (int i = 0; i < N; i++)
        cost += (row[i] != INT_MAX) ? row[i] : 0,
            cost += (col[i] != INT_MAX) ? col[i] : 0;

    return cost;
}

void printPath(vector<pair<int, int>> const &list)
{
    for (int i = 0; i < list.size(); i++)
        cout << list[i].first + 1 << " -> "
             << list[i].second + 1 << endl;
}

class comp {
public:
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};

int solve(int adjacensyMatrix[N][N])
{
    priority_queue<Node*, std::vector<Node*>, comp> pq;
    vector<pair<int, int>> v;
    Node* root = newNode(adjacensyMatrix, v, 0, -1, 0);
    root->cost = cost_calculation(root->matrix_reduced);
    pq.push(root);
    while (!pq.empty())
    {
        Node* min = pq.top();
        pq.pop();
        int i = min->vertex;
        if (min->level == N - 1)
        {
            min->path.push_back(make_pair(i, 0));
            printPath(min->path);
            return min->cost;
        }

        for (int j = 0; j < N; j++)
        {
            if (min->matrix_reduced[i][j] != INF)
            {
                Node* child = newNode(min->matrix_reduced, min->path,
                    min->level + 1, i, j);

                child->cost = min->cost + min->matrix_reduced[i][j]
                            + cost_calculation(child->matrix_reduced);

                pq.push(child);
            }
        }

        delete min;
    }
}

int main()
{
    int adjacensyMatrix[N][N] =
    {
        { INF, 20, 30, 10, 11 },
        { 15,  INF, 16,  4,  2 },
        { 3,   5,  INF, 2,  4 },
        { 19,   6,   18,   INF, 3 },
        { 16,   4,   7,   16, INF }
    };

    cout << "\nCost is " << solve(adjacensyMatrix);

    return 0;
}
