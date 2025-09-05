
// Print numbers from 1 to N using recursion

#include <iostream>
using namespace std;

void print1toN(int n) {
    if (n == 0) return;
    print1toN(n - 1);
    cout << n << " ";
}

int main() {
    int n = 5;
    print1toN(n);
    return 0;
}

/*

Output:

1 2 3 4 5

*/
