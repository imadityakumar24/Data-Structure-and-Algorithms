// log(n)  for both uper and lower bound

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "enter the size of array : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // array and vectors should be in sorted order
     cout << endl
    << "sorted array" << endl;
    // starting address // jaha tak sort karna uska next address
    sort(a, a + n); // a is a pointer of array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    cout << endl;
    int *ptr = lower_bound(a, a+n, 6);  // agar element prsent mhi hoga to uska agla wala element return kar degaa
    if(ptr == (a+n) ){
        cout << "not found";
        return 0;
    }
    cout << *ptr << endl;

    cout << endl;
    int *ptr1 = upper_bound(a, a+n, 5);  // jo element pass krenge uska agla element hi return krega 
    if(ptr1 == (a+n) ){
        cout << "not found"; 
        return 0;
    }
    cout << *ptr1 << endl;

     cout << endl;
    int *ptr2 = upper_bound(a, a+n, 10);  // jo element pass krenge uska agla element hi return krega 
    if(ptr2 == (a+n) ){
        cout << "not found"; 
        return 0;
    }
    cout << *ptr2 << endl;
  

    return 0;
}