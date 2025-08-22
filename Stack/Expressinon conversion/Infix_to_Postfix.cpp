/*

==================  Infix to Postfix Conversion  ================== 

Difficulty: Medium
Accuracy: 52.94%
Submissions: 141K+
Points: 4

Problem:
Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

Definitions:
- Infix expression: a op b (operator between operands)
- Postfix expression: a b op (operator after operands)

Operator precedence: 
^ > * = / > + = -
(assume all operators are left-associative, ignoring right associativity of ^)

Examples:
Input:  s = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-

Input:  s = "A*(B+C)/D"
Output: ABC+*D/

Input:  s = "(a+b)*(c+d)"
Output: ab+cd+*

Constraints:
1 ≤ s.length ≤ 30

Expected Complexity:
Time: O(n)
Space: O(n) (stack usage)


| Infix Expression     | Postfix Expression |
|----------------------|--------------------|
| A + B                | AB+               |
| A + B * C            | ABC*+             |
| (A + B) * C          | AB+C*             |
| A * (B + C) / D      | ABC+*D/           |
| (A + B) * (C - D)    | AB+CD-*           |
| A + B - C * D        | AB+CD*-           |
| (A + B) ^ C          | AB+C^             |


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to define operator precedence
    int precedence(char ch) {
        if (ch == '^') return 3;
        if (ch == '*' || ch == '/') return 2;
        if (ch == '+' || ch == '-') return 1;
        return -1;
    }

public:
    // Function to convert infix expression to postfix
    string infixToPostfix(string& s) {
        string result;
        stack<char> st;

        for (char ch : s) {
            if (isspace(ch)) continue;

            // If operand, add to result
            if (isalnum(ch)) {
                result += ch;
            }
            // If opening parenthesis, push to stack
            else if (ch == '(') {
                st.push(ch);
            }
            // If closing parenthesis, pop until '('
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // Remove '('
            }
            // If operator
            else {
                while (!st.empty() && st.top() != '(' && 
                       precedence(ch) <= precedence(st.top())) {
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
