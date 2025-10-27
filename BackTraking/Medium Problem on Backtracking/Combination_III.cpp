/*

216. Combination Sum III

Solved
Medium
Topics
premium lock icon
Companies

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
732,960/1M
Acceptance Rate
72.5%
Topics
Array
Backtracking


*/




#include <bits/stdc++.h>
using namespace std;


// Optimal recursive solution
// TC = o(2^n)
// SC = o(n) + o(k) for subset
class Solution {
private:
    void backtrack (int i, int size, int target, vector <int> &arr, vector <int> &combo, vector <vector<int>> &result) {
        if (combo.size() == size && target == 0) {
            result.push_back(combo);
            return;
        }
        if (i >= arr.size() || combo.size() > size || target < 0) return;

        combo.push_back(arr[i]);
        backtrack (i+1, size, target-arr[i], arr, combo, result);
        combo.pop_back();
        backtrack (i+1, size, target, arr, combo, result);
    } 
// private section ends here     
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> arr;
        for (int i = 1; i <= 9; i++) 
            arr.push_back(i);

        vector <int> combo;
        vector <vector<int>> result;
        backtrack (0, k, n, arr, combo, result);

        return result;    
    }
};