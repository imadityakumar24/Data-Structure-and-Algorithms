/*

283. Move Zeroes
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
4,323,114/6.9M
Acceptance Rate
63.0%

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int left = 0;
       for(int right = 0; right < nums.size(); right++) {
           if(nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
           }
       }
    }
};