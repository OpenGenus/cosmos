#include <iostream>
#include <math.h>

using namespace std;

typedef struct VEB
{
    int u;
    int min, max;
    int count;
    struct VEB *summary, **cluster;
} VEB;

int high(int x, int u)
{
    return (int)(x / (int) sqrt(u));
}

int low(int x, int u)
{
    return x % (int) sqrt(u);
}

int VEBmin(VEB*V)
{
    return V->min;
}

int VEBmax(VEB*V)
{
    return V->max;
}

VEB* insert(VEB*V, int x, int u)
{
    if (!V)
    {
        V = (VEB*) malloc(sizeof(VEB));
        V->min = V->max = x;
        V->u = u;
        V->count = 1;
        if (u > 2)
        {
            V->summary = NULL;
            V->cluster = (VEB**) calloc(sqrt(u), sizeof(VEB*));
        }
        else
        {
            V->summary = NULL;
            V->cluster = NULL;
        }
    }
    else if (V->min == x || V->max == x)
        V->count = 1;
    else
    {
        if (x < V->min)
        {
            if (V->min == V->max)
            {
                V->min = x;
                V->count = 1;
                return V;
            }
        }
        else if (x > V->max)
        {
            int aux = V->max;
            V->max = x;
            x = aux;
            V->count = 1;
            if (V->min == x)
                return V;
        }
        if (V->u > 2)
        {
            if (V->cluster[high(x, V->u)] == NULL)
                V->summary = insert(V->summary, high(x, V->u), sqrt(V->u));
            V->cluster[high(x, V->u)] =
                insert(V->cluster[high(x, V->u)], low(x, V->u), sqrt(V->u));
        }
    }
    return V;
}

VEB* deleteVEB(VEB*V, int x)
{
    if (V->min == V->max)
    {
        free(V);
        return NULL;
    }
    else if (x == V->min || x == V->max)
    {
        if (!--V->count)
        {
            if (V->summary)
            {
                int cluster = VEBmin(V->summary);
                int new_min = VEBmin(V->cluster[cluster]);
                V->min = cluster * (int) sqrt(V->u) + new_min;
                V->count = V->cluster[cluster]->count;
                (V->cluster[cluster])->count = 1;
                if ((V->cluster[cluster])->min == (V->cluster[cluster])->max)
                    (V->cluster[cluster])->count = 1;
                V->cluster[cluster] = deleteVEB(V->cluster[cluster], new_min);
                if (V->cluster[cluster] == NULL)
                    V->summary = deleteVEB(V->summary, cluster);
            }
            else
            {
                V->min = V->max;
                V->count = 1;
            }
        }
    }
    else
    {
        V->cluster[high(x, V->u)] = deleteVEB(V->cluster[high(x, V->u)], low(x, V->u));
        if (V->cluster[high(x, V->u)] == NULL)
            V->summary = deleteVEB(V->summary, high(x, V->u));
    }
    return V;
}

int elements(VEB*V, int x)
{
    if (!V)
        return 0;
    else if (V->min == x || V->max == x)
        return V->count;
    else
    {
        if (V->cluster)
            return elements(V->cluster[high(x, V->u)], low(x, V->u));
        else
            return 0;
    }
}

void printVEB(VEB*V, int u)
{
    for (int i = 0; i < u; ++i)
        printf("VEB[%d] = %d\n", i, elements(V, i));
}

int main()
{
    int u = 4;
    int sqrt_u = sqrt(u);
    VEB* V = NULL;

    if (sqrt_u * sqrt_u != u)
    {
        printf("Invalid 'u' : Must be a perfect square\n");
        return 0;
    }

    V = insert(V, 0, u);
    V = insert(V, 1, u);
    V = insert(V, 2, u);

    printVEB(V, u);
    printf("\n\n");

    V = deleteVEB(V, 0);
    V = deleteVEB(V, 1);

    printVEB(V, u);
    return 0;
}
