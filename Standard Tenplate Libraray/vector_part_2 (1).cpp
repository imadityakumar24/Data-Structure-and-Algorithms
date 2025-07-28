// when we pass copy it takes o(n) time
// when we pass reference it takes o(1) time   // prefered this

#include <iostream> 
#include <vector>       // library for vector
using namespace std;

void printVector(vector<int> &v) {
    cout << "Size = " << v.size() << endl;      // size() have  O(1) time complexity
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    vector <int> v(5);      // size of vector is 5 
    printVector(v);
    v.push_back(11);        // adding value in last    // time complexity O(1)
    printVector(v);

    vector <int> p(5, 7);      // means assigning all vector elemts with 7 and 5 is the size of vector
    printVector(p);
    
    vector <int> a;
    a.push_back(44);
    a.push_back(55);
    a.pop_back();          // removing last element from vector    // time complexity O(1)
    printVector(a);

    cout << endl;
    vector <int> b = p;         // copy the vector p to b    // time complexity O(n)
    printVector(b);

    cout << endl;

    vector <int> A;
    A.push_back(2);
    A.push_back(5);

    vector <int> &A2 = A;
    A2.push_back(8);
    printVector(A);
    printVector(A2);




    return 0;
}