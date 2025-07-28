// iteratos are like pointer

// it++  means go to  next iterator
//  it+1 means next location 
// both are working properly in the case in vector , becases vector are continuous in memory

//  but in the case of set and map it+1 not working properly , because set and map are not contionuous in memory
// so use it++


#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector <int> v = {2,3,4,5,6};
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    vector<int> :: iterator it = v.begin();         //  begin it poiniting to first element
    cout << "vector  element : " << (*it) << endl;
    cout << "vector  element : " << (*it+1) << endl; 
    cout << "vector  element : " << (*it+2) << endl;
    cout << "vector  element : " << (*it+3) << endl;
    cout << "vector  element : " << (*it+4) << endl;

 //   it = v.end(); //  it point to to next location of the last element
/*
    for(it = v.begin(); it != v.end(); ++it) {    // ++it se iterator next iterator pe jata hai
        cout << (*it) << " ";
    }
*/
    // both are same

    for(it = v.begin(); it != v.end(); it++) {    // means it moves the iterator to the next iterator
        cout << (*it) << " ";
    }

    cout << endl;
    
    vector< pair<int, int> > v_p = {{5,3}, {6,4}, {2,8}};
    vector<pair<int, int>>::iterator it_pair;                           // Renaming the iterator to avoid conflict
    for (it_pair = v_p.begin(); it_pair != v_p.end(); ++it_pair) {
        cout << (*it_pair).first << " " << (*it_pair).second << endl;
    }

    cout << endl; // both are same little bit syntax is different

    for (it_pair = v_p.begin(); it_pair != v_p.end(); ++it_pair) {
        cout << (it_pair->first) << " " << (it_pair->second) << endl;
    }

    
    

    return 0;
}