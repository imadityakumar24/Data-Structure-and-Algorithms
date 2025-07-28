/*

231. Power of Two
Solved
Easy
Topics
premium lock icon
Companies
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false

*/


/*
// brute force solution using for loop
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        long long int ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = ans * 2;
            if (ans == n) return true;
            if (ans > n) break;
        }

        return false;
    }
};
*/


/*
// optimal solution
// recursive code
class Solution {
private:
    bool calculatePower(int n, long long int ans) {
        if (n == ans) return true;
        if (ans > n) return false;
        ans = ans * 2;
        return calculatePower(n, ans);
    }
// private section ends here   
public:
    bool isPowerOfTwo(int n) {

        if (n < 0) return false;
        long long int ans = 1;
        bool result = calculatePower(n, ans);

        return result;
    }
};
*/


// most optimal solution using bit maniplation
// tc = O(1)
// sc = O(1)
class Solution { 
public:
    bool isPowerOfTwo(int n) {
        if (n < 0 || n == 0) return false;
        if (n == 1) return true;    // mean 2 power 0 is equal to 1
        
        int result = (n & n-1);
        if (result == 0) 
            return true;
        return false;    
    }
};