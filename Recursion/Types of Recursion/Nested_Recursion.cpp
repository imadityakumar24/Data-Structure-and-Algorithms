
// Nested Recursion:

// Definition: A recursion where the argument of a recursive call itself is another recursive call.

#include <iostream>
using namespace std;

int nestedRec(int n) {
    if (n > 100) return n - 10;
    return nestedRec(nestedRec(n + 11));
}

int main() {
    cout << "\n\n";

    cout << nestedRec(95);

    cout << "\n\n";
    return 0;
}

/*

Output:

91

*/
