
// Sum of digits of a number using recursion

#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n = 1234;
    cout << "Sum of digits = " << sumDigits(n);
    return 0;
}

/*

Output:

Sum of digits = 10

*/
