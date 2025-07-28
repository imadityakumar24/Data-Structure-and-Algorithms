/* // this is the output 

// is question ko solve krne ke liye Maine dekha ki jo hamari even rows hai vha pehle 0 print hoga phir 1 to maine even row ko check karne ke liye i ko 1 se start Kiya hai then I ko 2 ke sath modulus krke dekha hai ki row even hai ya odd 
Enter n : 5

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1


*/


#include <iostream>
using namespace std;

void pattern(int N) {
    for(int i = 1; i <= N; i++) {
        if(i % 2 == 0) { // if i value is even so first print 0 otherwise print 1
            int number = 0; // this for print 0 and 1 agar row even Hui to pehle 0 print hoga otherwise odd row hai to 1 print hoga 
            for(int j = 0; j < i; j++) {
                cout << number << " ";
                if(number == 0)
                    number = 1;
                else
                    number = 0;    
            }
            cout << endl;
        }
        else {
            int number = 1;
            for(int j = 0; j < i; j++) {
                cout << number << " ";
                if(number == 0)
                    number = 1;
                else
                    number = 0;    
            }
            cout << endl;
        }
    }
}

int main() {

    int N;
    cout << "Enter n : ";
    cin >> N;
    
    cout << endl;
    pattern(N);

    return 0;
}

