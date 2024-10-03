// part of cosmos by opengenus foundation

#include <iostream>
#include <algorithm>   // used for sort()
using namespace std;

bool isLapindrome(string str)
{
    int mid = str.length() / 2;
    int delim = (str.length() % 2) == 0 ? mid : mid + 1;

    string first_half = str.substr(0, mid);
    string second_half = str.substr(delim);

    sort(first_half.begin(), first_half.end());
    sort(second_half.begin(), second_half.end());

    return first_half == second_half;
}


int main()
{
    string test_case;
    cout << "Input the string to be checked" << endl;
    cin >> test_case;
    if (isLapindrome(test_case))
        cout << test_case << "is a lapindrome.\n";
    else
        cout << test_case << "is not a lapindrome.\n";

    return 0;
}
