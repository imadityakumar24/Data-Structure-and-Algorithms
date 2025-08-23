/*

2461. Maximum Sum of Distinct Subarrays With Length K

Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
222,088/520.7K
Acceptance Rate
42.7%


*/







#include <bits/stdc++.h>
using namespace std;



// optimal solution
// used : sliding window and set 
// tc = o(2n)
// sc = 0(n) for set
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        long long int windowSum = 0, maxSum = LLONG_MIN;
        unordered_set <int> st;

        while (r < n) {
            // auto it = st.find(nums[r]);
            // if (it == st.end()) {
            //     st.insert(nums[r]);
            //     windowSum += nums[r];
            // }
            // else {
            //     windowSum = windowSum - nums[l];
            //     st.erase(nums[l]);
            //     l++;
            // }

            while (st.find(nums[r]) != st.end()) {
                windowSum = windowSum - nums[l];
                st.erase(nums[l]);
                l++;
            }

            st.insert(nums[r]);
            windowSum += nums[r];

            if (r - l + 1 == k) {
                maxSum = max(maxSum, windowSum);
                windowSum = windowSum - nums[l];
                st.erase(nums[l]);
                l++;
            }
            r++;
        }

        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};



/*
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long currSum = 0, MaxSum = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            currSum += nums[right];

            // Shrink window if a duplicate is found
            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                currSum -= nums[left];
                left++;
            }

            // Check for valid subarray of size k
            if (right - left + 1 == k) {
                MaxSum = max(MaxSum, currSum);

                // Slide the window forward
                freq[nums[left]]--;
                currSum -= nums[left];
                left++;
            }
        }
        return MaxSum;
    }
};
*/