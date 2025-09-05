
// Sum of first N natural numbers using recursion

#include <iostream>
using namespace std;

int sumN(int n) {
    if (n == 0) return 0;
    return n + sumN(n - 1);
}

int main() {
    int n = 5;
    cout << "Sum = " << sumN(n);
    return 0;
}

/*

Output:

Sum = 15

*/
