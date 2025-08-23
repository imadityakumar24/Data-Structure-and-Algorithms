/*

Queue using Linked List:

Queue follows FIFO (First In, First Out).  
Using a linked list, we can dynamically allocate memory, so queue size is not fixed.  

We maintain:  
- `front` pointer → points to the first element (head).  
- `rear` pointer → points to the last element (tail).  

=================  QUEUE OPERATION (USING LINKED LIST) ================= 

1. Enqueue (Insert)

Create a new node and add it at the end (rear).  
If queue is empty → both front and rear point to new node.  
O(1).

2. Dequeue (Delete)

Remove node from the front.  
If queue becomes empty → set both front and rear = NULL.  
O(1).

3. Peek / Front

Return the data at front without deleting.  
O(1).

4. isEmpty

Check if front == NULL.  
O(1).

5. Display (optional)

Traverse from front to rear and print all nodes.  
O(n).



time complexity of queue (using linked list)

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

// Node structure
struct Node {
    int data;
    Node* next;
};

Node* front = NULL;  // pointer to front node
Node* rear = NULL;   // pointer to rear node

// enqueue operation
void enqueue(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) { // empty queue
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    cout << x << " enqueued into queue\n";
}

// dequeue operation
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;
    cout << front->data << " dequeued from queue\n";

    front = front->next;
    if (front == NULL) rear = NULL; // queue became empty

    delete temp;
}

// peek front element
void peek() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Front element: " << front->data << endl;
}

// check if queue is empty
void isEmpty() {
    if (front == NULL)
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";
}

// display queue
void display() {
    if (front == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
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
    dequeue(); // extra dequeue to show underflow

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
