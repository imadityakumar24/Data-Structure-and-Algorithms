/*

53. Maximum Subarray
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
5,275,469/10.1M
Acceptance Rate
52.3%

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curuntSum = 0, maxSum = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            curuntSum += nums[i];
            maxSum = max(maxSum, curuntSum);
            if(curuntSum < 0)
                curuntSum = 0;
        }
        return maxSum;
    }
};

/*  // this is right but it giving the time limit exeded

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum;
        int maxSum = nums[0];
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

*/