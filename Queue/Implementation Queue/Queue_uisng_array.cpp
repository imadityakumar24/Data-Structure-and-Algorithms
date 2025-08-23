/*


============================  QUEUEN  ============================

Queue is a linear data structure that follows the FIFO (First In, First Out) principle.

The element inserted first is the first one to be removed.

Example: A queue of people → the person who comes first stands first in line and leaves first.

=================  QUEUE OPERATION   ================= 

1. Enqueue (Insert)

Adds (inserts) an element at the rear (end) of the queue.
In array implementation: queue[++rear] = x;
If the queue is full → Queue Overflow.

2. Dequeue (Delete)

Removes (deletes) an element from the front of the queue.
In array implementation: front++;
If the queue is empty → Queue Underflow.

3. Peek / Front

Returns the front element of the queue without removing it.
If the queue is empty → no element to return.

4. isEmpty

Checks whether the queue is empty.
Returns true if front > rear.

5. Display (optional)

Prints all queue elements from front to rear.
Helpful for debugging or visualization.



time complexity of queue operations

| Operation   | Description                          | Time Complexity |
| ----------- | ------------------------------------ | --------------- |
| Enqueue     | Insert an element at the rear        | O(1)            |
| Dequeue     | Remove an element from the front     | O(1)            |
| Peek        | View the front element               | O(1)            |
| isEmpty     | Check if queue is empty              | O(1)            |
| Display     | Print all elements (front → rear)    | O(n)            |

*/

#include <iostream>
using namespace std;

#define MAX 100   // maximum size of queue

int queueArr[MAX];  // array to store queue elements
int front = 0;      // index of front element
int rear = -1;      // index of rear element

// enqueue element into queue
void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    queueArr[++rear] = x;
    cout << x << " enqueued into queue\n";
}

// dequeue element from queue
void dequeue() {
    if (front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << queueArr[front++] << " dequeued from queue\n";
}

// view front element
void peek() {
    if (front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Front element: " << queueArr[front] << endl;
}

// check if queue is empty
void isEmpty() {
    if (front > rear)
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
}

// display all elements
void display() {
    if (front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << queueArr[i] << " ";
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
