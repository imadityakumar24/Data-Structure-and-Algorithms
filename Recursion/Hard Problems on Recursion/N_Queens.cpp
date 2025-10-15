/*

51. N-Queens
Solved
Hard
Topics
premium lock icon
Companies
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,108,054/1.5M
Acceptance Rate
74.0%
Topics
Array
Backtracking

*/


#include <bits/stdc++.h>
using namespace std;

/*

Time complexity for Approach-1 : O(N!)
Unlike the brute force approach, we will only place queens on squares that aren't under attack.
For the first queen, we have N options. For the next queen, we won't attempt to place it in the
same column as the first queen, and there must be at least one square attacked diagonally by the
first queen as well. Thus, the maximum number of squares we can consider for the second queen is
(N−2). For the third queen, we won't attempt to place it in 2 columns already occupied by the first
2 queens, and there must be at least two squares attacked diagonally from the first 2 queens.
Thus, the maximum number of squares we can consider for the third queen is (N-4).
This pattern continues, resulting in an approximate time complexity of O(N!)
*/
/*
// Aproach 1
// TC : O(N!) - Read the reason above
// SC : O(N) to store the result
class Solution {
private:
    bool isValid(vector <string> &board, int row, int col) {
        // vertical check colum checking
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }
        // left diagonal check
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        // right diagonal check
        int n = board.size();
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    } 

    void nQueen(vector <string> &board, int row, vector <vector<string>> &result) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                nQueen(board, row+1, result);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector <vector<string>> result;
        vector <string> board(n, string(n, '.'));
        nQueen(board, 0, result);

        return result;
    }
};
*/






// Aproach 2
// TC : O(N!) - smae but in this issafe tc reduced to o(1) form o(n)
// SC : O(N) to store the result
class Solution {
public:

    unordered_set <int> colom;
    unordered_set <int> diagonal;
    unordered_set <int> antiDiagonal;

    void nQueen(vector <string> &board, int row, vector <vector<string>> &result) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            int diagConst     = row + col;  // right side diagnol
            int antidiagConst = row - col;  // left side diagnol

            if ( colom.find(col) != colom.end() || 
                 diagonal.find(diagConst) != diagonal.end() || 
                 antiDiagonal.find(antidiagConst) != antiDiagonal.end() ) 
            {
                continue;
            }

            // these take only o(1) tc while in previus it taking o(3n) means o(n) tc
            // for a given row col = 'Q'
            colom.insert(col);
            diagonal.insert(diagConst);
            antiDiagonal.insert(antidiagConst);
            board[row][col] = 'Q';

            nQueen(board, row+1, result);

            colom.erase(col);
            diagonal.erase(diagConst);
            antiDiagonal.erase(antidiagConst);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector <vector<string>> result;
        vector <string> board(n, string(n, '.'));
        nQueen(board, 0, result);

        return result;
    }
};