/*

1614. Maximum Nesting Depth of the Parentheses
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3

 

Constraints:

1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
476,523/564.2K
Acceptance Rate
84.5%

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int count= 0, maxDepth = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                count++;
                maxDepth = max(maxDepth, count);
            }
            if (s[i] == ')'){
                count--; 
            }
        }

        return maxDepth;
    }
};