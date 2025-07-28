/*

hello World!
enter N : 7

*******
 ******
  *****
   ****
    ***
     **
      *

*/



#include<iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    int N = 0;
    cout << "enter N : ";
    cin >> N;
    cout << endl;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j < i) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}