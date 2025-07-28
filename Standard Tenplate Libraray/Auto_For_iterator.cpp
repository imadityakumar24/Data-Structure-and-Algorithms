// c++ 11 it is introduced
// auto l=keyword is used // it automatically detect the data type of the variables

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> v = {2, 3, 4, 5, 6};
    /*  
       vector<int> :: iterator it;
       for(it = v.begin(); it != v.end(); it++) {    // means it mocves the iterator to the next iterator
           cout << (*it) << " ";
       }
    */

    // above code is working but if we used auto keyword so we need not to declare the iterator
    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++) {       
        cout << (*it) << " ";                         // means it mocves the iterator to the next iterator
    }

    cout << endl;  
    vector< pair<int, int> > v_p = {{5,3}, {6,4}, {2,8}};
    for (auto &value :v_p) {
        cout << value.first << " " <<value.second << endl;
    }

    return 0;
}