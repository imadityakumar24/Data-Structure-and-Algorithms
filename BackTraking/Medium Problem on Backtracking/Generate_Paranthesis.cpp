/*

22. Generate Parentheses

Solved
Medium
Topics
premium lock icon
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,587,457/3.3M
Acceptance Rate
77.8%
Topics
String
Dynamic Programming
Backtracking

*/







#include <bits/stdc++.h>
using namespace std;


/*
// Problem with your current approach

// For n = 3, total length = 6
// You generate 2⁶ = 64 possible strings
// But only 5 are valid:
// ((())), (()()), (())(), ()(()), ()()()

So most recursive calls are wasted checking invalid strings.
// brute force solution using recursion
// Number of leaf nodes = total strings of length 2n = 2^(2n)
// Step 3: Total Time Complexity

//  Each recursive branch creates 2^(2n) calls.
//  Each leaf node does an O(2n) validity check.
// Number of recursive calls = 2^(2n)
// tc = O(2^(2n) × 2n) = O(n × 4ⁿ)
// sc = O(2n)

class Solution {
private:
    bool isValid(string &temp) {
        int sum = 0;
        for (char ch : temp) {
            if (ch == '(') sum += 1;
            else sum -= 1;
            if (sum < 0) 
                return false;
        }
        
        return sum == 0;
    }

    void solve(int size, string &temp, vector <string> &result) {
        if (temp.size() == size) {
            if (isValid(temp))  
                result.push_back(temp);
            return;    
        }

        temp.push_back('(');
        solve(size, temp, result);
        

        temp.push_back(')');
        solve(size, temp, result);
        temp.pop_back();
    }
// private section ends here    
public:
    vector<string> generateParenthesis(int n) {
        vector <string> result;
        int size = n * 2;
        string temp;
        solve(size, temp, result);
        return result;
    }
};
*/


class Solution {
public:
    bool isValid(string str) {
        int sum = 0;
        for(char ch:str) {
            if(ch == '(')
                sum++;
            else
                sum--;
            if(sum < 0)
                return false;
        }
        return sum==0;
    }

    void generate(string curr, int n, int length, vector<string>& result) {
        if(length == 2*n) {
            if(isValid(curr))
                result.push_back(curr);
            return;
        }
        
        curr.push_back('(');
        generate(curr, n, length+1, result);
        curr.pop_back();
        curr.push_back(')');
        generate(curr, n, length+1, result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        generate("", n, 0, result);
        return result;
    }
};