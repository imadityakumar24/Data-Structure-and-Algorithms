/*

The Celebrity Problem
Difficulty: MediumAccuracy: 38.33%Submissions: 334K+Points: 4Average Time: 30m
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0],
                  [0, 1, 0],
                  [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.
Input: mat[][] = [[1, 1], 
                  [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
Input: mat[][] = [[1]]
Output: 0
Constraints:
1 ≤ mat.size() ≤ 1000
0 ≤ mat[i][j] ≤ 1
mat[i][i] = 1

Expected Complexities
Company Tags
ZohoFlipkartAmazonMicrosoftGoogleFab.comOne97United Health Group

*/








#include <bits/stdc++.h>
using namespace std;


/* 
// Brute force solution 
// tc = O(n^2) + O(n) for find above and below
// sc = O(1)
class Solution {
private:
    bool findAbove(vector<vector<int> >& mat, int index) {
        for (int i = 0; i < index; i++) {
            if (mat[i][index] == 0) {
                return false;
            }
        }
        return true;
    }
    
    bool findBelow(vector<vector<int> >& mat, int index) {
        int n = mat.size();
        for (int i = index + 1; i < n; i++) {
            if (mat[i][index] == 0) {
                return false;
            }
        }
        return true;
    }
// private section ends here    
public:
    int celebrity(vector<vector<int> >& mat){
        int r = mat.size();
        int c = mat.size();
       // int totalCelebrity = -1;
        if (r == 1) return 0;
        
        for (int i = 0; i < r; i++) {
            bool foundCelebrity = true;
            for (int j = 0; j < r; j++) {
                if (i == j) continue;
                if (mat[i][j] == 1) {
                    foundCelebrity = false;
                    break;
                }
            }
            if (foundCelebrity == true) {
                bool aboveKnown = findAbove(mat, i);
                bool belowKnown = findBelow(mat, i);
                
                if (aboveKnown == true && belowKnown == true) {
                    //totalCelebrity++;
                    return i;
                }
            }
        }
        
        //return totalCelebrity;
        return -1;
    }
};
*/



/*
// better solution using two pointer
// tc = O(2n)
// sc = O(1)
class Solution {
private:
    // means in row ith persong don't know anybody
    bool checkRows(vector<vector<int> >& mat, int index) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            if (i == index) continue;
            if (mat[index][i] == 1) {
                return false;
            }
        }
        return true;
    }
    
    // means ith person is known by all. 
    bool checkColum(vector<vector<int> >& mat, int index) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            if (mat[i][index] == 0) {
                return false;
            }
        }
        return true;
    }
// private section ends here    
public:
    int celebrity(vector<vector<int> >& mat){
        int r = mat.size();
        int i = 0, j = r - 1;
        
        while (i != j) {
            if (mat[i][j] == 0) {
                j--;
            }
            else {
                i++;
            }
        }
        
        bool rows = checkRows(mat, i);
        bool colum = checkColum(mat, i);
        
        if (rows == true && colum == true)
            return i;
        
        return -1;
    }
};
*/



// Optimal solution using two pointer
// tc = O(n)
// sc = O(1)
class Solution {
public:
    int celebrity(vector<vector<int> >& mat){
        int r = mat.size();
        int i = 0, j = r - 1;
        
        while (i != j) {
            if (mat[i][j] == 0) {
                j--;
            }
            else {
                i++;
            }
        }
        
        int foundCelebrity = true;
        for (int k = 0; k < r; k++) {
            if (k == i) continue;
            if (mat[k][i] != 1 || mat[i][k] != 0) {
                foundCelebrity = false;
                break;
            }
        }
        
        if (foundCelebrity) return i;
        
        return -1;
    }
};



















