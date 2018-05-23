#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

string strSub(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    for (int i = 0; i < n2; i++)
    {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);
        carry = 0;
        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    string s;
    string c;
    cout << "Enter Number One" << endl;
    cin >> s;
    cout << "Enter Number Two" << endl;
    cin >> c;
    cout << "Subtraction Result: " << strSub(s, c) << endl;
    return 0;
}
