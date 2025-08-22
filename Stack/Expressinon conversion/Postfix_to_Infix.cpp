/*

================== Postfix to Infix Conversion  ================== 

Problem:
Given a postfix expression, convert it into its equivalent infix expression.

Definitions:
- Postfix: Operands before operator (e.g., AB+).
- Infix: Operand1 Operator Operand2 (e.g., A+B).

Approach:
1. Traverse the postfix expression from left to right.
2. If operand → push to stack.
3. If operator → pop two operands (operand1, operand2),
   form "(operand2 operator operand1)", and push back.
4. At the end, the stack contains the infix expression.

Operators allowed: +, -, *, /, %, ^  
Operands: [a-z], [A-Z]

Example:
Input:   ab*c+  
Output:  ((a*b)+c)  

Steps:
- Read 'a' → push  
- Read 'b' → push  
- Read '*' → pop b, a → form (a*b) → push  
- Read 'c' → push  
- Read '+' → pop c, (a*b) → form ((a*b)+c) → push  

Complexity:
- Time: O(n)
- Space: O(n)

| Postfix Expression | Infix Expression    |
|--------------------|---------------------|
| AB+                | (A+B)              |
| ABC+*              | (A*(B+C))          |
| ab*c+              | ((a*b)+c)          |
| ABC/-              | ((A-(B/C)))        |
| abcd+^*            | (a*(b^(c+d)))      |
*/



#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

// scan form left to right
// operand B operator operand A

class Solution {
private:
    string convertToExp(string operand2, string optr, string operand1) {
        string temp = "";
        
        temp += '(';
        temp += operand2;
        temp += optr;
        temp += operand1;
        temp += ')';
        
        return temp;
    }
// private section ends here    
public:
    string postToInfix(string exp) {
        string ans = "";
        stack <string> st;
       
        for (auto ch: exp) {
            if (isspace(ch)) continue;
            if(isalnum(ch)) {
                string operand(1, ch);     // converting char to string bcs stack have string data types
                st.push(operand);
            }
            else {
                string operand1 = st.top(); st.pop();
                string operand2 = st.top(); st.pop();
                string optr(1, ch);
                
                string result = convertToExp(operand2, optr, operand1);
                st.push(result);
            }    
        }
        
        ans += st.top(); st.pop();
        
        return ans;
    }
};