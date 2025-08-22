/*

Count increasing Subarrays

Difficulty: EasyAccuracy: 50.27%Submissions: 8K+Points: 2
Given an array arr[] of integers, count the number of subarrays in arr[] which are strictly increasing with size greater or equal to 2. A subarray is a contiguous part of array. A subarray is strictly increasing if each element is greater then it's previous element if it exists.

Examples:

Input: arr[] = [1, 3, 3, 2, 3, 5]
Output: 4
Explanation: Increasing Subarrays are : arr[0,1], arr[3,4], arr[3,5], arr[4,5].
Input: arr[] = [1, 5] 
Output: 1
Explanation:The only Increasing Subarray is arr[0,1].
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 106
1 <= arri <= 107



*/






#include <bits/stdc++.h>
using namespace std;



/*
class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = 0, count = 0;
         
        while (r < n && l <= n-2) {
            if (r == n-1) {
                l++;
            }
            
            while (arr[r] < arr[l]) {
                l++;
            }
            
            int lenth = r - l + 1;
            if (lenth >= 2) {
                count++;
            }
            
            if (r != n-1) {
                r++;
            }
        } 
        
        return count;
    }
};
*/


class Solution {
private:
    int countS(vector<int>& arr, int index) {
        int n = arr.size();
        int l = index, r = n-1, count = 0;
         
        while (l < n) {
            while (arr[l] >= arr[r]) {
                l++;
            }
            
            int lenth = r - l + 1;
            if (arr[r] > arr[l]) {
                if (lenth >= 2) {
                    count++;
                }
            }
        } 
        
        return count;
    }
public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = 0, count = 0;
         
        while (r < n) {
            
            while (arr[l] > arr[r]) {
                l++;
            }
            
            int lenth = r - l + 1;
            if (arr[r] > arr[l]) {
                if (lenth >= 2) {
                    count++;
                }
            }
            
            r++;
        } 
        
        return count + countS(arr, l);
    }
};
