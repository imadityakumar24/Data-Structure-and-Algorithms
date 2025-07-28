#include <iostream>
#include <queue>
using namespace std;

int main() {
    cout << endl << endl;

    queue<int> q;

    // Enqueue (push elements)
    q.push(10);
    q.push(20);
    q.push(30);

    // Access front and back
    cout << "Front: " << q.front() << endl;  // 10
    cout << "Back: " << q.back() << endl;    // 30

    // Dequeue (pop element)
    q.pop(); // removes 10

    cout << "Front after pop: " << q.front() << endl;  // 20

    // Size and empty check
    cout << "Size: " << q.size() << endl;
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    cout << endl << endl;
    return 0;
}
