/*

90. Subsets II
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,346,088/2.2M
Acceptance Rate
60.3%
Topics
Array
Backtracking
Bit Manipulation

*/


#include <bits/stdc++.h>
using namespace std;


// tc = nlogn + o(2^n)
// sc = 
class Solution {
private:
    void solve(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }
       
        temp.push_back(nums[i]);
        solve(i+1, nums, temp, result);
        temp.pop_back();
        // to skip the same element dublicate
        while (i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        solve(i+1, nums, temp, result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        vector <int> temp;
        sort(nums.begin(), nums.end());
        solve(0, nums, temp, result);
        return result;
    }
};
