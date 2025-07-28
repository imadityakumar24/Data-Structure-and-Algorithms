/* here n = 5 // output

Output: 

****
* *
* *
****

Sample Output 2 :
*****
*   *
*   *
*   *
*****
*/


#include <iostream>
using namespace std;

void newPattern(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1) // this is for outside this printing star in boundries only
                cout << "*";
            else
                cout << " ";    
        }
        cout << "\n";
    }
}

int main() {

    int n = 10;
    newPattern(n);

    return 0;
}