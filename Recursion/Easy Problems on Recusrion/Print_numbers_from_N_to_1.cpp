
// Print numbers from N to 1 using recursion

#include <iostream>
using namespace std;

void printNto1(int n) {
    if (n == 0) return;
    cout << n << " ";
    printNto1(n - 1);
}

int main() {
    int n = 5;
    printNto1(n);
    return 0;
}

/*

Output:

5 4 3 2 1

*/
