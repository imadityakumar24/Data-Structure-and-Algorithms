
/*

============ Not ( ~ ) Operator ==============

The bitwise complement (NOT) operator flips each bit of a number, if a bit is set the operator will clear it, if it is cleared the operator sets it.

means convert the decimal number to binary and then perform operation

n         = 01011000
--------------------
~n        = 10100111


*/

#include <iostream>
using namespace std;

int main() {
    cout << endl << endl;

    cout << "5 = after bitwise not : " << (~5) << endl;
    cout << "10 = after bitwise not : " << (~10) << endl;
    cout << "20 = after bitwise not : " << (~20) << endl;
    cout << "-20 = after bitwise not : " << (~(-20)) << endl;
    cout << "-7 = after bitwise not : " << (~(-7)) << endl;

    int x = 5;       // Binary: 0000 0101
    int result = ~x; // Binary: 1111 1010 (Two's complement = -6)
    cout << "x after not"<< result << endl;  // Output: -6


    unsigned int y = 5;        // 0000...0101
    unsigned int ans = ~y;  // 1111...1010
    cout << "y after not " << ans << endl;       // Output: 4294967290 (if 32-bit unsigned)


   
    cout << endl << endl;
    return 0;
}

/*

===== output======

5 = after bitwise not : -6
10 = after bitwise not : -11
20 = after bitwise not : -21
x after not-6
y after not 4294967290


*/