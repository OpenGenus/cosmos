#include <string>
#include <iostream>

void Zalgo(std::string s, std::string pattern)
{
    using namespace std;
    string k = pattern + "&" + s;

    size_t Z[k.length()]; //Z-array for storing the length of the longest substring
                          //starting from s[i] which is also a prefix of s[0..n-1]
    size_t l = 0, r = 0;
    for (size_t i = 1; i < k.length(); i++)
    {
        if (i > r)
        {
            l = i; r = i;
            while (r < k.length() && k[r] == k[r - l])
                r++;
            Z[i] = r - l;
            r--;
        }
        else
        {
            int p = i - l;
            if (Z[p] < r - i + 1)
                Z[i] = Z[p];
            else
            {
                l = i;
                while (r < k.length() && k[r] == k[r - l])
                    r++;
                Z[i] = r - l;
                r--;
            }
        }
    }
    for (size_t i = 1; i < k.length(); i++)
        if (Z[i] == pattern.length())
            cout << "Found Pattern at " << i - pattern.length() - 1 << endl;

}
int main()
{
    using namespace std;
    string s = "atababatggagabagt";  //original string
    string pattern = "aba";  //pattern to be searched in string
    Zalgo(s, pattern);
    return 0;
}
/*Output:
 * Found Pattern at 2
 * Found Pattern at 4
 * Found Pattern at 12
 */
