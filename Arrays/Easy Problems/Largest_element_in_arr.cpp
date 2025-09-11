/*

Largest Element in Array
Difficulty: BasicAccuracy: 67.48%Submissions: 504K+Points: 1Average Time: 20m
Given an array arr[]. The task is to find the largest element and return it.

Examples:

Input: arr[] = [1, 8, 7, 56, 90]
Output: 90
Explanation: The largest element of the given array is 90.
Input: arr[] = [5, 5, 5, 5]
Output: 5
Explanation: The largest element of the given array is 5.
Input: arr[] = [10]
Output: 10
Explanation: There is only one element which is the largest.
Constraints:
1 <= arr.size()<= 106
0 <= arr[i] <= 106

*/




#include <bits/stdc++.h>
using namespace std;

// recursive solution
// brute force solution
// tc = o(n)
// sc = o(1)
class Solution {
private:
    int largestElement(vector<int> &arr, int index, int lElement) {
        if (arr.size() == index) 
            return lElement; 
        
        if (arr[index] > lElement) {
            lElement = arr[index];
        }
        return largestElement(arr, index + 1, lElement);
    }
public:
    int largest(vector<int> &arr) {
        if (arr.size() == 1) return arr[0];
        return largestElement(arr, 1, arr[0]);
    }
};
