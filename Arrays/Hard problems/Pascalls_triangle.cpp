/*

118. Pascal's Triangle
Solved
Easy
Topics
premium lock icon
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,363,215/3M
Acceptance Rate
78.0%

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    
    int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++) {
            vector <int> temp;
            for(int j = 0; j <= i; j++) {
                temp.push_back( nCr(i, j) );
            }
            ans.push_back(temp);
        }

        return ans;
    }
};