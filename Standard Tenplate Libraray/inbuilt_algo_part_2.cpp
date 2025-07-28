// all of
// none of
// any of
// it return true false 
// lambda funtion 

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

    cout << [](int x){return x+2;}(2) << endl ;  // lambda funtion
    cout << [](int a, int b){return a + b;}(2, 5) << endl;  // lambda funtion

    auto sum = [](int p, int q){return p + q;};
    cout << sum(7,9)  << endl;
    cout << sum(1,9) << endl;
    cout << sum(3,4) << endl << endl;

    cout << "all_of funtion" << endl;  // means all condition should true
    vector <int> v ={1,3,4};
    cout << all_of(v.begin(),  v.end(), [](int x){return x > 0;}) << endl;  // 1 means all elemnt are greaater then 0

    vector <int> a ={1,-3,4};
    cout << all_of(a.begin(),  a.end(), [](int b ){return b > 0;}) << endl;  // 0 means some elemnt are less then 0

    cout << "any_of funtion" << endl;
    // any_of means agar ek bhi true haito true return kar dega like ( or gate ) digital electronics
    vector <int> s ={1,-3,4};
    cout << any_of(s.begin(),  s.end(), [](int d ){return d > 0;}) << endl;
    
    vector <int> z ={-2,-3,-4};
    cout << any_of(z.begin(),  z.end(), [](int n ){return n > 0;}) << endl;  // 0

    //  means ye wala true ko false banata hai and false ko true
    cout << "none_of funtion" << endl;
    vector <int> w ={1,-3,4};
    cout << none_of(w.begin(),  w.end(), [](int e ){return e > 0;}) << endl;
    
    vector <int> n ={-2,-3,-4};  
    cout << none_of(n.begin(),  n.end(), [](int k ){return k > 0;}) << endl;  

    vector <int> k ={9,6,5};
    cout << none_of(k.begin(),  k.end(), [](int m ){return m > 0;}) << endl;  


    return 0;
}    
