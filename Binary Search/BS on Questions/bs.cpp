
#include <bits/stdc++.h>
using namespace std;
/*
int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
*/

int binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left <= right) { // Fix loop condition
        int middle = (left + right) / 2;
        if (nums[middle] == target) 
            return middle; // Return immediately if found
        else if (nums[middle] < target) 
            left = middle + 1; // Move to the right half
        else 
            right = middle - 1; // Move to the left half
    }

    return -1; // Return -1 if not found
}

int main() {
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    // vector<int> a = {3, 4, 5, 7, 9, 12, 16, 17};
    int targe = 6;
    int ind = binarySearch(a, targe);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;
    return 0;
}


