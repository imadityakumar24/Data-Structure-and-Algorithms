/*

============ Left Shift ( << ) Operator ==============

 
<<  Shifts a number to left by appending zero digits. In similar fashion to a right shift by  
k , a left shift by  k represents a multiplication by 2powerk

*/

#include <iostream>
using namespace std;

int main() {
    cout << endl << endl;

    // Example 1: Left shift with a positive number
    int x = 4;            // Binary: 0000 0100
    int result1 = x << 1; // Shift left by 1 → 0000 1000 (8)
    int result2 = x << 2; // Shift left by 2 → 0001 0000 (16)

    cout << "x = " << x << endl;
    cout << "x << 1 = " << result1 << " (Multiplies by 2)" << endl;
    cout << "x << 2 = " << result2 << " (Multiplies by 4)" << endl;

    // Example 2: Left shift with a negative number
    int y = -4;           // Binary (2's complement): 1111 1100
    int result3 = y << 1; // Shift left by 1 → becomes more negative (usually)
    int result4 = y << 2; // Shift left by 2

    cout << "\ny = " << y << endl;
    cout << "y << 1 = " << result3 << " (May become more negative)" << endl;
    cout << "y << 2 = " << result4 << " (May become more negative)" << endl;

    // Example 3: Left shift with unsigned integer
    unsigned int z = 4;          // Binary: 0000 0100
    unsigned int result5 = z << 2; // → 0001 0000 (16)

    cout << "\nunsigned z = " << z << endl;
    cout << "z << 2 = " << result5 << " (Unsigned, fills right bits with 0)" << endl;

    cout << endl << endl;
    return 0;
}


/*

===== output======

x = 4
x << 1 = 8 (Multiplies by 2)
x << 2 = 16 (Multiplies by 4)

y = -4
y << 1 = -8 (May become more negative)
y << 2 = -16 (May become more negative)

unsigned z = 4
z << 2 = 16 (Unsigned, fills right bits with 0)


*/
