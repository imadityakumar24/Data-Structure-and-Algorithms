// quick , heap and insertion sort are used in sort libraray 
 // intro sort mixture of 3 sorting algorithm
// complexity in worst case is nlog(n)

// start sort form second element 
// is called intro sort 


#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "enter the size of array : ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << endl
         << "sorted array" << endl;
    // starting address // jaha tak sort karna uska next address
    sort(a, a + n); // a is a pointer of array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " " ;
    }

    return 0;
}