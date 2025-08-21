/*

1781. Sum of Beauty of All Substrings
Solved
Medium
Topics
premium lock icon
Companies
Hint
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
135,008/187.8K
Acceptance Rate
71.9%


*/


#include <bits/stdc++.h>
using namespace std;




class Solution {
private:
    int findbeauty(const string& copy) {
        vector<int> freq(26, 0); // Frequency array for 'a' to 'z'
        // Count frequencies
        for (char c : copy) {
            freq[c - 'a']++;
        }

        // Find max and min frequency
        int maxFreq = 0, minFreq = INT_MAX;

        for (int f : freq) {
            if (f > 0) { // Only consider characters that appear in the substring
                maxFreq = max(maxFreq, f);
                minFreq = min(minFreq, f);
            }
        }

        return maxFreq - minFreq;
    }

public:
    int beautySum(string s) {
        int ans = 0, n = s.size();
        // Generate all substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string copy = s.substr(i, j - i + 1); // Correct substring generation
                ans += findbeauty(copy);
            }
        }

        return ans;
    }
};