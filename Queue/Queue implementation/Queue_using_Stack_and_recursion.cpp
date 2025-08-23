/*

===============  Queue using Single Stack + Recursion  ===============  

Normally Queue follows FIFO, but Stack follows LIFO.  
We can simulate a Queue with just one Stack by using recursion.

Idea:
- Enqueue: Push element into stack (same as normal stack push).  
- Dequeue: Use recursion to reach the bottom element (the first enqueued), pop it, then rebuild the stack on the way back.  

=================  QUEUE OPERATION (USING ONE STACK + RECURSION) ================= 

1. Enqueue (Insert)

Push element into stack.  
Always O(1).

2. Dequeue (Delete)

If stack has only one element → pop it (that’s the front).  
Else → pop all elements until bottom is reached, then rebuild stack using recursion.  
O(n) in worst case.

3. Peek / Front

Similar to dequeue, but instead of removing the bottom element, we return it.  
O(n).

4. isEmpty

Check if stack is empty.  
O(1).

5. Display (optional)

Print all stack elements from bottom → top (to simulate queue order).  
O(n).



time complexity of queue (using single stack + recursion)

| Operation   | Description                          | Time Complexity |
| ----------- | ------------------------------------ | --------------- |
| Enqueue     | Insert an element into queue         | O(1)            |
| Dequeue     | Remove an element from queue         | O(n)            |
| Peek        | View the front element               | O(n)            |
| isEmpty     | Check if queue is empty              | O(1)            |
| Display     | Print all elements (front → rear)    | O(n)            |

*/

#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

// push into stack
void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}

// pop from stack
int pop() {
    if (top == -1) return -1;
    return stackArr[top--];
}

// check empty
bool isEmptyStack() {
    return (top == -1);
}

// enqueue operation
void enqueue(int x) {
    push(x);
    cout << x << " enqueued into queue\n";
}

// dequeue operation (using recursion)
int dequeue() {
    if (isEmptyStack()) {
        cout << "Queue Underflow\n";
        return -1;
    }

    int x = pop();

    if (isEmptyStack()) {
        // this was the first inserted element
        return x;
    }

    // recursive call to reach bottom
    int item = dequeue();

    // push back the popped elements (to restore stack)
    push(x);

    return item;
}

// peek front element
int peek() {
    if (isEmptyStack()) {
        cout << "Queue is empty\n";
        return -1;
    }

    int x = pop();

    if (isEmptyStack()) {
        // bottom element (front of queue)
        push(x); // restore before returning
        return x;
    }

    int item = peek();
    push(x); // restore before returning
    return item;
}

// check if queue is empty
void isEmpty() {
    if (isEmptyStack())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
}

// display queue
void display() {
    if (isEmptyStack()) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    for (int i = 0; i <= top; i++)
        cout << stackArr[i] << " ";
    cout << endl;
}

int main() {
    cout << endl << endl;

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    cout << "Front element: " << peek() << endl;

    cout << dequeue() << " dequeued from queue\n";
    display();

    isEmpty();
    cout << dequeue() << " dequeued from queue\n";
    cout << dequeue() << " dequeued from queue\n";
    isEmpty();
    dequeue();  // extra dequeue to show underflow

    cout << endl << endl;
    return 0;
}


/*

========== OUTPUT ==========

10 enqueued into queue
20 enqueued into queue
30 enqueued into queue
Queue elements: 10 20 30
Front element: 10
10 dequeued from queue
Queue elements: 20 30
Queue is not empty
20 dequeued from queue
30 dequeued from queue
Queue is empty
Queue Underflow

*/
