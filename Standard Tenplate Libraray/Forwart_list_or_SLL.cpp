/*

=====================  Forward List / Singly linked list using STL  =====================


Explanation of Operations & Properties


1. push_front(value)
What it does: Inserts a new node at the beginning.
How it works: Creates a node and makes its next point to the current head. Head pointer updated.
Time Complexity: O(1) (constant time).

2. insert_after(iterator, value)
What it does: Inserts a node after a given position.
How it works: Creates a node, adjusts the next pointer of the given node to the new one.
Time Complexity: O(1) (if iterator given).

3. erase_after(iterator)
What it does: Deletes the node after a given position.
How it works: Bypasses the node after iterator by adjusting pointers.
Time Complexity: O(1).

4. remove(value)
What it does: Removes all nodes containing the given value.
How it works: Traverses the list, skips nodes matching the value.
Time Complexity: O(n) (since entire list may be traversed).

5. unique()
What it does: Removes consecutive duplicate values.
How it works: Compares each element with the next and removes if equal.
Time Complexity: O(n).

6. sort()
What it does: Sorts the linked list in ascending order.
How it works: Uses merge sort internally (efficient for linked lists).
Time Complexity: O(n log n).

7. reverse()
What it does: Reverses the order of elements.
How it works: Re-links nodes so that last becomes first.
Time Complexity: O(n).

8. clear()
What it does: Removes all elements.
How it works: Deallocates memory of all nodes.
Time Complexity: O(n).


Note:
forward_list is memory‑efficient because it stores only one pointer (next) per node.
Unlike std::list (doubly linked list), it doesn’t allow reverse traversal.

*/





#include <iostream>
#include <forward_list>
using namespace std;

// Function to display the list
void printList(const forward_list<int>& lst, const string& msg) {
    cout << msg;
    for (int x : lst) cout << x << " ";
    cout << endl;
}

int main() {
    cout << endl << endl;


    forward_list<int> llist;

    // 1. Insert elements at front
    llist.push_front(10);
    llist.push_front(20);
    llist.push_front(30);
    printList(llist, "After push_front: ");

    // 2. Insert after first element
    auto it = llist.begin();
    llist.insert_after(it, 25);
    printList(llist, "After insert_after: ");

    // 3. Delete element after first
    llist.erase_after(it);
    printList(llist, "After erase_after: ");

    // 4. Remove specific value (20)
    llist.remove(20);
    printList(llist, "After remove(20): ");

    // 5. Add duplicates and remove consecutive duplicates
    llist.push_front(10);
    llist.push_front(10);
    llist.unique();
    printList(llist, "After unique(): ");

    // 6. Sort the list
    llist.sort();
    printList(llist, "After sort(): ");

    // 7. Reverse the list
    llist.reverse();
    printList(llist, "After reverse(): ");

    // 8. Clear the list
    llist.clear();
    cout << "After clear(), list size: "
         << distance(llist.begin(), llist.end()) << endl;

    cout << endl << endl;
    return 0;
}


/*

After push_front: 30 20 10 
After insert_after: 30 25 20 10 
After erase_after: 30 20 10 
After remove(20): 30 10 
After unique(): 10 30 10 
After sort(): 10 10 30 
After reverse(): 30 10 10 
After clear(), list size: 0


*/

/*

| Operation     | Description                       | Time Complexity |
| ------------- | --------------------------------- | --------------- |
| push\_front   | Insert node at front              | O(1)            |
| insert\_after | Insert node after position        | O(1)            |
| erase\_after  | Delete node after position        | O(1)            |
| remove        | Delete all nodes with given value | O(n)            |
| unique        | Remove consecutive duplicates     | O(n)            |
| sort          | Sort list                         | O(n log n)      |
| reverse       | Reverse order of list             | O(n)            |
| clear         | Delete all elements               | O(n)            |


*/