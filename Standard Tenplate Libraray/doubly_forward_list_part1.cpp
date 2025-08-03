/*

=====================  Doubly Linked List using STL list  =====================


Explanation of Operations & Properties


1. push_front(value)
What it does: Inserts a node at the beginning.
How it works: Creates a node, sets its next to current head and updates head.
Time Complexity: O(1).

2. push_back(value)
What it does: Inserts a node at the end.
How it works: Creates a node, attaches it after the current tail, updates tail.
Time Complexity: O(1).

3. insert(iterator, value)
What it does: Inserts before the given iterator position.
How it works: Creates a node and adjusts prev and next pointers accordingly.
Time Complexity: O(1) (if iterator given).

4. erase(iterator)
What it does: Removes the node at the given position.
How it works: Links prev->next to next, and next->prev to prev.
Time Complexity: O(1).

5. remove(value)
What it does: Removes all nodes containing the given value.
How it works: Traverses list and deletes matching nodes.
Time Complexity: O(n).

6. unique()
What it does: Removes consecutive duplicate values.
How it works: Compares each element with the next and deletes duplicates.
Time Complexity: O(n).

7. sort()
What it does: Sorts the list in ascending order.
How it works: Uses merge sort internally (good for linked lists).
Time Complexity: O(n log n).

8. reverse()
What it does: Reverses the order of elements.
How it works: Re-links nodes so last becomes first.
Time Complexity: O(n).

9. clear()
What it does: Removes all nodes.
How it works: Deallocates memory of all nodes.
Time Complexity: O(n).

Note:
Unlike forward_list, std::list allows bidirectional traversal using prev & next.

*/


#include <iostream>
#include <list>
using namespace std;

// Function to display list
void printList(const list<int>& lst, const string& msg) {
    cout << msg;
    for (int x : lst) cout << x << " ";
    cout << endl;
}

int main() {
    cout << endl << endl;

    list<int> dlist;

    // 1. Insert elements at front
    dlist.push_front(10);
    dlist.push_front(20);
    dlist.push_front(30);
    printList(dlist, "After push_front: ");

    // 2. Insert elements at back
    dlist.push_back(40);
    dlist.push_back(50);
    printList(dlist, "After push_back: ");

    // 3. Insert before second element
    auto it = next(dlist.begin()); // pointing to 20
    dlist.insert(it, 25);
    printList(dlist, "After insert before 20: ");

    // 4. Erase second element (20)
    it = next(dlist.begin(), 2); // pointing to 20 now
    dlist.erase(it);
    printList(dlist, "After erase(20): ");

    // 5. Remove specific value (30)
    dlist.remove(30);
    printList(dlist, "After remove(30): ");

    // 6. Add duplicates and remove consecutive duplicates
    dlist.push_back(50);
    dlist.push_back(50);
    dlist.unique();
    printList(dlist, "After unique(): ");

    // 7. Sort list
    dlist.sort();
    printList(dlist, "After sort(): ");

    // 8. Reverse list
    dlist.reverse();
    printList(dlist, "After reverse(): ");

    // 9. Clear list
    dlist.clear();
    cout << "After clear(), list size: " << dlist.size() << endl;

    cout << endl << endl;
    return 0;
}


/*

=========== Expected Output ===========

After push_front: 30 20 10 
After push_back: 30 20 10 40 50 
After insert before 20: 30 25 20 10 40 50 
After erase(20): 30 25 10 40 50 
After remove(30): 25 10 40 50 
After unique(): 25 10 40 50 
After sort(): 10 25 40 50 
After reverse(): 50 40 25 10 
After clear(), list size: 0

*/

/*

| Operation     | Description                       | Time Complexity |
| ------------- | --------------------------------- | --------------- |
| push_front    | Insert at front                   | O(1)            |
| push_back     | Insert at back                    | O(1)            |
| insert        | Insert at given position          | O(1)            |
| erase         | Delete node at position           | O(1)            |
| remove        | Delete all nodes with given value | O(n)            |
| unique        | Remove consecutive duplicates     | O(n)            |
| sort          | Sort list                         | O(n log n)      |
| reverse       | Reverse list                      | O(n)            |
| clear         | Delete all nodes                  | O(n)            |

*/

