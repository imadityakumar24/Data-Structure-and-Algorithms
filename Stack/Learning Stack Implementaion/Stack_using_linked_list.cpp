/*

=========== Stack implementation using Linked List ===============

👉 Approach:

- Use a singly linked list.
- The "top" of the stack will be the head of the linked list.

Operations:
1. Push(x): Insert a node at the beginning (head).
2. Pop(): Remove a node from the beginning.
3. Top(): Return the value of the head node.
4. isEmpty(): Check if head == NULL.
5. Display(): Traverse and print all nodes.

Why head as top? 
Because insertion and deletion at the beginning are O(1).

-------------------------------------------------------
| Operation  | Description                  | Time     |
|------------|------------------------------|----------|
| Push       | Insert at beginning (head)   | O(1)     |
| Pop        | Delete from beginning        | O(1)     |
| Top        | Return head->data            | O(1)     |
| isEmpty    | Check if head == NULL        | O(1)     |
| Display    | Traverse entire list         | O(n)     |
-------------------------------------------------------

Definitions:
- Push: Add a new element on top (head).
- Pop: Remove the element from top (head).
- Top: Get the value of the top element.
- isEmpty: Check if stack has no elements.
- Display: Print all stack elements (top → bottom).

*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* topNode = NULL; // top of stack

// push element into stack
void push(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = topNode;
    topNode = temp;
    cout << x << " pushed into stack\n";
}

// pop element from stack
void pop() {
    if (topNode == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << topNode->data << " popped from stack\n";
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
}

// top element
void top() {
    if (topNode == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << topNode->data << endl;
}

// check if empty
void isEmpty() {
    if (topNode == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
}

// display all elements
void display() {
    if (topNode == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node* temp = topNode;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    cout << endl << endl;

    push(10);
    push(20);
    push(30);

    display();
    top();
    pop();
    display();
    isEmpty();
    pop();
    pop();
    isEmpty();
    pop(); // extra pop to show underflow

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
