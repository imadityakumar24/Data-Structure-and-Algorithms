/*

54. Spiral Matrix
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,046,985/3.7M
Acceptance Rate
54.6%


*/




#include <bits/stdc++.h>
using namespace std;

// tc = O(N * M)
// sc = O(N * M)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> result;
        int n = matrix.size();  // row number
        int m = matrix[0].size();   // colum number
        int top = 0, left = 0, right = m -1, bottom = n - 1;

        while(top <= bottom && left <= right) {   
            for(int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }    
        }
        return result;
    }
};