
// Print characters of a string in reverse using recursion

#include <iostream>
using namespace std;

void reverseString(string s, int i) {
    if (i < 0) return;
    cout << s[i];
    reverseString(s, i - 1);
}

int main() {
    string s = "hello";
    reverseString(s, s.size() - 1);
    return 0;
}

/*

Output:

olleh

*/
