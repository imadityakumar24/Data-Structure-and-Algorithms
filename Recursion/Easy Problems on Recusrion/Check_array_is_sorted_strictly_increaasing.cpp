
// Check if array is sorted (strictly increasing) using recursion

#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 1) return true;
    if (arr[n - 1] <= arr[n - 2]) return false;
    return isSorted(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 5, 7};
    int n = 5;
    cout << (isSorted(arr, n) ? "Sorted" : "Not Sorted");
    return 0;
}

/*

Output:

Sorted

*/
