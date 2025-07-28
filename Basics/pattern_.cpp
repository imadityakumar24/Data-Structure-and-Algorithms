#include <iostream>
using namespace std;

int pattern();
int pattern1();
int pattern2();

int main() {

    pattern();
    cout << "\n";
    pattern1();
    cout << endl;
    pattern2();

    return 0;
}

int pattern() {
    for(int row = 0; row<5; row++) {
        for(int column = 0; column<5; column++) {
            cout <<" * ";
        }
        cout << endl;
    }
}

//cout << endl;


int pattern1() {
    for(int row = 0; row<5; row++) {
        for(int column = 0; column<=row; column++) {
            cout <<" * ";
        }
        cout << endl;
    }
}

int pattern2() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " " ;
        }
        cout << endl;
    }
}


