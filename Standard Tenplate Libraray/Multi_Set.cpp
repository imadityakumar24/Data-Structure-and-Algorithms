// elements are not unique means in this we can store same value againa and again
// means dublicate are allowed in multiset
// internal implementation using red black trees
// log(n) time complexity of insertion and fetching 
// multi set print value in lexographical manner means according to increasing alphabets

#include <bits/stdc++.h>
using namespace std;

void printSet(multiset <string> &s) {
    for(string words : s) {
        cout << words << " " << endl;
    } 
    cout << endl;
    for(auto itForSet = s.begin(); itForSet != s.end(); itForSet++) {
        cout << *itForSet << " " << endl;
    } 
}

void printInterger(multiset <int> &integer) {
    for(int i : integer) {
        cout << i << " " <<  endl;
    }
}

int main() {

    multiset <string> s;    // set of strings  
    s.insert("aditya");         // log(n) time complexity of insertion and fetching 
    s.insert("abhijeet");
    s.insert("purvi");
    s.insert("aditya");

    auto it = s.find("aditya");   // it return iterator  // log(n)
    if(it == s.end()) {
        cout << "not present in multiset";
    }
    else {
        cout << *it <<" is present in multiset" << endl;
    }

    auto it1 = s.find("shreya");   // it return iterator  
    if(it1 == s.end()) {
        cout << "not present in set";
    }
    else {
        cout << *it <<" is present in set" << endl;
    }

    cout << endl;  
    auto it2 = s.find("purvi");
    if(it2 != s.end()) {
        cout << (*it) << endl ;
    }
    printSet(s);

    cout << endl;
    multiset <int> integer = {4,5,6,3};
    integer.insert(5);           // 5, 4 is already present in the set but it again insert 4 and 5 because in multiset it is allowed
    integer.insert(4);
    printInterger(integer);
    cout << endl;
    integer.erase(6);         // it delete 6 from the set 
    printInterger(integer);


    return 0;
}