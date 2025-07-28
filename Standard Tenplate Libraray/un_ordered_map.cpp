// unordered map is a data structur  it is like a pair
// it have key and value  both can be any type
// unordered map print values in random oreder 
// internal implementation of unoredered map is used  with hash table 
// keys are unique
// it++  means go to  next iterator
//  it+1 means next location 
// both are working properly in the case in vector // becases vector are continuous in memory
//  but in the case of set and map it+1 not working properly , because set and map are not contionuous in memory
// so use it++
// map mai hum jo kar sakte hai vo hum unsorted_map ke sath bhi kar sakte hai

// ek multi map bhi hota hai

#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> &m){
    cout << "size : " << m.size() << endl;
    for(auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
    cout << endl;
}

int main() {

    unordered_map <int,string> m;         // means int and string values are inserted 
    m[1] = "aditya";           // o(1) time complexityof  insertion and fething  // average case
    m[6] = "sachin";
    m[3] = "vivek";
    m.insert({4, "lovepreet"});

    print(m);




    return 0;
}

