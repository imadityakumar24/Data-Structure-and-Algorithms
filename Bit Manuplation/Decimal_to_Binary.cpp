
// tc = o(logn) 
// sc = o(1)

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int decialToBinar(int n) {
    string ans = "";

    while (n > 0) {
        if (n % 2 == 1) 
            ans = ans + "1";
        else 
            ans = ans + "0";

        n = n / 2;    
    }

    reverse(ans.begin(), ans.end());
    return stoi(ans);
}

string deciToBin(int n) {
    string ans = "";

    while (n > 0) {
        if (n % 2 == 1) 
            ans = ans + "1";
        else 
            ans = ans + "0";

        n = n / 2;    
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << endl << endl;

    int decimal = 10;
    int ans = decialToBinar(decimal);
    cout << decimal << " in binary : " << ans << endl;              // integer return type
    cout << decimal << " in binary : " << deciToBin(10) << endl;    // string return type

    cout << endl << endl;
    return 0;
}

/*

===== output======

10 in binary : 1010
10 in binary : 1010

*/