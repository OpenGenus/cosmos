/* 
 * 
 * Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Solution Description: 
 * 	Sliding Window Approach:
 * 	We take two pointers i (left pointer) and j (right pointer). Then we 
 *  widen our window on the right side at each step (by incrementing j).
 * 	Whenever s[j] has been previously visited, we move the left pointer over
 *  to the just right of the last visited index of (s[j]), so that all 
 *  characters in the window from i to j are unique again. We do a comparison
 *  between	the current best and the length of the window (i - j + 1), and
 *  update our solution accordingly.
 * Time Complexity: O(N)
 * 
 */ 

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // Map each character to its last visited index in s
        unordered_map<char, int> char_to_index;
        int best_len = 0;
        for (int i = 0, j = 0; j < n; j++)
        {
			// Update i if s[j] has been seen before
            if (char_to_index.find(s[j]) != char_to_index.end())
                i = max(i, char_to_index[s[j]] + 1);

            // Length of window = j - i + 1
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
