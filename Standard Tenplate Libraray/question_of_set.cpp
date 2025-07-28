// print all unique string 

// sets store keys 
// it stored elements in sorted order 


#include <bits/stdc++.h>
using namespace std;

int main() {

    set <string> s;    // set of strings  
    int n;
    cout << "enter n : ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cout << "enter the string : "; cin >> str;
        s.insert(str);
    }
    
    for(auto value : s) {
        cout << value << endl;
    }
    


    return 0;
}