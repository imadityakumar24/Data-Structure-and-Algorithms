// recursion basic problem
// tc = bogo n
// sc = bigo n
#include <bits/stdc++.h>
using namespace std;

void name(int i, int n ) {
    if(i > n)
        return;
    cout << "raj" << endl;    
    name(i+1, n);    
}

int main() {
    int i, n;
    cout << "enter i : ";
    cin >> i;
    cout << "enter n : ";
    cin >> n;

    name(i, n);

    return 0;
}