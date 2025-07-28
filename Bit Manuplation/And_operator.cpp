
/*

============ And ( & ) Operator ==============

&  = one and means binary and operator

means convert the decimal number to binary and then perform operation

true & true   = ture
true & false  = false
false & true  = false
false & false = false

1 & 1 = 1
1 & 0 = 0
0 & 1 = 0
0 & 0 = 0

&& = two ans means logical and operator is check both operands conditon should be true



*/

#include <iostream>
using namespace std;

int main() {
    cout << endl << endl;

    int a = 10, b = 14;
    int ans = a & b;

    cout << "( a & b ) is equal to = " << ans << endl;
    cout << "( a & b ) is equal to = " << (15 & 15) << endl;
    cout << "( a & b ) is equal to = " << (13 & 0) << endl;


    if (10 > 0 && 16 < 70) 
        cout << "both conditon true" << endl;
    else 
        cout << "both conditon are not true" << endl;
    

    if (10 > 110 && 16 < 70) 
        cout << "both conditon true" << endl;
    else 
        cout << "both conditon are not true" << endl;


    cout << endl << endl;
    return 0;
}


/*

===== output======

( a & b ) is equal to = 10
( a & b ) is equal to = 15
( a & b ) is equal to = 0
both conditon true
both conditon are not true

*/