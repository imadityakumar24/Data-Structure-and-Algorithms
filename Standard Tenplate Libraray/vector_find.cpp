// finding the index with the help of vector element


/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << endl << endl;

    vector<int> vec = {10, 20, 30, 40, 50};
    int target = 30;

    // Using find to get iterator position
    auto it = find(vec.begin(), vec.end(), target);

    if (it != vec.end()) {
        int index = distance(vec.begin(), it);
        cout << "Index of " << target << " is: " << index << endl;
    } else {
        cout << target << " not found in the vector." << endl;
    }

    cout << endl << endl;
    return 0;
}

*/



#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << endl << endl;

    vector<int> vec = {10, 20, 30, 40, 50};
    int target = 30;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            cout << "Index of " << target << " is: " << i << endl;
            break;
        }
    }

    cout << endl << endl;
    return 0;
}


