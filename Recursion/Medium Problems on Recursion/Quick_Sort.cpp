// quick sort
// tc = best and average -> o(nlogn)
// tc = worst = o(n^2)
// sc = O(1) + O(N) auxiliary stack space. that why it is slightly better then merge sort

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // find the first element greater then pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        // find the first element smaller then pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        if (i < j) 
            swap(arr[i], arr[j]);
    }
    // low is pivot
    // j tell us the correct position for the pivot so swap them
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);   // left half
        qs(arr, pIndex + 1, high);  // right half
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    cout << endl << endl;

    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl << endl;
    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// int correctPosition(int &array, int low, int  high){
//     int pivot = array[low];
//     int i = low;
//     int j = high;

//     while(i < j) {
//         while(array[i] <= pivot && i <= high-1) {
//             i++;
//         }

//         while(array[i] > pivot && j >=  high+1 ) {
//             j--;
//         }
//         if(i < j) {
//             swap(array[i], array[j]);
//         }
//     }
//     swap(array[low], array[j]);
//     return j;
// }

// void quickSort(int &array,int low, int high) {
//     if(low < high) {
//         int partition = correctPosition(array, low, high);
//         quickSort(array, low, partition-1);
//         quickSort(array, low, partition+1);
//     }
// }

// int main() {

//     int size;
//     cout << "Enter the size of array : ";
//     cin >> size;
//     int array[size];

//     for(int i = 0; i < size; i++) {
//         cout << "Enter the array element : ";
//         cin >> array[i];
//     }

    
//     quickSort(array, 0, size-1);

//     cout  << endl << "Sorted array is : ";
//     for(int i = 0; i < size; i++) {
//         cout << array[i] << " ";
//     }



//     return 0;
// }