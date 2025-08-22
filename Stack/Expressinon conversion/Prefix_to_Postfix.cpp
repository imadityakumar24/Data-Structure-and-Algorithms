
/*
 
==================  Prefix to Postfix Conversion  ==================

Problem:
Given a prefix expression, convert it into its equivalent postfix expression.

Definitions:
- Prefix: Operator before operands (e.g., *+AB-C).
- Postfix: Operands before operator (e.g., AB+C-).

Approach:
1. Traverse the prefix expression from right to left.
2. If operand → push to stack.
3. If operator → pop two operands from stack, form "operand1 operand2 operator" and push back.
4. At the end, the stack contains the postfix expression.

Operators allowed: +, -, *, /, %, ^  
Operands: [a-z], [A-Z]  

Example:
Input:  *-A/BC-/AKL  
Output: ABC/-AK/L-*  

Complexity:
- Time: O(n)
- Space: O(n)


| Prefix Expression | Postfix Expression |
|-------------------|--------------------|
| +AB               | AB+                |
| *+ABC             | AB+C*              |
| *-A/BC-/AKL       | ABC/-AK/L-*        |
| ^+ABC             | AB+C^              |
| -+AB*CD           | AB+CD*-            |


*/



#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

// postfix expressin
// operand-1 operand-2 operator 

class Solution {
private:
    string convertToExp(string operand1, string operand2, string optr) {
        string temp = "";
        
        temp += operand1;
        temp += operand2;
        temp += optr;
        
        return temp;
    }
// private section ends here     
public:
    string preToPost(string pre_exp) {
       int n = pre_exp.size();   
       string ans = "";
       stack <string> st;
       
        for (auto ch = pre_exp.rbegin(); ch != pre_exp.rend(); ++ch) {
            if (isspace(*ch)) continue;
            if(isalnum(*ch)) {
                string operand(1, *ch);     // converting char to string bcs stack have string data types
                st.push(operand);
            }
            else {
                string operand1 = st.top(); st.pop();
                string operand2 = st.top(); st.pop();
                string optr(1, *ch);
                
                string result = convertToExp(operand1, operand2, optr);
                st.push(result);
            }    
        }
        
        ans += st.top(); st.pop();
        
        return ans;
    }
};