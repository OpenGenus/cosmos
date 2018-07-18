#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;
        bool ans = next_permutation(s.begin(), s.end());                       // do permutation and store it in string ans
        if(ans == false)                                                        // if there is no permutation possible original and ans will be same
            cout <<"no answer " << endl;
        else
            cout << s << endl;                                                  // else print ans
    }
}
