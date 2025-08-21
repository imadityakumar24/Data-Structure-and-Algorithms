/*

18. 4Sum
Solved
Medium
Topics
premium lock icon
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,388,503/3.6M
Acceptance Rate
38.7%

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> result;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hashSet;
                for (int k = j + 1; k < n; k++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k]; // 
                    long long needMore = (long long)target - sum; 
                    if (hashSet.find(needMore) != hashSet.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)needMore};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    } else {
                        hashSet.insert(nums[k]);
                    }
                }
            }
        }

        vector<vector<int>> ans(result.begin(), result.end());
        return ans;
    }
};