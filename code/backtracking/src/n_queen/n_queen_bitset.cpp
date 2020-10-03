///GIVES TOTAL NUMBER OF POSSIBLE WAYS TO SOLVE N QUEEN PROBLEM USING BITSET
// Part of Cosmos by OpenGenus Foundation
#include <iostream>
#include <bitset>
using namespace std;

bitset<30> column, diag1, diag2;

void solveNQueen(int r, int n, int &ans)
{
    if (r == n)
    {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
        if (!column[c] && !diag1[r - c + n - 1] && !diag2[r + c])
        {
            column[c] = diag1[r - c + n - 1] = diag2[r + c] = 1;
            solveNQueen(r + 1, n, ans);
            //backtrack
            column[c] = diag1[r - c + n - 1] = diag2[r + c] = 0;
        }

}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    int ans = 0;
    solveNQueen(0, n, ans);
    cout << endl << ans << endl;

    return 0;
}
