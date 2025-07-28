// sets store keys 
// it stored elements in sorted order 
// it is ordered set 
// interanl implementation using red blsck tree which are self balancing tree
// log(n) time complexity of insertion and fetching 
// if dublicates are present then find return first element iterator
// if dubllicate id present and if we pass element in eras it erase all the dublicate
// set print value in lexographical manner means according to increasing alphabets


#include <bits/stdc++.h>
using namespace std;

void printSet(set <string> &s) {
    for(string words : s) {
        cout << words << " " << endl;
    } 
    cout << endl;
    for(auto itForSet = s.begin(); itForSet != s.end(); itForSet++) {
        cout << *itForSet << " " << endl;
    } 
}

void printInterger(set <int> &integer) {
    for(int i : integer) {
        cout << i << " " <<  endl;
    }
}

int main() {

    set <string> s;    // set of strings  
    s.insert("aditya");         // log(n) time complexity of insertion and fetching 
    s.insert("abhijeet");
    s.insert("purvi");
    s.insert("purvi");    // dublicates are allowed

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
        cout << (*it) << " yes yes i am present" << endl ;
    }

    printSet(s);

    cout << endl;
    set <int> integer = {4,5,6,3};
    integer.insert(5);           // it don.t insert this value beacasue  only unique element are present in set and 5 is already present 
    printInterger(integer);
    integer.erase(6);   
    cout << endl;      // it delete 6 from the set 
    printInterger(integer);

    cout << endl;

    int n = 5; int m = 5;
    int arr1[n] = {1,2,3,4,5};
    int arr2[m] = {1,2,3,6,7};
    set <int> unique;
    for(int i = 0; i < n; i++) {
        unique.insert(arr1[i]);
    }

    // int total = accumulate(unique.begin(), unique.end(), 0);
    // cout << "total = " << total << endl;

    for(int i = 0; i < m; i++) {
        unique.insert(arr2[i]);
    }

    // printing set
    for(int i : unique) {
        cout << i << " ";
    }

    cout << endl << endl;

    return 0;
}