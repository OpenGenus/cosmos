#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

set<string> s;

void permutation(string a, int i = 0)
{
    if (a[i] == '\0')
    {
        // cout << a << endl;
        s.insert(a);
        return;
    }
    for (int j = i; a[j] != '\0'; j++)
    {
        swap(a[i], a[j]);
        permutation(a, i + 1);
        swap(a[i], a[j]);
    }
}

int main()
{
    string a;
    cout << "Enter any string : ";
    cin >> a;

    permutation(a);

    set<string>::iterator i;

    for (i = s.begin(); i != s.end(); i++)
        cout << *i << endl;

    return 0;
}
