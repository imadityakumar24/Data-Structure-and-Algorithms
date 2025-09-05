
// Print each digit of a number using recursion

#include <iostream>
using namespace std;

void printDigits(int n) {
    if (n == 0) return;
    printDigits(n / 10);
    cout << n % 10 << " ";
}

int main() {
    int n = 1234;
    printDigits(n);
    return 0;
}

/*

Output:

1 2 3 4

*/
