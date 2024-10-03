#include <bits/stdc++.h>
using namespace std;
#define int long long int
int merges(int* A, int* L, int lc, int* R, int rc)
{
    int i = 0, j = 0, k = 0, inv = 0;
    while (i < lc && j < rc) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            k++;
            i++;
        }
        else if (R[j] < L[i]) {
            A[k] = R[j];
            k++;
            j++;
            inv = inv + (lc - i);
        }
    }
    while (i < lc) {
        A[k] = L[i];
        k++;
        i++;
    }
    while (j < rc) {
        A[k] = R[j];
        k++;
        j++;
    }
    free(L);
    free(R);
    return inv;
}
int mergesort(int* A, int n)
{
    int inv = 0;
    if (n >= 2) {
        int mid = n / 2;
        int *L, *R;
        L = (int*)malloc(mid * sizeof(int));
        R = (int*)malloc((n - mid) * sizeof(int));
        int i;
        for (i = 0; i < mid; i++)
            L[i] = A[i];
        for (i = mid; i < n; i++)
            R[i - mid] = A[i];
        inv = mergesort(L, mid);
        inv += mergesort(R, n - mid);
        inv += merges(A, L, mid, R, n - mid);
    }
    return inv;
}

main()
{
    int t;
    cin >> t;
    int v = 0;
    int ans[t];
    cin.get();
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int i;
        for (i = 0; i < n; i++)
            cin >> a[i];
        int inv;
        inv = mergesort(a, n);
        cout << inv << "\n";
        //ans[v]=inv;
        v++;
        cin.get();
    }
    /*for(int i=0;i<v;i++)
  cout<<ans[i]<<"\n";*/
}
