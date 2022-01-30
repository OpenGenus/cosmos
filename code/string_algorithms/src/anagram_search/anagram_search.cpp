/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *  Checks if two strings are anagrams of each other, ignoring any whitespace.
 *
 *  Create maps of the counts of every character in each string.
 *  As well as keep a set of all characters used in both strings.
 *
 *  Check to ensure every unique character is used in both strings the
 *      same number of times.
 */

vector<int> getMap(const string& s) 
{
    vector<int> m(26, 0);
    for(char c : s) 
    {
        if(c != ' ') 
        {
            c = tolower(c);
            m[c - 'a']++;
        }
    }
    return m;
}
bool isAnagram(const string& s1, const string& s2) 
{
    vector<int> m1 = getMap(s1);
    vector<int> m2 = getMap(s2);
    return m1 == m2;
}
int main()
{
    cout << isAnagram("anagram", "not a gram") << endl; // false
    cout << isAnagram("anagram", "na a marg") << endl;  // true
    cout << isAnagram("William Shakespeare", "I am \t a weakish speller") << endl; // true
    cout << isAnagram("Madam Curie", "Radium came") << endl; // true
    cout << isAnagram("notagram", "notaflam") << endl; // false

    return 0;
}
