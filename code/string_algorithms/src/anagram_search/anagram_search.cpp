/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>

#include <unordered_map>
#include <unordered_set>
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
bool isAnagram(const string& s1, const string& s2)
{
    unordered_map<char, int> charCount1, charCount2;
    unordered_set<char> allChars;

    for (char c : s1)
    {
        c = tolower(c);
        if (!iswspace(c))
        {
            charCount1[c]++;
            allChars.insert(c);
        }
    }

    for (char c : s2)
    {
        c = tolower(c);
        if (!iswspace(c))
        {
            charCount2[c]++;
            allChars.insert(c);
        }
    }

    for (auto it = allChars.begin(); it != allChars.end(); it++)
    {
        char c = *it;
        if (charCount1[c] != charCount2[c])
            return false;
    }

    return true;
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
