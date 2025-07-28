// default  logic is to print array in asending order
// butwe can easily change the behaviour using comparator funtion


/*

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }

    cout << endl;

    for(int i =0; i < n; i++){
        for(int j =i+1; j < n; j++){  // O(N^2)
          //  if(a[i] > a[j]) {        // due to this our array sort in asending order
             if(a[i] < a[j]) {      // due to this our array sort in decending order
                swap(a[i], a[j]);
            }
        }
    }

    cout << endl;
    for(int i = 0; i< n; i++) {
       cout <<  a[i] << " ";
    }


    return 0;
}

*/


#include <bits/stdc++.h>
using namespace std;

/* // increasing order

bool should_I_Swap(int a, int b) {
    if(a > b) {
        return true;
    }
    return false;
}

*/

 // decreasong order

bool should_I_Swap(int a, int b) {
    if(a < b) {
        return true;
    }
    return false;
}

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i< n; i++) {
        cin >> a[i];
    }

    cout << endl;

    for(int i =0; i < n; i++){
        for(int j =i+1; j < n; j++){
            if( should_I_Swap(a[i], a[j]) ){        // this is comparator funtion
                swap(a[i], a[j]);
            }
        }
    }

    cout << endl;
    for(int i = 0; i< n; i++) {
       cout <<  a[i] << " ";
    }


    return 0;
}