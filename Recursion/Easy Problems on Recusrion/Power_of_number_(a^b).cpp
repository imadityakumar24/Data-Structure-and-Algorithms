
// Power of number (a^b) using recursion

#include <iostream>
using namespace std;

int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

int main() {
    int a = 2, b = 5;
    cout << a << "^" << b << " = " << power(a, b);
    return 0;
}

/*

Output:

2^5 = 32

*/
