/*

14. Longest Common Prefix
Solved
Easy
Topics
premium lock icon
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
4,838,959/10.5M
Acceptance Rate
46.0%

*/



#include <bits/stdc++.h>
using namespace std;


// tc = O(n) * o(nlogn)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int strSize = strs.size();
        string s1 = strs[0], s2 = strs[strSize-1];
        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        string ans = "";

        if (strs.empty()) return "";
        if (strSize == 1) return strs[0];
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                ans += s1[i];
                i++;
                j++;
            } 
            else {
                break;
            }
        }

        return ans;
    }
};