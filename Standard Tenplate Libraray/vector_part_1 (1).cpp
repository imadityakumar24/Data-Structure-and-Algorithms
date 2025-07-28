#include <iostream> 
#include <vector>       // library for vector
using namespace std;

void printVector(vector<int> v) {
    cout << "Size = " << v.size() << endl;      // size() have  O(1) time complexity
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
/*
    vector <int> v;
    int n;
    cout << "Enter n : "; cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);     // O(1) time complexity
    }

    printVector(v);
*/
    cout << endl;

    vector <int> r;
    int s;
    cout << "Enter s : "; 
    cin >> s;
    for(int i = 0; i < s; i++) {
        int a;
        cout << "enter a : ";
        cin >> a;
        printVector(r);
        r.push_back(a);     // O(1) time complexity
    }

    printVector(r);


    return 0;
}