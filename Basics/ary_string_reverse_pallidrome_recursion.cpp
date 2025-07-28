#include <bits/stdc++.h>
using namespace std;

bool pallidrome(int i, string &name) {
    if(i >= name.size()/2 ) 
        return true;
    if(name[i] != name[name.size()-i-1]) 
        return false;
    return pallidrome(i+1, name);  //it return true or false

   //  pallidrome(i+1, name);     // error
}

int main() {

    string name;
    getline(cin, name);

    cout << pallidrome(0, name);

    return 0;
}

/*

int main() {

    string name;
    getline(cin, name);
   // string copy[name.size()];
  // string copy(); // error
  //  string copy[6]; // error
  //  string copy(6); // eeror
   // string copy; //error
  //  string copy(name.size()); // error
   string copy(name.size(), ' '); 

    for(int i = name.size()-1; i >= 0; i--) {
        copy[name.size()-1-i] = name[i];
        cout << copy[name.size()-1-i];
    }

    cout << endl;

    if(name == copy)
        cout << "true" << endl;
    else 
        cout << "false" << endl;    


    return 0;
}

*/


/* // reversing the tring using recursion


void reverseString(string s, int n) {
    if(n < 0) {
        return;
    }
    cout << s[n] << " ";
    reverseString(s, n-1);
   //  reverseString( n-1); // showing error
}
 
int main() {

    string name = "Aditya kumar";
    int size = name.size()-1;

    reverseString(name, size);


    return 0;
}

*/

/*

void reverseArray(int i, int arr[], int n) {
    if(i >= n/2) {
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverseArray(i+1, arr, n);
}

int main() {

    int n; 
    cout << "enter the size of array : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i] ;
    }

    reverseArray(0, arr,n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}

*/