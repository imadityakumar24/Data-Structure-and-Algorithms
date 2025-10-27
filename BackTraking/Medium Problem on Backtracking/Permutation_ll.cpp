/*

47. Permutations II

Solved
Medium
Topics
premium lock icon
Companies
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,185,582/1.9M
Acceptance Rate
62.3%
Topics
Array
Backtracking
Sorting

*/




#include <bits/stdc++.h>
using namespace std;


/*
// Brute force Aproach using recursion
// TC = O(n! * n) n for copy
// SC = O(n) for map + o(n) for stack space
class Solution {
public:
    vector<vector<int>> result;

    void solve(unordered_map<int, int> &mp, vector <int> &temp, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);   // o(n) for copy to result
            return;
        }

        // for (auto &[value, count] : mp) {
        //     if (count == 0) continue;
        //     temp.push_back(value);
        //     mp[value]--;
        //     solve(mp, temp, nums);
        //     temp.pop_back();
        //     mp[value]++;
        // }

        // above and below for loop code is same 

        for (auto &pair : mp) {
            int value = pair.first;
            int count = pair.second;
            if (count == 0) continue;
            temp.push_back(value);
            mp[value]--;
            solve(mp, temp, nums);
            temp.pop_back();
            mp[value]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};

        unordered_map<int, int> mp;
        for (auto &i : nums){
            mp[i]++;
        } 

        vector <int> temp;
        solve(mp, temp, nums);
        return result;
    }
};
*/



// Optimal Aproach using recursion
// TC = O(n! * n) n for copy
// SC = O(n)
class Solution {
public:

    void solve(int idx, vector<int>& nums, vector<vector<int>> &result) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set <int> uniqueSet;
        for (int i = idx; i < nums.size(); i++) {
            // matlab hume value use kiya hua hai , agar phir abhi dublicate value 
            // ko use kiya to same hi result dega , to isliye dublicate value skip kardi
            if (uniqueSet.find(nums[i]) != uniqueSet.end()) {
                continue;
            }
            // new unique value aayi to use kar liya us value ko 
            uniqueSet.insert(nums[i]);
            swap(nums[idx], nums[i]);
            solve(idx+1, nums, result);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;

        solve(0, nums, result);
        
        return result;
    }
};