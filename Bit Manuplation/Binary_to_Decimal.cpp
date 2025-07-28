
/*

Why it works:
Characters like '0', '1' have ASCII values.

'0' → ASCII 48

'1' → ASCII 49

So:

'1' - '0' = 49 - 48 = 1
'0' - '0' = 48 - 48 = 0

*/

// tc = o(lenth of string) 
// sc = o(1)

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int binaryToDecimal(string binary) {
    int ans = 0, n = binary.size();
    int power = 1;

    for (int i = n-1; i >= 0; i--) {
        int bit = binary[i] - '0';  // Convert char to int
        ans += bit * power;
        power = power * 2;
    }

    return ans;
}

int main() {
    cout << endl << endl;

    string binary = "1011";
    int ans = binaryToDecimal(binary);
    cout << binary << " in decimal    : " << ans << endl;              // integer return type
    cout << "1101010" << " in decimal : " << binaryToDecimal("1101010") << endl;              // integer return type
    

    cout << endl << endl;
    return 0;
}

/*

===== output======

10 in binary : 1010
10 in binary : 1010

*/

