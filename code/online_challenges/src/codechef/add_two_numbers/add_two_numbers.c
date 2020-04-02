#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = a + b;
        printf("%d\n", ans);
        --t;
    }
    return 0;
}
