
/*

40. Combination Sum II
Solved
Medium
Topics
premium lock icon
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,534,133/2.6M
Acceptance Rate
58.4%
Topics
Array
Backtracking

*/




#include <bits/stdc++.h>
using namespace std;

// Recursive solution Aproach 1 
// method every time i am subtract arra value from target when target is 0 means we have valid combination
//T.C : O(2^n)
//S.C : O(n)
class Solution {
private:
    void findCombinations(int idx, int target, vector<int>& arr, vector <int> &combo, vector<vector<int>> &result) {
        if (target < 0) return;
        if (target == 0) {
            result.push_back(combo);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i-1]) 
                continue;

            combo.push_back(arr[i]);
            findCombinations(i+1, target-arr[i], arr, combo, result); 
            combo.pop_back();   
        }
    }   

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;

        vector <int> combo;
        sort(candidates.begin(), candidates.end());

        findCombinations(0, target, candidates, combo, result);

        return result;
    }
};



/*
class Solution {
private:
    void makeCombination(int index, int sum, int target, vector<int>& candidates, vector<int>& combo, vector<vector<int>>& result) {
        if (sum == target) {
            result.push_back(combo);
            return;
        }

        if (index >= candidates.size() || sum > target) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) 
                continue;

            combo.push_back(candidates[i]);      // Choose element
            makeCombination(i + 1, sum + candidates[i], target, candidates, combo, result); 
            combo.pop_back();                   // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combo;

        sort(candidates.begin(), candidates.end()); // Important to detect duplicates

        makeCombination(0, 0, target, candidates, combo, result);
        return result;
    }
};
*/



