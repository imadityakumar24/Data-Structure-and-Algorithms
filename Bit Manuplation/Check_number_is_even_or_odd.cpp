/*

Odd or Even
Difficulty: BasicAccuracy: 60.6%Submissions: 158K+Points: 1Average Time: 5m
Given a positive integer n, determine whether it is odd or even. Return true if the number is even and false if the number is odd.

Examples:

Input: n = 15
Output: false
Explanation: The number is not divisible by 2, Odd number.
Input: n = 44
Output: true
Explanation: The number is divisible by 2, Even number.

*/


/*
// brute foce solution
// tc = O(1)
// sc = O(1)
class Solution {
public:
    bool isEven(int n) {
        if (n < 0) return false;
        
        if (n % 2 == 0) 
            return true;
        return false;        
    }
};
*/

// Optimal solution using bit maniplation
// tc = o(1)
// sc = 0(1)
// If n & 1 == 0 → number is even
// If n & 1 == 1 → number is odd
class Solution {
public:
    bool isEven(int n) {
        // if (n & 1 == 0)  // this give error due ot operator precidence
        // n & (1 == 0)     // which is: n & false → n & 0
        if ((n & 1) == 0)
            return true;
        return false;    
    }
};