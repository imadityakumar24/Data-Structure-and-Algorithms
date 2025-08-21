/*

73. Set Matrix Zeroes
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,217,670/3.6M
Acceptance Rate
61.3%

*/


#include <bits/stdc++.h>
using namespace std;

// better aproach and it is  working for negative elements also
// tc = O(n * m) + (n * m) 
// sc = O(n + m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector <int> row(m, 0);
        vector <int> colum(n, 0);

        for(int i = 0; i < m; i++) {        // marking the row and colum to one so further we convert intier row and colum to 0
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    colum[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {        // converting the row and colum to zer0
            for(int j = 0; j < n; j++) {
                if(row[i] == 1 || colum[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



// better aproach and it is  working for negative elements also
// tc = O(n * m) + (n * m) 
// sc = O(n + m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector <int> row(m, 0);
        vector <int> colum(n, 0);

        for(int i = 0; i < m; i++) {        // marking the row and colum to one so further we convert intier row and colum to 0
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    colum[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {        // converting the row and colum to zer0
            for(int j = 0; j < n; j++) {
                if(row[i] == 1 || colum[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

/*
// brute force aproach and it is not working for negative elements
// tc = O(n * m) * (n + m) + O(n)
// sc = O(1)
class Solution {
private:  
    void markRow(int i, int size, vector<vector<int>>& matrix) {
        for(int j = 0; j < size; j++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }
private:  
    void markColum(int j, int size, vector<vector<int>>& matrix) {
        for(int i = 0; i < size; i++) {
            if(matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m, n;
        m = matrix.size();
        n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n ; j++) {
                if(matrix[i][j] == 0) {
                    markRow(i, n, matrix);
                    markColum(j, m, matrix);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n ; j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

*/