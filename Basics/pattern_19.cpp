#include <iostream>
using namespace std;

void pattern(int N) {
    int space = 0;
    for(int i = 0; i < N; i++) {
        // star
        for(int j = 0; j < N-i; j++) {
            cout << "*";
        }
        // space
        for(int j = 0; j < space; j++) {
            cout << " ";
        }
        // star
        for(int j = 0; j < N-i; j++) {
            cout << "*";
        }
        space = space + 2;
        cout << endl;
    }   

    int newSpace = 8;
    for(int i = 0; i < N; i++) {
        // star
        for(int j = 0; j <= i; j++) {
            cout << "*";
        }
        // space
        for(int j = 0; j < newSpace; j++) {
            cout << " ";
        }
        // star
        for(int j = 0; j <= i; j++) {
            cout << "*";
        }
        space = space - 2;
        cout << endl;
    }   
}

int main() {

    int N;
    cout << "Enter n : ";
    cin >> N;

    cout << "\n";

    pattern(N);

    return 0;
}


/*

Enter n : 5

**********
****  ****
***    ***
**      **
*        *

*/
/*

void pattern(int N) {
    int space = 0;
    for(int i = 0; i < N*2; i++) {
        // star
        for(int j = 0; j < N-i; j++) {
            cout << "*";
        }
        // space
        for(int j = 0; j < space; j++) {
            cout << " ";
        }
        // star
        for(int j = 0; j < N-i; j++) {
            cout << "*";
        }
        space = space + 2;
        cout << endl;
    }
}

int main() {

    int N;
    cout << "Enter n : ";
    cin >> N;

    cout << "\n";

    pattern(N);

    return 0;

}

*/