/*

============ Right Shift ( >> ) Operator ==============

 
>>  Shifts a number to the right by removing the last few binary digits of the number. Each shift by one represents an integer division by 2, so a right shift by k  represents an integer division by 2power(k) or 

*/

#include <iostream>
using namespace std;

int main() {
    cout << endl << endl;

    // Example 1: Right shift with a positive number
    int x = 16;          // Binary: 0001 0000
    int result1 = x >> 1;  // Shift right by 1 → 0000 1000 (8)
    int result2 = x >> 2;  // Shift right by 2 → 0000 0100 (4)

    cout << "x = " << x << endl;
    cout << "x >> 1 = " << result1 << " (Divides by 2)" << endl;
    cout << "x >> 2 = " << result2 << " (Divides by 4)" << endl;

    // Example 2: Right shift with a negative number
    int y = -16;           // Binary (2's complement): 1111 0000
    int result3 = y >> 1;  // Shift right by 1 → implementation-defined (often -8)
    int result4 = y >> 2;  // Shift right by 2 → often -4

    cout << "\ny = " << y << endl;
    cout << "y >> 1 = " << result3 << " (May keep sign bit)" << endl;
    cout << "y >> 2 = " << result4 << " (May keep sign bit)" << endl;

    // Example 3: Right shift with unsigned integer
    unsigned int z = 16;      // Binary: 0001 0000
    unsigned int result5 = z >> 2;  // → 0000 0100 (4)

    cout << "\nunsigned z = " << z << endl;
    cout << "z >> 2 = " << result5 << " (Unsigned always fills left bits with 0)" << endl;

    cout << endl << endl;
    return 0;
}


/*

===== output======

x = 16
x >> 1 = 8 (Divides by 2)
x >> 2 = 4 (Divides by 4)

y = -16
y >> 1 = -8 (May keep sign bit)
y >> 2 = -4 (May keep sign bit)

unsigned z = 16
z >> 2 = 4 (Unsigned always fills left bits with 0)


*/