/* Name: Mohit Khare
 * B.Tech 2nd Year
 * Computer Science and Engineering
 * MNNIT Allahabad
 */
#include <cstdio>
#include <climits>
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

typedef long long int ll;

#define mod 1000000007
const int maxn = 1e5 + 1;

void build(ll segtree[], ll arr[], int low, int high, int pos)
{
    if (low == high)
    {
        segtree[pos] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(segtree, arr, low, mid, 2 * pos + 1);
    build(segtree, arr, mid + 1, high, 2 * pos + 2);
    segtree[pos] = min(segtree[2 * pos + 2], segtree[2 * pos + 1]);
}

ll query(ll segtree[], ll arr[], int low, int high, int qs, int qe, int pos)
{
    if (qe < low || qs > high)
        return LLONG_MAX;
    if (qs <= low && high <= qe)
        return segtree[pos];
    int mid = (low + high) / 2;
    ll left = query(segtree, arr, low, mid, qs, qe, 2 * pos + 1);
    ll right = query(segtree, arr, mid + 1, high, qs, qe, 2 * pos + 2);
    return min(right, left);
}
int main()
{
    int n, m;
    printf("Input no of input elements and no. of queries\n");
    scanf("%d %d", &n, &m);
    ll segtree[4 * n], arr[n];
    printf("Input Array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    build(segtree, arr, 0, n - 1, 0);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        printf("Enter range - l and r\n");
        scanf("%d %d", &l, &r);
        l--; r--;
        printf("Result is :%lld\n", query(segtree, arr, 0, n - 1, l, r, 0));
    }
    return 0;
}

/* Test Case
 *
 * 5 2
 * Input Array elements
 * 3 4 2 1 5
 * 1 2
 * Result is :3
 * 2 5
 * Result is :1
 *
 */
