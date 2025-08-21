/*

560. Subarray Sum Equals K
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,944,277/4.2M
Acceptance Rate
45.9%

*/


#include <bits/stdc++.h>
using namespace std;


//  tc = O(n * nlogn2) 
//  sc = O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> map;
        int sum = 0, ans = 0;
        map[sum] = 1;

        for(auto i : nums) {
            sum = sum + i;
            int find = sum - k;
            if(map.find(find) != map.end()) {
                ans = ans + map[find];
            }
            map[sum]++;
        }

        return ans;
    }
};


/*
//  tc = O(n ^ 2) 
//  sc = O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum, subArrayCount = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum = sum + nums[j];
                if(sum == k) {
                    subArrayCount += 1;
                   // break;
                }
            }
        }

        return subArrayCount;
    }
};
*/