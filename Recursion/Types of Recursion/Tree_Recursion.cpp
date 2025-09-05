
// Tree Recursion:

// Definition: A recursion where a function calls itself more than once, forming a tree of calls.

#include <iostream>
using namespace std;

void treeRec(int n) {
    if (n == 0) return;
    cout << n << " ";
    treeRec(n - 1);
    treeRec(n - 1);
}

int main() {
    cout << "\n\n";

    treeRec(3);

    cout << "\n\n";
    return 0;
}

/*

Output:

3 2 1 1 2 1 1

*/
