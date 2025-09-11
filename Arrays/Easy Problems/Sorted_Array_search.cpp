/*

Sorted Array Search
Difficulty: BasicAccuracy: 48.03%Submissions: 367K+Points: 1Average Time: 20m
Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

Examples:

Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.
Input: arr[] = [1, 2, 4, 5, 6], k = 3
Output: false
Exlpanation: Since, 3 is not present in the array, output is false.
Input: arr[] = [2, 3, 5, 6], k = 1
Output: false
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k ≤ 106
1 ≤ arr[i] ≤ 106

Expected Complexities
Company Tags
Paytm

*/


#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) { 
        int found = 0;
        for(int i = 0; i < N; i++) {
            if(arr[i] == K) {
                found = 1;
                break;
            }        
        }
        if(found == 1) 
            return 1;
        else 
            return -1;
    }
};
