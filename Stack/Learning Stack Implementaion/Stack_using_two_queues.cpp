/*

=========== Stack implemention using two queues ================

Approach 1: Using Two Queues

Make push operation costly.

Use two queues q1 (main) and q2 (helper).

Push(x):
    Enqueue x into q2.
    Move all elements from q1 to q2.
    Swap q1 and q2.

Pop:
    Dequeue from q1.

Top:
    Return q1.front().

Complexity:
    Push → O(n)
    Pop  → O(1)
    Top  → O(1)

*/

#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

// push element into stack
void push(int x) {
    q2.push(x);

    // move all elements of q1 into q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    // swap q1 and q2
    swap(q1, q2);

    cout << x << " pushed into stack\n";
}

// pop element from stack
void pop() {
    if (q1.empty()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << q1.front() << " popped from stack\n";
    q1.pop();
}

// top element
void top() {
    if (q1.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << q1.front() << endl;
}

// check if empty
void isEmpty() {
    if (q1.empty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
}

int main() {
    cout << endl << endl;

    push(10);
    push(20);
    push(30);

    top();
    pop();
    top();
    
    cout << endl << endl;
    return 0;
}


/*

========== OUTPUT ==========

10 pushed into stack
20 pushed into stack
30 pushed into stack
Top element: 30
30 popped from stack
Top element: 20

*/
