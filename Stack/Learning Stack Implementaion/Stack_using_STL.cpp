/*

Stack using STL:

C++ STL provides a ready-made `stack` container adaptor in <stack> header.  
It is a LIFO (Last In, First Out) data structure.  

Internally, `stack` uses `deque` by default (but can also use vector or list).  

=================  STACK OPERATION (USING STL) ================= 

1. Push

s.push(x) → adds element on top of the stack.  
O(1).

2. Pop

s.pop() → removes element from the top of the stack.  
(O(1)) → must check if not empty before calling.  

3. Peek / Top

s.top() → returns the top element of the stack.  
O(1).

4. isEmpty

s.empty() → returns true if stack is empty.  
O(1).

5. Size

s.size() → returns number of elements.  
O(1).

6. Display (optional)

We need to copy/iterate elements since STL stack does not provide direct iteration.  
O(n).



time complexity of stack operations (STL)

| Operation   | Description                       | Time Complexity |
| ----------- | --------------------------------- | --------------- |
|   Push      | Insert an element at the top      |   O(1)          |
|   Pop       | Remove the top element            |   O(1)          |
|   Peek      | View the top element              |   O(1)          |
|   isEmpty   | Check if stack is empty           |   O(1)          |
|   Size      | Number of elements in stack       |   O(1)          |
|   Display   | Print all elements (top → bottom) |   O(n)          |

*/

#include <iostream>
#include <stack>
using namespace std;

// display function
void display(stack<int> s) {
    if (s.empty()) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    cout << endl << endl;

    stack<int> s;

    // Push
    s.push(10);
    cout << "10 pushed into stack\n";
    s.push(20);
    cout << "20 pushed into stack\n";
    s.push(30);
    cout << "30 pushed into stack\n";

    display(s);

    // Peek
    cout << "Top element: " << s.top() << endl;

    // Pop
    s.pop();
    cout << "Top element popped\n";
    display(s);

    // Empty check
    cout << (s.empty() ? "Stack is empty\n" : "Stack is not empty\n");

    // Size
    cout << "Stack size: " << s.size() << endl;

    // More pops
    s.pop();
    s.pop();
    cout << (s.empty() ? "Stack is empty\n" : "Stack is not empty\n");

    // Extra pop (not allowed)
    if (!s.empty()) {
        s.pop();
    } else {
        cout << "Stack Underflow (cannot pop)\n";
    }

    cout << endl << endl;
    return 0;
}


/*

========== OUTPUT ==========

10 pushed into stack
20 pushed into stack
30 pushed into stack
Stack elements: 30 20 10
Top element: 30
Top element popped
Stack elements: 20 10
Stack is not empty
Stack size: 2
Stack is empty
Stack Underflow (cannot pop)

*/
