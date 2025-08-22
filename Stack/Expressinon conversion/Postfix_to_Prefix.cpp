
/*

==================  Postfix to Prefix Conversion  ================== 

Problem:
Given a postfix expression, convert it into its equivalent prefix expression.

Definitions:
- Postfix: Operands before operator (e.g., AB+).
- Prefix: Operator before operands (e.g., +AB).

Approach:
1. Traverse the postfix expression from left to right.
2. If operand → push to stack.
3. If operator → pop two operands (operand2, operand1),
   form "operator operand2 operand1", and push back.
4. At the end, the stack contains the prefix expression.

Operators allowed: +, -, *, /, %, ^  
Operands: [a-z], [A-Z]

Examples:
Input:  ABC/-AK/L-*  
Output: *-A/BC-/AKL  

Input:  ab+  
Output: +ab  

Complexity:
- Time: O(n)
- Space: O(n)

| Postfix Expression | Prefix Expression |
|--------------------|-------------------|
| AB+                | +AB               |
| ABC+*              | *A+BC             |
| ABC/-AK/L-*        | *-A/BC-/AKL       |
| ab+                | +ab               |
| abcd+^*            | *a^b+cd           |


*/


#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

// Prefix expressin
// operator operand-2 operand-1

class Solution {
private:
    string convertToExp(string optr, string operand2, string operand1) {
        string temp = "";
        
        temp += optr;
        temp += operand2;
        temp += operand1;
        
        return temp;
    }
// private section ends here
public:
    string postToPre(string post_exp) {
        int n = post_exp.size();   
        string ans = "";
        stack <string> st;
       
        for (auto ch: post_exp) {
            if (isspace(ch)) continue;
            if(isalnum(ch)) {
                string operand(1, ch);     // converting char to string bcs stack have string data types
                st.push(operand);
            }
            else {
                string operand1 = st.top(); st.pop();
                string operand2 = st.top(); st.pop();
                string optr(1, ch);
                
                string result = convertToExp(optr, operand2, operand1);
                st.push(result);
            }    
        }
        
        ans += st.top(); st.pop();
        
        return ans;
    }
};