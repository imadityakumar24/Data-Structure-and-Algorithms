
/*

============ Or ( || ) Operator ==============

| = one or means binary or operator
one true means true
both false mens false
means convert the decimal number to binary and then perform operation

true & true   = ture
true & false  = true
false & true  = true
false & false = false

1 & 1 = 1
0 & 1 = 1
1 & 0 = 1
0 & 0 = 0

|| = two or means logical or operator means from both operand one condition should be true
if first condition is true it don't check second conditon
if first conditionis false then it check second conditon



*/

#include <iostream>
using namespace std;

int main() {
    cout << endl << endl;

    int a = 10, b = 14;
    int ans = a | b;

    cout << "( a | b ) is equal to = " << ans << endl;
    cout << "( a | b ) is equal to = " << (15 | 15) << endl;
    cout << "( a | b ) is equal to = " << (13 | 0) << endl;


    if (10 > 0 || 16 < 70) 
        cout << "one conditon true" << endl;
    else 
        cout << "both conditon are false" << endl;
    

    if (10 > 110 || 16 < 5) 
        cout << "one conditon true" << endl;
    else 
        cout << "both conditon are false" << endl;


    cout << endl << endl;
    return 0;
}


/*

===== output======

( a | b ) is equal to = 14
( a | b ) is equal to = 15
( a | b ) is equal to = 13
one conditon true
both conditon are false


*/