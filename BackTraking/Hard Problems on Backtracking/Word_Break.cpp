/*

139. Word Break
Attempted
Medium
Topics
premium lock icon
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,236,968/4.6M
Acceptance Rate
48.8%
Topics

*/


#include <bits/stdc++.h>
using namespace std;

// Giving TLE 
// becase i m not using dp in this
class Solution {

    bool solve(int idx, string &s, unordered_set <string> &st) {
        if (idx == s.size()) {
            return true;
        }
       
        for (int i = idx; i < s.size(); i++) {
            string str = s.substr(idx, i - idx + 1);
            if (st.find(str) != st.end()) {
                if (solve(i + 1, s, st))
                    return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st;
        for (auto str : wordDict) {
            st.insert(str);
        }
        return solve(0, s, st);
    }
};


