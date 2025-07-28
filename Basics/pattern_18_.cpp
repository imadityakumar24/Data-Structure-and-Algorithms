
/* // output is like this 

Enter n : 5

E
DE
CDE
BCDE
ABCDE

*/

#include <iostream>
using namespace std;

void reversedCharacter(int N) {
    for(int i = 0; i < N; i++) {
        int assciValue = 65+N-i-1; // asscivalue of A IS 65 
        for(int j = 0; j <= i; j++) {
            char character = static_cast<char>(assciValue);
            cout << character << " ";
            assciValue++;
        } 
        cout << endl;
    }
}


int main() {

    int N;
    cout << "Enter n : ";
    cin >> N;

    cout << "\n";

    reversedCharacter(N);

    return 0;
}