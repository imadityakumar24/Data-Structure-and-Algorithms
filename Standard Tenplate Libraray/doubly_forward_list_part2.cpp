/*

=====================  Doubly Linked List using STL list  =====================

*/



#include <iostream>
#include <list>
#include <iterator>
using namespace std;

// Function to display list
void printList(const list<int>& lst, const string& msg) {
    cout << msg;
    for (int x : lst) cout << x << " ";
    cout << endl;
}

int main() {
    cout << endl;

    list<int> dlist;

    // 1. push_front
    dlist.push_front(10);
    dlist.push_front(20);
    dlist.push_front(30);
    printList(dlist, "After push_front: ");

    // 2. push_back
    dlist.push_back(40);
    dlist.push_back(50);
    printList(dlist, "After push_back: ");

    // 3. insert at given position
    auto it = next(dlist.begin(), 2); // 10
    dlist.insert(it, 25);
    printList(dlist, "After insert at position 2: ");

    // 4. emplace_front
    dlist.emplace_front(5);
    printList(dlist, "After emplace_front: ");

    // 5. emplace_back
    dlist.emplace_back(60);
    printList(dlist, "After emplace_back: ");

    // 6. emplace (before iterator)
    it = next(dlist.begin(), 3);
    dlist.emplace(it, 15);
    printList(dlist, "After emplace at pos 3: ");

    // 7. pop_front
    dlist.pop_front();
    printList(dlist, "After pop_front: ");

    // 8. pop_back
    dlist.pop_back();
    printList(dlist, "After pop_back: ");

    // 9. erase (remove element at iterator)
    it = next(dlist.begin(), 2);
    dlist.erase(it);
    printList(dlist, "After erase at pos 2: ");

    // 10. remove (all with value)
    dlist.push_back(25);
    dlist.push_back(25);
    dlist.remove(25);
    printList(dlist, "After remove(25): ");

    // 11. remove_if (remove with condition)
    dlist.remove_if([](int x){ return x % 2 == 0; });
    printList(dlist, "After remove_if(even): ");

    // 12. unique (remove consecutive duplicates)
    dlist.push_back(11);
    dlist.push_back(11);
    dlist.unique();
    printList(dlist, "After unique(): ");

    // 13. sort
    dlist.push_back(3);
    dlist.push_back(99);
    dlist.sort();
    printList(dlist, "After sort(): ");

    // 14. reverse
    dlist.reverse();
    printList(dlist, "After reverse(): ");

    // 15. merge
    list<int> other = {100, 200, 300};
    other.sort();
    dlist.merge(other);
    printList(dlist, "After merge(): ");

    // 16. splice (move elements from another list)
    list<int> extra = {500, 600};
    dlist.splice(dlist.begin(), extra);
    printList(dlist, "After splice at beginning: ");

    // 17. clear
    dlist.clear();
    cout << "After clear(), list size: " << dlist.size() << endl;

    cout << endl;
    return 0;
}

/*

=========== Expected Output ===========

After push_front: 30 20 10 
After push_back: 30 20 10 40 50 
After insert at position 2: 30 20 25 10 40 50 
After emplace_front: 5 30 20 25 10 40 50 
After emplace_back: 5 30 20 25 10 40 50 60 
After emplace at pos 3: 5 30 20 15 25 10 40 50 60 
After pop_front: 30 20 15 25 10 40 50 60 
After pop_back: 30 20 15 25 10 40 50 
After erase at pos 2: 30 20 25 10 40 50 
After remove(25): 30 20 10 40 50 
After remove_if(even):  30  10 
After unique(): 30 10 11 
After sort(): 3 10 11 30 99 
After reverse(): 99 30 11 10 3 
After merge(): 3 10 11 30 99 100 200 300 
After splice at beginning: 500 600 3 10 11 30 99 100 200 300 
After clear(), list size: 0


*/

/*

| Operation      | Description                        | Time Complexity |
| -------------- | ---------------------------------- | --------------- |
| push\_front    | Insert at front                    | O(1)            |
| push\_back     | Insert at back                     | O(1)            |
| pop\_front     | Remove from front                  | O(1)            |
| pop\_back      | Remove from back                   | O(1)            |
| insert         | Insert before given position       | O(1)            |
| emplace        | Construct & insert before position | O(1)            |
| emplace\_front | Construct & insert at front        | O(1)            |
| emplace\_back  | Construct & insert at back         | O(1)            |
| erase          | Delete at position                 | O(1)            |
| remove         | Delete all nodes with given value  | O(n)            |
| remove\_if     | Delete nodes matching condition    | O(n)            |
| unique         | Remove consecutive duplicates      | O(n)            |
| sort           | Sort the list                      | O(n log n)      |
| reverse        | Reverse list                       | O(n)            |
| merge          | Merge 2 sorted lists               | O(n + m)        |
| splice         | Move elements from another list    | O(1)            |
| clear          | Remove all elements                | O(n)            |


*/