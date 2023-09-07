#include <iostream>
#include <vector>



int main()
{
    int n;
    std :: cin >> n;
    int arr[n];
    int sockarr[101] = {};
    for(int i = 0;i < n;++i) cin >> arr[i];
    memset(sockarr,0,101);
    for(int i = 0;i < n;++i)
    {
        sockarr[arr[i]] += 1;
    }
    int pairs = 0;
    for(int i = 0;i < 101;++i)
    {
        pairs += sockarr[i]/2;
    }
    std :: cout << pairs << endl;
    return 0;
}
