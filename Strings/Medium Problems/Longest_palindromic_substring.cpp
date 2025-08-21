/*


5. Longest Palindromic Substring
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
4,076,774/11.2M
Acceptance Rate
36.3%


*/




#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int maxLen = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string copystring = s.substr(i, j - i + 1); // always use j-i+1 for extracting // string don't use j++
                // string copystring = s.substr(i, j++); // wrong
                // string copystring = s.substr(i, j+1); // wrong
                string reversestring = copystring;
                reverse(reversestring.begin(), reversestring.end());

                if (reversestring == copystring) {
                    int length = j - i + 1;
                    if (length > maxLen) { // Update longest palindrome
                        maxLen = length;
                        ans = copystring;
                    }  
                }           
            }
        }

        return ans;
    }
};
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        int n = s.size();

        // Helper function to expand around center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Length of palindrome
        };

        for (int i = 0; i < n; i++) {
            int len1 = expand(i, i);       // Odd-length palindrome
            int len2 = expand(i, i + 1);   // Even-length palindrome
            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2; // Update start position
            }
        }

        return s.substr(start, maxLen);
    }
};
