
// Factorial using Recursion
// -------------------------------------------------------------
// Definition:
// Factorial of n (n!) is the product of numbers from 1 to n.
// Example: 5! = 5 * 4 * 3 * 2 * 1 = 120
//
// How recursion works here:
// factorial(n) = n * factorial(n-1)
// Base Case: factorial(0) = 1 or factorial(1) = 1
//
// -------------------------------------------------------------
// Step-by-step stack flow for factorial(5):
//
// Call expansion (going deeper):
// factorial(5)
//   -> returns 5 * factorial(4)
// factorial(4)
//   -> returns 4 * factorial(3)
// factorial(3)
//   -> returns 3 * factorial(2)
// factorial(2)
//   -> returns 2 * factorial(1)
// factorial(1)
//   -> base case, returns 1
//
// -------------------------------------------------------------
// Stack unwinding (returning results back):
// factorial(2) = 2 * 1 = 2
// factorial(3) = 3 * 2 = 6
// factorial(4) = 4 * 6 = 24
// factorial(5) = 5 * 24 = 120
//
// Final Answer = 120
// -------------------------------------------------------------

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;  // base case
    return n * factorial(n - 1);     // recursive case
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " = " << factorial(n);
    return 0;
}

/*

Output:

Factorial of 5 = 120

*/
