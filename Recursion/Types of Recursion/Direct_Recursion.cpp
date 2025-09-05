
// Direct Recursion:

// Definition: When a function directly calls itself until the base condition is met.

#include <iostream>
using namespace std;

void directRec(int n) {
    if (n == 0) return;   // base case
    cout << n << " ";
    directRec(n - 1);     // function calling itself directly
}

int main() {
    cout << "\n\n";

    directRec(5);

    cout << "\n\n";
    return 0;
}


/*

Output:

5 4 3 2 1

*/
