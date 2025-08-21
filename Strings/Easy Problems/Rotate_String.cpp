/*

796. Rotate String
Solved
Easy
Topics
premium lock icon
Companies
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
669,087/1M
Acceptance Rate
64.3%

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        // int sSize = s.size(), goalSize = goal.size();
        // int found = false;

        // if (sSize != goalSize) return false;
        // if (s == goal) return true;
        // while (found != true) {
        //     char chtr = s[0];
        //     for (int i = 1; i < sSize; i++) {
        //         s[i-1] = s[i];
        //     }
        //     s[sSize-1] = chtr;
        //     if (s == goal) {
        //         return true;
        //     }
        // }

        // return false;

        // if (s.size() != goal.size()) return false;
        // return (s + s).find(goal) != string::npos;

        int sSize = s.size(), goalSize = goal.size();
        if (sSize != goalSize)
            return false;
        if (s == goal)
            return true;

        for (int i = 0; i < sSize; i++) {
            rotate(s.begin(), s.begin() + 1, s.end()); // Rotates in O(N)
            if (s == goal)
                return true;
        }

        return false;
    }
};
