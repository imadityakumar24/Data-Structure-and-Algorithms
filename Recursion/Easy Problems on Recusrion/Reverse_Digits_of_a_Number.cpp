
// Reverse digits of a number using recursion

#include <iostream>
using namespace std;

int reverseNum(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNum(n / 10, rev * 10 + (n % 10));
}

int main() {
    int n = 1234;
    cout << "Reversed = " << reverseNum(n);
    return 0;
}

/*

Output:

Reversed = 4321

*/
