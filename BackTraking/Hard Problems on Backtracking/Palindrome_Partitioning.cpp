/*

131. Palindrome Partitioning
Solved
Medium
Topics
premium lock icon
Companies
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,238,089/1.7M
Acceptance Rate
73.2%

*/




#include <bits/stdc++.h>
using namespace std;


// TC = O(N∗2^N)
// SC = O(n)      → recursion + temporary vector (auxiliary space)
//      O(n × 2ⁿ) → total space including result storage
 
class Solution {

    bool isPalindrome (string s) {
        int i = 0, j = s.length()-1;
        while (i < j) {
            if (s[i++] != s[j--]) 
                return false;
        }
        return true;
    }

    void solve (int idx, string &s, vector <string> &str,  vector<vector<string>> &result) {

        if (idx == s.size()) {
            result.push_back(str);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string temp = s.substr(idx, i-idx+1);
            if (isPalindrome(temp)) {
                str.push_back(temp);
                solve (i+1, s, str, result);
                str.pop_back();
            }
        }

    }

public:
    vector<vector<string>> partition (string s) {
        vector<vector<string>> result;
        if (s.empty()) return {};
        vector <string> str;
        solve (0, s, str, result);
        return result;
    }
};

