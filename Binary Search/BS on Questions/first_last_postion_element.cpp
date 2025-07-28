/*

34. Find First and Last Position of Element in Sorted Array
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                start = i;
                break;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] == target) {
                end = i;
                break;
            }
        }

        return {start, end};
    }
};

/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, middle = 0;

        if (n == 1) {
            if (nums[0] == target)
                return {0, 0};
        } 
        else if (n == 1) {
            if (nums[0] =! target)
                return {-1, -1};
        } 
        else {
            while (left <= right) {
                middle = (left + right) / 2;
                if (nums[middle] == target) {
                    // Check bounds before accessing nums[middle + 1]
                    if (middle + 1 < n && nums[middle + 1] == target)
                        return {middle, middle + 1};
                    // Check bounds before accessing nums[middle - 1]    
                    else if (middle - 1 >= 0 && nums[middle - 1] == target)
                        return {middle - 1, middle};
                    else
                        return {middle, middle};
                } else if (nums[middle] < target)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }

        return {-1, -1};
    }
};
*/