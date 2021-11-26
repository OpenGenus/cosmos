/*

// backtracking | permutations of string | permutations of string stl | C++
// Part of Cosmos by OpenGenus Foundation

*/


// Part of Cosmos by OpenGenus Foundation
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    do
        cout << s << endl;
    while (next_permutation(s.begin(), s.end()));
    return 0;
}
