/*

48. Rotate Image
Solved
Medium
Topics
premium lock icon
Companies
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,435,748/3.1M
Acceptance Rate
78.4%

*/



#include <bits/stdc++.h>
using namespace std;


// better apraoch
// tc = O(n) + O(n) 
// sc = O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++) {    // transpose the matrix
            for(int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {   // reveresing the row
            reverse(matrix[i].begin(), matrix[i].end());
        }
/*        
        int left = 0, right = n-1;
        while(left < right) {
            swap()
        }
*/        
    }
};

/*
// brute force aproach
// tc = O(n * m) + O(n * m)  or O(N^2) 
// because we are iterating on the each index of the martrix for first loop time complexity is 0(N)
// sc = O(n * m)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector< vector<int> > result(n, vector < int > (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                result[j][n-1-i] = matrix[i][j];
            }
        }

        for(int i = 0; i < n; i++) {  
            for(int j = 0; j < m; j++) {
                matrix[i][j] = result[i][j];
            }
        }
    }
};

*/