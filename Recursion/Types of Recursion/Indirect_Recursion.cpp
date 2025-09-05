
// Indirect Recursion:

// Definition: When one function calls another function, and that function calls back the first one.

#include <iostream>
using namespace std;

void funcA(int n);
void funcB(int n);

void funcA(int n) {
    if (n <= 0) return;
    cout << "A: " << n << " ";
    funcB(n - 1);
}

void funcB(int n) {
    if (n <= 0) return;
    cout << "B: " << n << " ";
    funcA(n - 2);
}

int main() {
    cout << "\n\n";

    funcA(5);

     cout << "\n\n";
    return 0;
}

/*

Output:

A: 5 B: 4 A: 2 B: 1

*/
