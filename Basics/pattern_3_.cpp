/* // output

*****
****
***
**
*

*/


#include <iostream>
using namespace std;

void pattern2() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 0; j <= 5-i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

int main() {

    for(int i = 1; i <= 5; i++) {
        for(int j = 0; j <= 5-i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << endl << "\n";
    pattern2(); 

    return 0;
}