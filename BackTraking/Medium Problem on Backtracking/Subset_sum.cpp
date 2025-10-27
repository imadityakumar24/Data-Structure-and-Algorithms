/*

Subset Sum Problem

Difficulty: MediumAccuracy: 32.0%Submissions: 410K+Points: 4
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104

Expected Complexities
Company Tags
AmazonMicrosoft
Topic Tags
Dynamic ProgrammingAlgorithms

*/




#include <bits/stdc++.h>
using namespace std;


// Giving TLE
// because this is salved using recrusino + dynamic programaing 
// im am not know very well about dp
class Solution {
private:
    bool find(int idx, int sum, vector<int>& arr) {
        if (sum == 0) {
            return true;
        }
        if (idx >= arr.size()) return false;
        bool pick = false, noPick = false;
        // pick
        pick = find(idx+1, sum - arr[idx], arr);
        // no pick
        noPick = find(idx+1, sum, arr);
        return (pick || noPick);
    }
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        return find(0, sum, arr);        
    }
};