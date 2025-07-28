/* // output

1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/

#include <iostream>
using namespace std;

void pattern2() {
    for(int i = 0; i <= 5; i++) {
        for(int j = 1; j <= 5-i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {

    for(int i = 0; i <= 5; i++) {
        for(int j = 1; j <= 5-i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << endl << "\n";

    pattern2(); // calling which is declare aabove

    return 0;
}