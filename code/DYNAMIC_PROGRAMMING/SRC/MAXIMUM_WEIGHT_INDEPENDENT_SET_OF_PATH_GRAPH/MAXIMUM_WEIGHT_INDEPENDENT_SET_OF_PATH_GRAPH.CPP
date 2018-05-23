#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of vertices of the path graph : ";
    cin >> n;
    int g[n];
    cout << "Enter the vertices of the graph : ";
    for (int i = 0; i < n; i++)
        cin >> g[i];
    int sol[n + 1];
    sol[0] = 0;
    sol[1] = g[0];
    for (int i = 2; i <= n; i++)
        sol[i] = max(sol[i - 1], sol[i - 2] + g[i - 1]);
    cout << "The maximum weighted independent set sum is : " << sol[n] << endl;
    int i = n;
    cout << "The selected verices are : ";
    while (i >= 1)
    {
        if (sol[i - 1] >= sol[i - 2] + g[i - 1])
            i--;
        else
        {
            cout << g[i - 1] << " ";
            i -= 2;
        }
    }
    return 0;
}
