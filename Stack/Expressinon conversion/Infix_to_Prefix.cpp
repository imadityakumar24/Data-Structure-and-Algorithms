/*

==================  Infix to Prefix Conversion  ================== 

Problem:
Given an infix expression (a op b), convert it into a prefix expression (op a b).

Definitions:
- Infix: Operator between operands (e.g., A + B).
- Prefix: Operator before operands (e.g., +AB).

Approach:
1. Reverse the infix expression.
2. Replace '(' with ')' and ')' with '('.
3. Convert the modified expression into postfix.
4. Reverse the postfix → this gives prefix.

Operator Precedence:
^ > * = / > + = -
(assume all operators are left-associative, ignoring right associativity of ^)

Examples:
Input:  (A - B/C) * (A/K-L)
Output: *-A/BC-/AKL

Input:  A*(B+C)/D
Output: /*A+BCD

Input:  (a+b)*(c+d)
Output: *+ab+cd

Complexity:
- Time: O(n)
- Space: O(n)


| Infix Expression     | Prefix Expression  |
|----------------------|--------------------|
| A + B                | +AB               |
| A + B * C            | +A*BC             |
| (A + B) * C          | *+ABC             |
| A * (B + C) / D      | /*A+BCD           |
| (A + B) * (C - D)    | *+AB-CD           |
| A + B - C * D        | -+AB*CD           |
| (A + B) ^ C          | ^+ABC             |
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

    // Helper to convert infix to postfix (used after reversing)
    string infixToPostfix(string& s) {
        string result;
        stack<char> st;

        for (char ch : s) {
            if (isspace(ch)) continue;

            if (isalnum(ch)) {
                result += ch;
            }
            else if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else {
                while (!st.empty() && st.top() != '(' &&
                       precedence(ch) <= precedence(st.top())) {
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }

public:
    // Main function: infix to prefix
    string infixToPrefix(string s) {
        // Step 1: Reverse infix
        reverse(s.begin(), s.end());

        // Step 2: Replace '(' with ')' and vice versa
        for (char& ch : s) {
            if (ch == '(') ch = ')';
            else if (ch == ')') ch = '(';
        }

        // Step 3: Convert to postfix
        string postfix = infixToPostfix(s);

        // Step 4: Reverse postfix → prefix
        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};
