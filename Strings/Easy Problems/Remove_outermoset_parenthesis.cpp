/*

==========  1021. Remove Outermost Parentheses   ==========


Solved
Easy
Topics
premium lock icon
Companies
Hint
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
538,188/625.1K
Acceptance Rate
86.1%


*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack <char> st;
        string ans =  "";

        // for (int i = 0; i < n; i++) {
        //     if (st.empty()) {
        //         st.push(s[i]);
        //     }
        //     else {
        //         if (!st.empty()) {
        //             st.pop();
        //             ans += s[i];
        //         }
        //     }
        // }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // Only add '(' if it's not the outermost one
                if (!st.empty()) {
                    ans += s[i];
                }
                st.push(s[i]);
            } 
            else { // s[i] == ')'
                st.pop();
                // Only add ')' if it's not the outermost one
                if (!st.empty()) {
                    ans += s[i];
                }    
            }
        }

        return ans;
    }
};