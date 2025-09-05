
// Find maximum element in array using recursion

#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    return max(arr[n - 1], findMax(arr, n - 1));
}

int main() {
    int arr[] = {10, 25, 5, 99, 32};
    int n = 5;
    cout << "Max = " << findMax(arr, n);
    return 0;
}

/*

Output:

Max = 99

*/
