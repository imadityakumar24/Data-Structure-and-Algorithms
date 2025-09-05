
// Nth Fibonacci number using recursion

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 6;
    cout << n << "th Fibonacci = " << fib(n);
    return 0;
}

/*

Output:

6th Fibonacci = 8

*/
