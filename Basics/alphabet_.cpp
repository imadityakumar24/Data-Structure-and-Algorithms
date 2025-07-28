/* // output

    A
   ABC
  ABCDE
 ABCDEFG
ABCDEFGHI



*/

#include<iostream>
using namespace std;

void pattern(int N) {
    // this for uper stars
    for(int i = 0; i < N; i++) {
        // this for space
        for(int j = 0; j < N-i-1; j++) {
            cout << " ";
        }
        // this for albhabets
        char ch = 'A';
        for(int j = 0; j < 2*i+1; j++) {

            cout << ch ;
            if(j < (2*i+1)/2 )
                ch++;
            else
                ch--;
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
    cout << "Enter N : ";
    cin >> N;

    cout << endl;
    pattern(N);

    return 0;
}