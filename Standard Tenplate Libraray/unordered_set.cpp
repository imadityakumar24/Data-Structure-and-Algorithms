// unordered sets store keys 
// it stored elements in unoreder
// it print elemts in unsorted order
// internal implementation using hash table
// use whem just you want to check that value is present in the set or not and order is not matter

// unordered set mai hum  only basic data types rakh sakte hai complex data type nhi rakh sakte because unki internal hast funtion c++ mai define nhi hai 
// O(1) time complexity of insertion and fetching 

#include <bits/stdc++.h>
using namespace std;

void printSet(unordered_set <string> &s) {
    for(string words : s) {
        cout << words << " " << endl;
    } 
    cout << endl;
    for(auto itForSet = s.begin(); itForSet != s.end(); itForSet++) {
        cout << *itForSet << " " << endl;
    } 
}

void printInterger(unordered_set <int> &integer) {
    for(int i : integer) {
        cout << i << " " <<  endl;
    }
}

int main() {

    unordered_set <string> s;    // set of strings  
    s.insert("aditya");         // O(1) time complexity of insertion and fetching 
    s.insert("abhijeet");
    s.insert("purvi");

    auto it = s.find("aditya");   // it return iterator  // log(n)
    if(it == s.end()) {
        cout << "not present in set";
    }
    else {
        cout << *it <<" is present in set" << endl;
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
    unordered_set <int> integer = {4,5,6,3};
    integer.insert(5);           // it don.t insert this value beacasue  only unique element are present in set and 5 is already present 
    printInterger(integer);
    cout << endl;
    integer.erase(6);         // it delete 6 from the set 
    printInterger(integer);


    return 0;
}