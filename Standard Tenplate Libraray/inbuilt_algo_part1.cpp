// o(n)  time complexity for all 

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cout << "Enter the size of vector : ";
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int min = *min_element(v.begin(), v.end());     // it return pointer or iterator
    cout << endl <<"min = "<< min;

    int min1 = *min_element(v.begin()+2, v.end());      // means skiping strting 3 elementd
    cout <<  endl <<"min = " << min1;

    int max = *max_element(v.begin(), v.end());      // it return pointer or iterator
    cout << endl << "max = " << max;

    int sum = accumulate(v.begin(), v.end(), 0);        // 0 is an initail sum 
    cout << endl << "Sum is = " << sum;
    int sum_1 = accumulate(v.begin(), v.end(), 5);      // intail sum is 5 and it add vector element with 5
    cout << endl << "Sum is = " << sum_1;

    int apear = count(v.begin(), v.end(), 5);       // 5 is element jiska hum count find kar rhe hai matlab kitni barr vector mai 5 yaya ahai
    cout << endl << apear << " apear in array";

    int element = *find(v.begin(), v.end(), 5);         // 5 is present or not // it return pointer or iterator if presentit print 1 otherwise 0
    cout << endl << element << endl;
 
    auto it = find(v.begin(), v.end(), 2);
    if(it != v.end())
        cout << "present = "<< *it << endl;
    else
        cout << "not found" << endl;


    // reverse
    reverse(v.begin(), v.end());
    for(auto val : v) {
        cout << val << " ";
    }

    string s = "aytida ramuk";
    reverse(s.begin(), s.end());
    cout << endl << s << endl;

    return 0;
}