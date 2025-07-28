// map is a data structur  it is like a pair
// it have key and value  both can be any type
// map print values in sorted oreder according to key 
// internal implementation of map  is used red black tree to store data // it is self balancing tree
// keys are unique
// it++  means go to  next iterator
//  it+1 means next location 
// both are working properly in the case in vector // becases vector are continuous in memory
//  but in the case of set and map it+1 not working properly , because set and map are not contionuous in memory
// so use it++


#include <bits/stdc++.h>
using namespace std;

void print(map<int, string> &m){
    cout << "size : " << m.size() << endl;
    for(auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
    cout << endl;
}

int main() {

    map <int,string> m;         // means int and string values are inserted 
    m[1] = "aditya";           // o(logn)  // insertion
    m[6] = "sachin";
    m[3] = "vivek";
    m.insert({4, "lovepreet"});

    map<int, string> :: iterator it;
    for(it = m.begin(); it != m.end(); it++) {   // o(logn)   // printing // accessing
       cout << (*it).first << " " << (*it).second << endl;
    }

    cout << endl;
    for(auto &pr : m) {                        // o(logn)
       cout << pr.first << " " << pr.second << endl;
    }

    cout << endl;

    auto it_map = m.find(3);      // it return iterator // if value is not prensent then it return m.end() 
    if(it_map == m.end()) {
        cout << "No value";
    }
    else {
        cout << (*it_map).first << " " << (*it_map).second << endl;
    }
/*
    cout <<  endl;
    m.erase(3);
    print(m);       // it delete key and string
*/
    cout << endl;
    auto it_3 = m.find(7);
    if(it_3 != m.end()) {
        m.erase(it);
    }

    // m.cleaer();  // it delete the whole map




    return 0;
}

