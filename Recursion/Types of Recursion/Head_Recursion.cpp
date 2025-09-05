
// Head Recursion:

// Definition: A type of recursion where the recursive call happens before any other statements.

#include <iostream>
using namespace std;

void headRec(int n) {
    if (n == 0) return;
    headRec(n - 1);   // recursive call first
    cout << n << " "; // work happens after recursion
}

int main() {
    cout << "\n\n";

    headRec(5);

    cout << "\n\n";
    return 0;
}

/*

Output:

1 2 3 4 5

*/
