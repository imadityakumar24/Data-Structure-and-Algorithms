/* // output

nter N : 5

*****
****
***
**
*
*
**
***
****
*****


*/

#include<iostream>
using namespace std;

void pattern(int N) {
    // this for uper stars
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}


int main() {
    int N;
    cout << "Enter N : ";
    cin >> N;

    cout << endl;
    pattern(N);

    return 0;
}