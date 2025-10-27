/*

39. Combination Sum
Solved
Medium
Topics
premium lock icon
Companies
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,814,088/3.7M
Acceptance Rate
75.5%

*/



#include <bits/stdc++.h>
using namespace std;


/*
// method 1
// Recursive Solution
// TC = O(N (T/M))Where N Is The Number Of Candidates, T Is The Target, And M Is The Minimum Value Among The Candidates
// SC = O(T/M) Where T Is The Target And M Is The Minimum Value Among The Candidates
class Solution {
private:
    void makeCombination(int index, int sum, int target, vector<int>& candidates, vector <int> &combo, vector<vector<int>> &result) {
        if (sum == target) {
            result.push_back(combo);
            return;
        }

        if (index >= candidates.size() || sum > target) {
            return;
        }

        combo.push_back(candidates[index]);
        // signle element ko bar bar add kar rhe hai
        sum += candidates[index];
        makeCombination(index, sum, target, candidates, combo, result);
        combo.pop_back();           // removing the last inseting element
        sum -= candidates[index];   // removing the last inseted element from sum
        makeCombination(index + 1, sum, target, candidates, combo, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector <int> combo;

        makeCombination(0, 0, target, candidates, combo, result);

        return result;
    }
};
*/


/*
// method 2
class Solution {
public:
    void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            combination(candidates, target-candidates[i], curr, result, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        combination(candidates, target, curr, result, 0);
        return result;
    }
};
*/


// method 3
class Solution {
public:
    int Sum(vector<int>& arr) {
        int sum = 0;
        for(int i = 0; i<arr.size(); i++)
            sum += arr[i];
        return sum;
    }
    void combination(vector<int>& candidates, int target, vector<int> curr, vector<vector<int>>& result, int idx) {
        if(Sum(curr) > target || idx >= candidates.size())
            return;
        if(Sum(curr) == target) {
            result.push_back(curr);
            return;
        }
        curr.push_back(candidates[idx]);
        combination(candidates, target, curr, result, idx);
        curr.pop_back();
        combination(candidates, target, curr, result, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        combination(candidates, target, curr, result, 0);
        return result;
    }
};

