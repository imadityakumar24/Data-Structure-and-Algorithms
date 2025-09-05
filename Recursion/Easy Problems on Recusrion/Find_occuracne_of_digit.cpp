
// Count occurrences of a digit in a number using recursion

#include <iostream>
using namespace std;

int countDigit(int n, int d) {
    if (n == 0) return 0;
    return ((n % 10 == d) ? 1 : 0) + countDigit(n / 10, d);
}

int main() {
    int n = 122333, d = 3;
    cout << "Occurrences of " << d << " = " << countDigit(n, d);
    return 0;
}

/*

Output:

Occurrences of 3 = 3

*/
