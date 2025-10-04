#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------------------
//  CASE 1: Pivot = FIRST ELEMENT
//-------------------------------------------------------------
int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];  //  Pivot chosen as FIRST element
    int i = low + 1, j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low && arr[j] > pivot) j--;
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    swap(arr[low], arr[j]); // place pivot in correct position
    return j; // return pivot index
}

void quickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionFirst(arr, low, high);
        quickSortFirst(arr, low, p - 1);
        quickSortFirst(arr, p + 1, high);
    }
}

//-------------------------------------------------------------
//  CASE 2: Pivot = MIDDLE ELEMENT
//-------------------------------------------------------------
int partitionMiddle(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int pivot = arr[mid];  //  Pivot chosen as MIDDLE element
    int i = low, j = high;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    return i; // return partition index
}

void quickSortMiddle(int arr[], int low, int high) {
    if (low < high) {
        int index = partitionMiddle(arr, low, high);
        quickSortMiddle(arr, low, index - 1);
        quickSortMiddle(arr, index, high);
    }
}

//-------------------------------------------------------------
//  CASE 3: Pivot = LAST ELEMENT
//-------------------------------------------------------------
int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];  //  Pivot chosen as LAST element
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // place pivot in correct position
    return i + 1;
}

void quickSortLast(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionLast(arr, low, high);
        quickSortLast(arr, low, p - 1);
        quickSortLast(arr, p + 1, high);
    }
}

//-------------------------------------------------------------
// Utility Function: Print Array
//-------------------------------------------------------------
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

//-------------------------------------------------------------
//  MAIN FUNCTION
//-------------------------------------------------------------
int main() {
    cout << "\n\n";

    int arr[] = {9, 4, 7, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    cout << "Original Array: ";
    printArray(arr, n);

    cout << "\nChoose Pivot Method:\n";
    cout << "1. First Element\n";
    cout << "2. Middle Element\n";
    cout << "3. Last Element\n";
    cout << "\nEnter choice (1-3): ";
    cin >> choice;

    int arrCopy[n];
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];

    switch (choice) {
        case 1:
            //  Pivot selection: arr[low]
            quickSortFirst(arrCopy, 0, n - 1);
            cout << "\nSorted using Pivot = First Element:\n";
            printArray(arrCopy, n);
            break;

        case 2:
            //  Pivot selection: arr[(low + high) / 2]
            quickSortMiddle(arrCopy, 0, n - 1);
            cout << "\nSorted using Pivot = Middle Element:\n";
            printArray(arrCopy, n);
            break;

        case 3:
            //  Pivot selection: arr[high]
            quickSortLast(arrCopy, 0, n - 1);
            cout << "\nSorted using Pivot = Last Element:\n";
            printArray(arrCopy, n);
            break;

        default:
            cout << "Invalid choice!\n";
    }

    cout << "\n\n";
    return 0;
}



/*

===========  OUTPUT  ==============

Original Array: 9 4 7 3 10 5 

Choose Pivot Method:
1. First Element
2. Middle Element
3. Last Element

Enter choice (1-3): 3

Sorted using Pivot = Last Element:
3 4 5 7 9 10

*/