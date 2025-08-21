/*

75. Sort Colors
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,159,652/4.6M
Acceptance Rate
68.1%

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int low = 0, mid = 0, high = size-1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } 
            else if(nums[mid] == 1) {
                mid++;
            } 
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};