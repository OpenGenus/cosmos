#include <iostream>
#include <cstring>
using namespace std;

int BIT[101000], A[101000], n;

int query(int i)
{
    int ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += BIT[i];
    return ans;
}
void update(int i)
{
    for (; i <= n; i += i & (-i))
        BIT[i]++;
}
int main()
{
    int ans, i;
    while (cin >> n and n)
    {
        memset(BIT, 0, (n + 1) * (sizeof(int)));
        for (int i = 0; i < n; i++)
            cin >> A[i];
        ans = 0;
        for (i = n - 1; i >= 0; i--)
        {
            ans += query(A[i] - 1);
            update(A[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
