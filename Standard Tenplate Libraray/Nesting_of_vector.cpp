// vectors of pairs


#include <iostream> 
#include <vector>       // library for vector
using namespace std;
 
void printVector(vector<pair<int, int>> & v){
    cout << "vector size is : " << v.size() << endl;
    for(int i= 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}

int main() {

    vector < pair<int, int> > v = { {1,2}, {5,6}, {8, 7} };   // vector ka har ek element pair hoga
    printVector(v);

    cout << endl;

    vector< pair <int, int> > A;
    int size;
    cout << "Enter size of vector : ";
    cin >> size; 
    cout << "input pairs" << endl;
    for(int i= 0; i < size; i++) {
       int value_1, value_2;
       cout << "enter pair first value : ";
       cin >> value_1;
       cout << "enter pair second value : ";
       cin >> value_2;
       A.push_back( {value_1, value_2} );   // both are same
     //  A.push_back( make_pair(x, y) );
    }
    printVector(A);
    
    return 0;
}