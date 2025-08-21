/*

242. Valid Anagram
Solved
Easy
Topics
premium lock icon
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
5,132,685/7.7M
Acceptance Rate
67.0%

*/


#include <bits/stdc++.h>
using namespace std;

// tc = o(n) + o(m) + o(freq.size)
// sc= o(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) return false;
        if (n == 1 && m == 1) {
            if (s[0] == t[0]) return true;
            else return false;
        }

        vector <int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) return false;
        }
        
        return true;
    }
};


/*
// tc = o(nlogn)
// sc= o(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) return false;
        if (n == 1 && m == 1) {
            if (s[0] == t[0]) return true;
            else return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i])
                return false;
        }

        return true;
    }
};
*/