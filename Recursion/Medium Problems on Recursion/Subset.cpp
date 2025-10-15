/*


Code
Testcase
Testcase
Test Result
78. Subsets
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,739,594/3.4M
Acceptance Rate
81.5%

*/




#include <bits/stdc++.h>
using namespace std;


// recursiove solution
// TC = O(2^n)
// SC = o(n)
class Solution {
private: 
    void solve (vector<int>& nums, vector <int>& temp,  vector<vector<int>>& result, int i) {
        if (i >= nums.size()) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        // don't use i++
        solve(nums, temp, result, i+1);     // answer mai le liya or take case of value
        temp.pop_back();
         // don't use i++
        solve(nums, temp, result, i+1);     // answer mai nhi liya or not take case of value
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector <int> temp;
        solve(nums, temp, result, 0);

        return result;
    }
};

/*
// copied solution 
// tc = O(2^n × n)
// sc = O(2^n × n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = { {} };
        for (int i = 0; i < nums.size(); i++) {
            int rSize = result.size();
            for (int j = 0; j < rSize; j++) {
                vector <int> subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }
        return result;
    }
};
*/

/*
Complexity
Time complexity: O(2 
n
 ⋅n)
Each element doubles the number of subsets and copying takes up to O(n) time in worst case.

Space complexity: O(2 
n
 ⋅n)
Because we are storing all possible subsets, each could be of size n.

// C++ implementation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};

        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            for (int j = 0; j < n; j++) {
                vector<int> subset = result[j];
                subset.push_back(nums[i]);
                result.push_back(subset);
            }
        }

        return result;
    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};

        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> newSubsets;
            for (int j = 0; j < result.size(); j++) {
                vector<int> subset = result[j];
                subset.push_back(nums[i]);
                newSubsets.push_back(subset);
            }
            // Add all new subsets to result
            for (int k = 0; k < newSubsets.size(); k++) {
                result.push_back(newSubsets[k]);
            }
        }

        return result;
    }
};

*/