/*

46. Permutations
Solved
Medium
Topics
premium lock icon
Companies
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,813,059/3.5M
Acceptance Rate
81.2%


*/




#include <bits/stdc++.h>
using namespace std;


/*
// Aproach 1
// solving this question using set data struture
// in unordered set find operation takes o(1) tc
// TC = O(N! * N)
// SC = O(n × n!)
class Solution { 
// private:
    void solve(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, set <int> st) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0 ; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums, result, temp, st);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }   

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        vector <int> temp;
        set <int> st;

        solve(nums, result, temp, st);
        
        return result;
    }
};
*/


// Aproach 2 using swaping method 
// more cleaner code
// TC = O(n × n!)
// SC = O(n!) + o(n) for stack sapce
class Solution { 

    void solve(int idx, vector<int>& nums, vector<vector<int>> &result) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            solve(idx+1, nums, result);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;

        solve(0, nums, result);
        
        return result;
    }
};







/*
// brute force solution
// tc = n! *o(n)
// sc = o(n) + o(n)
class Solution {
private:
    void recurPermute(vector<int> &ds, vector<int>& nums, vector<vector<int>> &ans, vector <int> freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (freq[i] == false) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }  
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> freq(nums.size(), 0);
        vector <int> ds;
        recurPermute(ds, nums, ans, freq);
        return ans;
    }
};
*/



/*
// optimal solution 
// in ths solution we are not using extra space 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
    
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }    
};


*/