/*

Swap two numbers
Difficulty: BasicAccuracy: 70.02%Submissions: 97K+Points: 1
You are given two numbers a and b. Your task is to swap the given two numbers.

Note: Try to do it without a temporary variable.

Examples:

Input: a = 13, b = 9
Output: 9 13
Explanation: After swapping it becomes 9 and 13.
Input: a = 15, b = 8
Output: 8 15
Explanation: after swapping it becomes 8 and 15.

*/


#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
/*
// brute solution
// using temp varible
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        int temp = a;
        a = b;
        b = temp;
        return {a, b};
    }
};
*/

/*
// brute solution
// using  stl
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        swap(a, b);
        return {a, b};
    }
};
*/




// optimal solution
// using  bit wise xor operator
class Solution {
  public:
    pair<int, int> get(int a, int b) {
        
       a = a ^ b;
       b = a ^ b;   // (a ^ b) ^ b
       a = a ^ b;   // (a ^ b) ^ b
       
       return {a, b};
    }
};