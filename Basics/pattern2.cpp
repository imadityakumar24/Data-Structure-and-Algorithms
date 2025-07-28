/*

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

*/


#include <iostream>
using namespace std;

void pattern1() {
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {

    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << endl << "\n";
    pattern1(); 

    return 0;
}