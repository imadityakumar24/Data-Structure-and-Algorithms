/*


Stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

The element inserted last is the first one to be removed.

Example: A stack of plates → the last plate kept on top is the first to be taken out.

=================  STACK OPERATION   ================= 


1. Push

Adds (inserts) an element on top of the stack.
In array implementation: stack[++top] = x;
If the stack is full → Stack Overflow.

2. Pop

Removes (deletes) the element from the top of the stack.
In array implementation: top--;
If the stack is empty → Stack Underflow.

3. Peek / Top

Returns the top element of the stack without removing it.
If the stack is empty → no element to return.

4. isEmpty

Checks whether the stack is empty.
Returns true if top == -1.
Useful before performing pop/peek to avoid underflow.

5. Display (optional)

Prints all stack elements from top to bottom.
Helpful for debugging or visualization.





time complexity of stack operations

| Operation   | Description                       | Time Complexity |
| ----------- | --------------------------------- | --------------- |
|   Push      | Insert an element at the top      |   O(1)          |
|   Pop       | Remove the top element            |   O(1)          |
|   Peek      | View the top element              |   O(1)          |
|   isEmpty   | Check if stack is empty           |   O(1)          |
|   Display   | Print all elements (top → bottom) |   O(n)          |


*/

#include <iostream>
using namespace std;

#define MAX 100   // maximum size of stack

int stack[MAX];   // array to store stack elements
int top = -1;     // index of top element

// push element into stack
void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
    cout << x << " pushed into stack\n";
}

// pop element from stack
void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << stack[top--] << " popped from stack\n";
}

// view top element
void peek() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << stack[top] << endl;
}

// check if stack is empty
void isEmpty() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
}

// display all elements
void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

int main() {
    cout << endl << endl;

    push(10);
    push(20);
    push(30);
    display();

    peek();
    pop();
    display();

    isEmpty();
    pop();
    pop();
    isEmpty();
    pop();  // extra pop to show underflow

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
30 popped from stack
Stack elements: 20 10
Stack is not empty
20 popped from stack
10 popped from stack
Stack is empty
Stack Underflow


*/