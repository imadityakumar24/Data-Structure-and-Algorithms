/*

=======================  Queue using Stack  ======================= 

Normally, a Queue follows FIFO (First In, First Out).
But a Stack follows LIFO (Last In, First Out).

We can implement a Queue using two Stacks.

Idea:  
- Use one stack (s1) for Enqueue (insert).  
- Use another stack (s2) for Dequeue (remove).  
- While dequeuing, if s2 is empty, move all elements from s1 to s2, then pop from s2.  

=================  QUEUE OPERATION (USING STACKS) ================= 

1. Enqueue (Insert)

Push element into stack s1.
Always O(1).

2. Dequeue (Delete)

If s2 is empty → move all elements from s1 to s2, then pop from s2.  
Else directly pop from s2.  
Amortized O(1), but worst case O(n) (when shifting elements).

3. Peek / Front

If s2 is empty → move all elements from s1 to s2, then return top of s2.  
Else directly return top of s2.  
O(1) amortized.

4. isEmpty

Queue is empty if both s1 and s2 are empty.  
O(1).

5. Display (optional)

Print elements in correct queue order (front → rear).  
Requires traversing stacks. O(n).



time complexity of queue (using stacks)

| Operation   | Description                          | Time Complexity |
| ----------- | ------------------------------------ | --------------- |
| Enqueue     | Insert an element into queue         | O(1)            |
| Dequeue     | Remove an element from queue         | Amortized O(1)  |
| Peek        | View the front element               | Amortized O(1)  |
| isEmpty     | Check if queue is empty              | O(1)            |
| Display     | Print all elements (front → rear)    | O(n)            |

*/

#include <iostream>
using namespace std;

#define MAX 100   // maximum size of stack

int s1[MAX], s2[MAX];  // two stacks
int top1 = -1, top2 = -1; // top pointers

// push into stack
void push(int stack[], int &top, int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
}

// pop from stack
int pop(int stack[], int &top) {
    if (top == -1) {
        return -1; // empty
    }
    return stack[top--];
}

// check if stack empty
bool isStackEmpty(int top) {
    return (top == -1);
}

// enqueue operation
void enqueue(int x) {
    push(s1, top1, x);
    cout << x << " enqueued into queue\n";
}

// dequeue operation
void dequeue() {
    if (isStackEmpty(top1) && isStackEmpty(top2)) {
        cout << "Queue Underflow\n";
        return;
    }

    if (isStackEmpty(top2)) {
        // move all elements from s1 to s2
        while (!isStackEmpty(top1)) {
            push(s2, top2, pop(s1, top1));
        }
    }

    cout << pop(s2, top2) << " dequeued from queue\n";
}

// peek front element
void peek() {
    if (isStackEmpty(top1) && isStackEmpty(top2)) {
        cout << "Queue is empty\n";
        return;
    }

    if (isStackEmpty(top2)) {
        while (!isStackEmpty(top1)) {
            push(s2, top2, pop(s1, top1));
        }
    }

    cout << "Front element: " << s2[top2] << endl;
}

// check if queue is empty
void isEmpty() {
    if (isStackEmpty(top1) && isStackEmpty(top2))
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
}

// display queue
void display() {
    if (isStackEmpty(top1) && isStackEmpty(top2)) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";

    // print elements of s2 from top to bottom
    for (int i = top2; i >= 0; i--)
        cout << s2[i] << " ";

    // print elements of s1 from bottom to top
    for (int i = 0; i <= top1; i++)
        cout << s1[i] << " ";

    cout << endl;
}

int main() {
    cout << endl << endl;

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    peek();
    dequeue();
    display();

    isEmpty();
    dequeue();
    dequeue();
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
