/*

Queue using STL:

C++ STL provides a ready-made `queue` container adaptor in <queue> header.  
It internally uses `deque` (double-ended queue) by default.  

Queue follows FIFO (First In, First Out).  
Insertion happens at the rear, and deletion happens at the front.

=================  QUEUE OPERATION (USING STL) ================= 

1. Enqueue (Insert)

q.push(x) → inserts element at the rear.  
O(1).

2. Dequeue (Delete)

q.pop() → removes element from the front.  
(O(1)) → must check if not empty before calling.  

3. Peek / Front

q.front() → returns front element.  
O(1).

4. Peek / Rear

q.back() → returns last element (rear).  
O(1).

5. isEmpty

q.empty() → returns true if queue is empty.  
O(1).

6. Size

q.size() → returns number of elements.  
O(1).

7. Display (optional)

We need to copy/iterate elements since STL queue doesn’t provide direct iteration.  
O(n).



time complexity of queue (STL)

| Operation   | Description                          | Time Complexity |
| ----------- | ------------------------------------ | --------------- |
| Enqueue     | Insert an element at the rear        | O(1)            |
| Dequeue     | Remove an element from the front     | O(1)            |
| Front       | View the front element               | O(1)            |
| Back        | View the last element                | O(1)            |
| isEmpty     | Check if queue is empty              | O(1)            |
| Size        | Number of elements in queue          | O(1)            |
| Display     | Print all elements (front → rear)    | O(n)            |

*/

#include <iostream>
#include <queue>
using namespace std;

// display function
void display(queue<int> q) {
    if (q.empty()) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    cout << endl << endl;

    queue<int> q;

    // Enqueue
    q.push(10);
    cout << "10 enqueued\n";
    q.push(20);
    cout << "20 enqueued\n";
    q.push(30);
    cout << "30 enqueued\n";

    display(q);

    // Peek front & back
    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.back() << endl;

    // Dequeue
    q.pop();
    cout << "Front element dequeued\n";
    display(q);

    // Size and empty check
    cout << "Queue size: " << q.size() << endl;
    cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");

    // More pops
    q.pop();
    q.pop();
    cout << (q.empty() ? "Queue is empty\n" : "Queue is not empty\n");

    // Extra pop (not allowed)
    if (!q.empty()) {
        q.pop();
    } else {
        cout << "Queue Underflow (cannot pop)\n";
    }

    cout << endl << endl;
    return 0;
}


/*

========== OUTPUT ==========

10 enqueued
20 enqueued
30 enqueued
Queue elements: 10 20 30
Front element: 10
Rear element: 30
Front element dequeued
Queue elements: 20 30
Queue size: 2
Queue is not empty
Queue is empty
Queue Underflow (cannot pop)

*/
