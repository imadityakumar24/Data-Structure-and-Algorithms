/*

Generate all binary strings

Difficulty: MediumAccuracy: 63.9%Submissions: 43K+Points: 4Average Time: 20m
Given an integer n. You need to generate all the binary strings of n characters representing bits.

Note: Return the strings in  ascending order.

Examples:

Input: n = 2
Output: [00, 01, 10, 11]
Explanation: As each position can be either 0 or 1, the total possible combinations are 4.
Input: n = 3
Output: [000, 001, 010, 011, 100, 101, 110, 111]
Explanation: As each position can be either 0 or 1, the total possible combinations are 8.
Constraints:
1 ≤ n ≤ 20

Expected Complexities
Time Complexity: O(n * 2^n)
Auxiliary Space: O(n)
Topic Tags
Bit Magic Backtracking Recursion

*/




#include <bits/stdc++.h>
using namespace std;

// Recursivoe solution
// TC = o(n * 2 ^ n)
// SC = O(n^2) for result


class Solution {
    
// here i am passing temp as reference so i need to pop the last character manually 
// here i am popoing 2 times
/*
private:
    void solve(int n, string &temp, vector<string> &result) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }    
        temp.push_back('0');
        solve(n, temp, result);
        temp.pop_back();
        temp.push_back('1');
        solve(n, temp, result);
        temp.pop_back();
    }
*/ 

// here i am passing temp as copy so not need to pop the last character manually 
// here i am popoing 1 times
private:
    void solve(int n, string temp, vector<string> &result) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }    
        temp.push_back('0');
        solve(n, temp, result);
        temp.pop_back();
        temp.push_back('1');
        solve(n, temp, result);
    }    
    
public:
    vector<string> binstr(int n) {
        vector <string> result;
        if (n == 0) return result;
        
        string temp;
        solve(n, temp, result);
        
        return result;
    }
};