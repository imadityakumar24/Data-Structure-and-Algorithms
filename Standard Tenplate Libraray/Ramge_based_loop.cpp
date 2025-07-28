 // ranged based loop

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector <int> v = {2,8,4,1,6};

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
   
    vector<int> :: iterator it;
    for(it = v.begin(); it != v.end(); it++) {    // means it mocves the iterator to the next iterator
        cout << (*it) << " ";
    }

    cout << endl;

    for(int value : v) {          // range based loop  // copy is made
        cout << value << " ";
    }

    cout << endl;

    
    for(int &value : v) {          // range based loop  // reference
        cout << value << " ";
        value++;                 // due to this values are incrimented with 1 just print and check
    }

    cout << endl;

    
    for(int value : v) {          // range based loop  // copy is made
        cout << value << " ";
    }

    cout << endl;

    vector< pair<int, int> > v_p = {{5,3}, {6,4}};
    vector<pair<int, int>>::iterator it_pair;                           // Renaming the iterator to avoid conflict
    for ( pair<int, int> &value : v_p) {
        cout << value.first << " " << value.second << endl;
    }

    

    return 0;
}