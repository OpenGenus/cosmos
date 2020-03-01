#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> char_to_index;
        int best_len = 0;
        for (int i = 0, j = 0; j < n; j++)
        {
            if (char_to_index.find(s[j]) != char_to_index.end()){
                i = max(i, char_to_index[s[j]] + 1);
            }
            best_len = max(j - i + 1, best_len);
            char_to_index[s[j]] = j;
        }
        return best_len;
    }
};


int main()
{
	int T = 3;
	string testCases[] = {"abcabcbb", "bbbbb", "pwwkew"};
	for (int i = 0; i < T; i++)
	{
		int sol = Solution::lengthOfLongestSubstring(testCases[i]);
		cout << "String: " << testCases[i] << " | Solution: " << sol << endl;
	}
	return 0;
}
