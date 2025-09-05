
// Check if a number is palindrome using recursion

#include <iostream>
using namespace std;

int reverseNum(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNum(n / 10, rev * 10 + (n % 10));
}

bool isPalindrome(int n) {
    return n == reverseNum(n);
}

int main() {
    int n = 1221;
    cout << (isPalindrome(n) ? "Palindrome" : "Not Palindrome");
    return 0;
}

/*

Output:
Palindrome

*/
