#include <iostream> 
#include <string>
#include <utility>  // library for pairs

using namespace std;

int main() {

    pair <int, string> p;
    p = make_pair(12, "Aditya");                     // initialization first method
    cout << p.first << "  " << p.second << endl;

    pair <int, string> value;
    value = {12, "Radha"};                          // initialization second method
    cout << value.first << "  " << value.second << endl;

    pair<int, string> myPair = {56, "example"};      // // initialization third method
    cout << myPair.first << "  " << myPair.second << endl;

    pair <int, string> p3 = p;                      // we are copy the pair p tp p3
    cout << p3.first << "  " << p3.second << endl;

    pair <int, string> p4 = p;                      // we are copy the pair p tp p3
    p4.first = 33; 
    p4.second = "Shambhavi";                                  // it don't affect output because here a copy is passing not reference 
    cout << p.first << "  " << p.second << endl;

    pair <int, string> &p5 = p;                      // we are copy the pair p tp p3 // with the help of referenc 
    p5.first = 26;
    p5.second = "Neelanjana";                                    // it  affect output because here we are using  reference 
    cout << p.first << "  " << p.second << endl;
    cout << p5.first << "  " << p5.second << endl << endl;

    int a[3] = {1,2,3};
    int b[3] = {2,3,4};
    pair <int, int> pArray[3];              // pairs of array
    pArray[0] = {1, 2};
    pArray[1] = {2, 3};
    pArray[2] = {3, 4};
    for(int i = 0; i < 3; i++) {
        cout << pArray[i].first << "  " << pArray[i].second << endl;
    }

    cout << endl;

 //   int a[3] = {1,2,3};
 //   int b[3] = {2,3,4};
    pair <int, int> pArr[3];              // pairs of array
    pArr[0] = {1, 2};
    pArr[1] = {2, 3};
    pArr[2] = {3, 4};
    swap(pArr[0], pArr[2]);
    for(int i = 0; i < 3; i++) {           // swapping
        cout << pArr[i].first << "  " << pArr[i].second << endl;
    }

    cout << endl;

    pair <int, string> v;
    cout << "enter the integer : ";
    cin >> v.first;
    cout << "enter the string : ";
    cin >> v.second;

    cout << v.first << "  " << v.second << endl;



    return 0;
}