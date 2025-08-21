/*

169. Majority Element
Solved
Easy
Topics
premium lock icon
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
4,607,540/7M
Acceptance Rate
65.8%
Topics

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int votes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (votes == 0)
                candidate = nums[i];
            if (nums[i] == candidate) {
                votes++;
            } else {
                votes--;
            }
        }
        return candidate;
    }
};