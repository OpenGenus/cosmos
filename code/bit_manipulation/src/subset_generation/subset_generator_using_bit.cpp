#include <iostream>
#include <cstring>
using namespace std;
typedef long long int ll;

void filter(char *a, int no)
{
    int i = 0;
    while (no > 0)
    {
        (no & 1) ? cout << a[i] : cout << "";
        i++;
        no = no >> 1;
    }
    cout << endl;
}

void generateSub(char *a)
{
    int n = strlen(a);
    int range = (1 << n) - 1;
    for (int i = 0; i <= range; i++)
        filter(a, i);
}
int main()
{
    char a[4] = {'a', 'b', 'c', 'd'};
    generateSub(a);
}
