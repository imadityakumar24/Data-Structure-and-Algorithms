/*

136. Single Number
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,930,252/5.1M
Acceptance Rate
76.4%

*/




#include <bits/stdc++.h>
using namespace std;

// optimal  solution using bit manuplation
// tc = o(n)
// sc = o(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
}; 
/*
// brute force solution
// tc = o(n)
// sc = o(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int apearence = 0; int result = 0;
         for(int i = 0; i < nums.size(); i++) {
            apearence = count(nums.begin(), nums.end(), nums[i]);
            if(apearence == 1) {
                result = nums[i];
                break;
            }
        }
        return result;
    }
}; 
*/