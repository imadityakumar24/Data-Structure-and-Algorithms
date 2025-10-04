/*

Reverse a Stack
Difficulty: MediumAccuracy: 80.5%Submissions: 119K+Points: 4Average Time: 20m
You are given a stack st[]. You have to reverse the stack.

Examples:

Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: After reversing, the elements of stack are in opposite order.

Constraints:
1 ≤ st.size() ≤ 100
0 ≤ stack element ≤ 100


*/



#include <bits/stdc++.h>
using namespace std;

/*
// brute force
// using temp stack and coping the stack
// tc = o(n^2) 
// sc= o(n) recursion stack space
class Solution {
public:
    void Reverse(stack <int> &St) {
        if (St.empty())
            return;
            
        int topElement = St.top(); 
        St.pop();
        Reverse(St);
        
        stack <int> temp;
        while (!St.empty()) {
            temp.push(St.top());
            St.pop();
        }
        
        St.push(topElement);
        while (!temp.empty()) {
            St.push(temp.top());
            temp.pop();
        }
        
    }
};
*/



// optimized recursion aproach
// tc = o(n) 
// sc= o(n) recursion stack space, o(!) auzxullary space 
class Solution {
private:
    void insertAtBottom(stack <int> &St, int element) {
        if (St.empty()) {
            St.push(element);
            return;
        }
        int currentTop = St.top();
        St.pop();
        insertAtBottom(St, element);
        St.push(currentTop);
    }
public:
    void Reverse(stack <int> &St) {
        if (St.empty())
            return;
            
        int topElement = St.top(); 
        St.pop();
        Reverse(St);
        
        insertAtBottom(St, topElement);
    }
};

