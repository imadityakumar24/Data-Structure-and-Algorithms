/*

79. Word Search

Solved
Medium
Topics
premium lock icon
Companies

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?

 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,300,601/5M
Acceptance Rate
46.2%
Topics
Array
String
Backtracking
Depth-First Search
Matrix

*/



#include <bits/stdc++.h>
using namespace std;

// Optimal Solution
// Time Complexity:  O(m*n*4^k), where “K” is the length of the word. And we are searching for the letter m*n times in the worst case. Here 4 in 4^k is because at each level of our decision tree we are making 4 recursive calls which equal 4^k in the worst case.
// Space Complexity: O(K), Where k is the length of the given words.

class Solution {

    bool isInBoundary(int i, int j, int m, int n) {
        if ((i >= 0 && i < m) && (j >= 0 && j < n)) 
            return true;
        return false;    
    }

    bool solve (int row, int col, int m, int n, int idx, string &word, vector<vector<char>>& board) {
        if (idx == word.size()) return true;
        if (isInBoundary(row, col , m, n) == false || word[idx] == '$') {
            return false;
        }
        if (word[idx] != board[row][col]) return false;

        char ch = board[row][col];
        board[row][col] = '$';

        bool left  = solve(row,   col-1, m, n, idx+1, word, board);     // left
        bool down  = solve(row+1, col,   m, n, idx+1, word, board);     // down
        bool right = solve(row,   col+1, m, n, idx+1, word, board);     // right
        bool up    = solve(row-1, col,   m, n, idx+1, word, board);     // up

        board[row][col] = ch;
        return down || left || right || up;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(i, j, m, n, 0, word, board)) 
                    return true;
            }
        }
    
        return false;
    }
};




/*

// first wrong aproach
class Solution {
private:

    bool isInBoundary(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }    

    bool solve(int i, int j, int idx, int m, int n, string str, string &word, vector<vector<char>>& board) {
        if (!isInBoundary(i, j, m, n) || board[i][j] == '$') {
            return false;
        }
        if (word[idx] != board[m][n]) {
            return false;
        }
        if (word == str) {
            return true;
        }

        // down
        char ch = board[i][j];
        str.push_back(ch);
        board[i][j] = '$';
        solve (i+1, 0, idx+1, m, n, str, word, board);
        str.pop_back();
        board[i][j] = ch;
        // left
        char a = board[i][j];
        str.push_back(a);
        board[i][j] = '$';
        solve (i+1, 0, idx+1, m, n, str, word, board);
        str.pop_back();
        board[i][j] = a;
         // right  
        char b = board[i][j];
        str.push_back(b);
        board[i][j] = '$';
        solve (i+1, 0, idx+1, m, n, str, word, board);
        str.pop_back();
        board[i][j] = b;
        // up
        char c = board[i][j];
        str.push_back(c);
        board[i][j] = '$';
        solve (i+1, 0, idx+1, m, n, str, word, board);
        str.pop_back();
        board[i][j] = c;

    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();       // row
        int n = board[0].size();    // colum
        string str = "";

        return solve(0, 0, 0, m, n, str, word, board);
    
    }
};
*/