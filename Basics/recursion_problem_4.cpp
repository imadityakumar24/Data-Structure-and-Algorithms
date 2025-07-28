// calculate sum of 1 to n natural numbers and return sum , using recursion means baktrackinvlg
// output : 5 to 225 or 7 to 784
#include <bits/stdc++.h>
using namespace std;
void series();

class solution {
public:
    int sum = 0;
    void series(int n) {
        if(n < 0) {
            return;
        }
        series(n-1);
        sum = sum + pow(n, 3);
    }

    int result() {
        return sum+1;
    }
};

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    solution obj;
    obj.series(n);
    int value = obj.result();
    cout << value << endl;

    return 0;
}