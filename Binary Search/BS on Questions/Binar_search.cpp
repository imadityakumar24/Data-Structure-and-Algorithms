/*

704. Binary Search
Solved
Easy
Topics
premium lock icon
Companies
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,248,266/5.4M
Acceptance Rate
59.7%

*/

#include <bits/stdc++.h>
using namespace std;


/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1, middle = 0;
        
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) 
                return middle;
            else if (nums[middle] < target) 
                left = middle + 1;
            else 
                right = middle - 1;        
        }

        return -1;        
    }
};
*/

// tc = o(n/2)
// sc = o(1)
class Solution {
private:
    int binarySearch(vector<int>& arr, int key, int left, int right) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;

        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] < key) {
            left = mid + 1;
            return binarySearch(arr,key, left, right);  
        } 
        else {
            right = mid - 1;
            return binarySearch(arr,key, left, right);
        }  
    }  
public:
    int search(vector<int>& nums, int target) {
       return binarySearch(nums, target,  0, nums.size()-1);  
    }
};