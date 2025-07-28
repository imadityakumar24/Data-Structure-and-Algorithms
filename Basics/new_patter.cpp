/*

{

            *
          * * *
        * * * * *
      * * * * * * *
    * * * * * * * * *

}

*/


#include <iostream>
using namespace std;


int pattern(int N) {
    for(int i = 0; i < N; i++) {
        // this for space
        for(int j = 0; j < N-i-1; j++) {
            cout << " ";
        }
        // this for stars
        for(int j = 0; j < 2*i+1; j++) {
            cout << "*";
        }
        // this for space
        for(int j = 0; j < N-i-1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {

    int N;
    cout << "Enter n : ";
    cin >> N;

    pattern(N);

    return 0;
}