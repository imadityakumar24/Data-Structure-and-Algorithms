// rows are fixed
// columns are dynamic
// it is like 2d array


#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
    cout << "size : " << v.size() << endl;
    for(int i= 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    int N;
    cout << "enter N: ";
    cin >> N;
    vector <int> v[N];    // array of vector means har ek vector element ek array hai
    for(int i = 0; i < N; i++) {
        int size;
        cout << "enter size of individual array: ";
        cin >> size;
        for(int j = 0; j < size; j++) {  // input individual vector element 
            int x;
            cout << "entr array element : ";
            cin >> x;
            v[i].push_back(x);
        }
    }

    for(int i = 0; i < N; i++) {  // it print individual array of vector 
        printVector(v[i]);
    }

    

    return 0;
}