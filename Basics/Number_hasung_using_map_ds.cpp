#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[8] = {2, 4, 6, 5, 1, 2, 2, 4};
    unordered_map<int, int> frequency;

    for(int i = 0; i < 8; ++i) {
        frequency[arr[i]]++;
    }

    for(auto &pair : frequency) {
        cout << "Element " << pair.first << " occurs " << pair.second << " times." << endl;
    }

    return 0;
}

/*

Element 2 occurs 3 times.
Element 4 occurs 2 times.
Element 6 occurs 1 time.
Element 5 occurs 1 time.
Element 1 occurs 1 time.

*/