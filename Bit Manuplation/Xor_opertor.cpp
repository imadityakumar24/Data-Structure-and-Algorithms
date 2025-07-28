
/*

============ Xor ( ^ ) Operator ==============

number of one's are even = 0
number of one's are odd  = 1

means convert the decimal number to binary and then perform operation

1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1
0 ^ 0 = 0


*/

#include <iostream>
using namespace std;

int main() {
    cout << endl << endl;

    int a = 10, b = 14;
    int ans = a ^ b;

    cout << "( a ^ b ) is equal to = " << ans << endl;
    cout << "( a ^ b ) is equal to = " << (15 ^ 15) << endl;
    cout << "( a ^ b ) is equal to = " << (13 ^ 0) << endl;


    cout << endl << endl;
    return 0;
}


/*

===== output======

( a ^ b ) is equal to = 4
( a ^ b ) is equal to = 0
( a ^ b ) is equal to = 13


*/