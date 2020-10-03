/*
 * Part of Cosmos by OpenGenus Foundation
 * finding longest common substring between two strings by dynamic programming
 */

#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int longestCommonSubString(string s1, string s2)
{
    int T[600][600];                            //array length can be adjusted by string length of vector can be used
    memset(T, 0, sizeof(T));                    //intialising T to zero
    int maximum = 0;

    //filling by recurrence relation
    for (int i = 1; i <= (int)s1.length(); i++)
    {
        for (int j = 1; j <= (int)s2.length(); j++)
            if (s1[i - 1] == s2[j - 1])                         //matching of characters
            {
                T[i][j] = T[i - 1][j - 1] + 1;
                if (maximum < T[i][j])
                    maximum = T[i][j];
            }
    }
    return maximum;
}

//longest common substring
int main()
{
    string s1, s2;

    //standard input stream
    //cin >> s1 >> s2;
    s1 = "abcdedwwop";
    s2 = "abeeedcedwcdedop";
    int maximum = longestCommonSubString(s1, s2);
    cout << "Length of longest substring = ";
    cout << maximum << "\n";

    //maximum length substring above -- "cded" -- length = 4
}
