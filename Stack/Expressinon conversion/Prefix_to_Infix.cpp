

/*

==================  Prefix to Infix Conversion  ================== 

Problem:
Given a prefix expression, convert it into its equivalent infix expression.

Definitions:
- Prefix: Operator before operands (e.g., *+AB-C).
- Infix: Operator between operands (e.g., (A+B)*(C-D)).

Approach:
1. Traverse the prefix expression from right to left.
2. If operand → push to stack.
3. If operator → pop two operands from stack, form "(operand1 op operand2)" and push back.
4. At the end, the stack contains the full infix expression.

Operators allowed: +, -, *, /, %, ^  
Operands: [a-z], [A-Z]  

Example:
Input:  *-A/BC-/AKL  
Output: ((A-(B/C))*((A/K)-L))

Complexity:
- Time: O(n)
- Space: O(n)



| Prefix Expression | Infix Expression          |
|-------------------|---------------------------|
| +AB               | (A+B)                     |
| *+ABC             | ((A+B)*C)                 |
| *-A/BC-/AKL       | ((A-(B/C))*((A/K)-L))     |
| ^+ABC             | ((A+B)^C)                 |
| -+AB*CD           | ((A+B)-(C*D))             |


*/


#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

// infix expressin
// operand-1 operator operand-2

class Solution {
private:
    string convertToExp(string operand1, string operand2, string optr) {
        string temp = "";
        
        temp += '(';
        temp += operand1;
        temp += optr;
        temp += operand2;
        temp += ')';
        
        return temp;
    }
// private section ends here    
public:
    string preToInfix(string pre_exp) {
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