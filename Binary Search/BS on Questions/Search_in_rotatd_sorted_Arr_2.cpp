/*

81. Search in Rotated Sorted Array II
Solved
Medium
Topics
premium lock icon
Companies
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

*/



#include <bits/stdc++.h>
using namespace std;

// worst case , tc = O(n/2)
// Average = o(long)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, middle = 0;

        while (left <= right) {
            middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                return true;
            }
            // shrinking the search space of the array id helps to identify which part is sorted 
            if (nums[left] == nums[middle] && nums[middle] == nums[right]) { 
                left = left + 1;
                right = right - 1;
                continue;
            }

            if (nums[left] <= nums[middle] ) {
                if(nums[left] <= target && target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
            else {
                if (nums[middle] < target && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }

            }                     
        }

        return false;
    }
};