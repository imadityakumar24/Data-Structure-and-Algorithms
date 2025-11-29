/*

37. Sudoku Solver
Solved
Hard
Topics
premium lock icon
Companies
Hint
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
949,160/1.5M
Acceptance Rate
65.3%
Topics
Array
Hash Table
Backtracking
Matrix

*/


#include <bits/stdc++.h>
using namespace std;


/*
class Solution {
private:

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        // for row 
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;
        }
        // for colom
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
        }

        // checking in the grid of 9
        // it find the grid cordinate means finding first element of 3 by 3 grid
        int start_i = (row / 3) * 3;
        int start_j = (col / 3) * 3;

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[start_i + k][start_j + l] == ch) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve (vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board) == true)
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve (board);
    }
};
*/


// more cleaner code
// TC = O(9^(M)) Where M Is The Number Of Empty Cells
// TC = O(9^(81)) 
// SC = O(1)
class Solution {
private:

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        // for row and col
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
        }

        // checking in the grid of 9
        // it find the grid cordinate means finding first element of 3 by 3 grid
        int start_i = (row / 3) * 3;
        int start_j = (col / 3) * 3;

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[start_i + k][start_j + l] == ch) 
                    return false;
            }
        }

        return true;
    }

    bool solve (vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board) == true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve (board);
    }
};