/*

Enter the rows : 6

1          1
12        21
123      321
1234    4321
12345  54321
123456654321


*/


#include <iostream>
using namespace std;

void pattern(int);

int main() {
    int Rows;
    cout << "Enter the rows : ";
    cin >> Rows;
    
    cout << endl;
    pattern(Rows); 
    
    return 0;
}

void pattern(int Rows) {
    int copy = 0;
    for(int i = 1; i <= Rows; i++) {
        for(int j = 1; j <= Rows*2; j++) {
            if(j <= i) {
                cout << j;
                copy = j;
            }
            else if(j >= i && j <= Rows*2-i) {
                cout << " ";
            }
            else {
                cout << copy;
                copy--;
            }
        }
        cout << endl;
    }
}