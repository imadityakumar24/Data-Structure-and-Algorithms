/*

155. Min Stack
Solved
Medium
Topics
premium lock icon
Companies
Hint
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,335,315/4.1M
Acceptance Rate
56.8%

*/




/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */








#include <bits/stdc++.h>
using namespace std;


/*
// did by me
// brute force
// tc = all operation take o(1) bit getmin take o(2n) time
// sc = o(n)  for temp stack
class MinStack {
private:
    stack <int> st;    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        if (st.empty()) 
            return -1;
        else 
            return st.top();    
    }
    
    int getMin() {
        if (st.empty())
            return -1;
        stack <int> temp;

        int minElement = INT_MAX;
        while (!st.empty()) {
            int top = st.top();
            minElement = min(minElement, top);
            temp.push(top);
            st.pop();
        }

        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }

        return minElement;
    }
};
*/



// used chatgpt
// optimal solution
// while inserting i find the min element
// tc = all operation take o(1) time
// sc = o(n)  for temp stack
class MinStack {
private:
    stack <int> st;
    stack <int> minSt;    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
        else {
            minSt.push(minSt.top());  // Repeat current min
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if (minSt.empty())
            return -1;
        return minSt.top();    
    }
};


