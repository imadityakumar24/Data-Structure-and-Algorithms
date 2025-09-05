
// Tail Recursion:

// Definition: A type of recursion where the recursive call is the last statement in the function.

#include <iostream>
using namespace std;

void tailRec(int n) {
    if (n == 0) return;
    cout << n << " ";
    tailRec(n - 1);   // recursive call at the end
}

int main() {
    cout << "\n\n";

    tailRec(5);

    cout << "\n\n";
    return 0;
}

/*

Output:

5 4 3 2 1

*/
