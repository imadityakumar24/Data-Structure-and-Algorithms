// vecotr of vector 
// means rows and column both are dynamic


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
    vector< vector <int> > v;       // vector of vector
    for(int i = 0; i < N; i++) {
        int n;
        cout << "enter n: ";
        cin >> n;
        vector <int> temp;
        for(int j = 0; j < n; j++) {        // iput for rows
            int x;
            cout << "entr x : ";
            cin >> x;
         //   v[i].push_back(x);    // we cant performe this 
            temp.push_back(x);
        }
        v.push_back(temp);          // vector ke andar vector
    }

    for(int i = 0; i < v.size(); i++) {
        printVector(v[i]);
    }
    

    return 0;
}