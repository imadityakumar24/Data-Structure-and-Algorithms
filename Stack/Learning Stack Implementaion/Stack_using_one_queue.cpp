/*

=========== Stack implementation using One Queue ===============

Approach 2: Using One Queue

Make push operation costly with rotation.

Steps:
1. Use only one queue `q`.
2. Push(x):
      - Enqueue element x.
      - Rotate the queue (dequeue and enqueue previous elements) 
        so that x moves to the front.
3. Pop:
      - Dequeue from q.
4. Top:
      - Return q.front().

Complexity:
- Push → O(n)
- Pop  → O(1)
- Top  → O(1)

*/

#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

// push element into stack
void push(int x) {
    int size = q.size();
    q.push(x);

    // rotate all previous elements behind new element
    for (int i = 0; i < size; i++) {
        q.push(q.front());
        q.pop();
    }

    cout << x << " pushed into stack\n";
}

// pop element from stack
void pop() {
    if (q.empty()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << q.front() << " popped from stack\n";
    q.pop();
}

// top element
void top() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << q.front() << endl;
}

// check if stack is empty
void isEmpty() {
    if (q.empty())
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
