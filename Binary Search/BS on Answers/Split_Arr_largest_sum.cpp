/*

410. Split Array Largest Sum
Solved
Hard
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)

*/




#include <bits/stdc++.h>
using namespace std;


// tc = o(long) + o(n)
// sc = o(1)
class Solution {
private:
    int findNoOfSpiletedArrays(vector<int>& nums, int barrier) {
        int n = nums.size();
        int noOfSpilts = 1, totalSum = 0;
        for (int i = 0; i < n; i++) {
            if (totalSum + nums[i] <= barrier) {    // if this fail start with new 
                totalSum = totalSum + nums[i];
            } 
            else {
                noOfSpilts++; 
                totalSum = nums[i];
            }
        }
        return noOfSpilts;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high  = accumulate(nums.begin(), nums.end(), 0);
        if (k > n) return -1;
        if (k == n) return *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (findNoOfSpiletedArrays(nums, mid) <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};