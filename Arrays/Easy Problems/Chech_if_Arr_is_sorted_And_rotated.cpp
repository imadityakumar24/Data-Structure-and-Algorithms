/*


1752. Check if Array Is Sorted and Rotated
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 


*/





#include <bits/stdc++.h>
using namespace std;


/*
// brute force giving tle 
class Solution {
private:
    bool checkSorted(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
public:
    bool check(vector<int>& nums) {
        if (checkSorted(nums)) return true;
        int n = nums.size();
        int count = 0;

        while (count <= n) {
            int temp = nums[0];
            vector <int> copy = nums;
            // for (int i = 1; i < n; i++) {
            //     nums[i-1] = nums[i];
            // }
            copy[n-1] = temp;
            bool result = checkSorted(copy);
            if (result == true) 
                return true;
        }  

        return false;  
    }
};
*/

/*
// little imroved code but it also giving the tle 
class Solution {
private:
    bool checkSorted(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
public:
    bool check(vector<int>& nums) {
        if (checkSorted(nums)) return true;
        int n = nums.size();
        int i = 0; long long int count = 0;
        while (i < n-1) {
            if (nums[i] > nums[i+1]) {
                break;
            }
            count++;
        } 
        vector <int> temp;
        for (int i = count; i < n; i++) {
            temp.push_back(nums[i]);
        }
        for (int i = 0; i <= count; i++) {
            temp.push_back(nums[i]);
        }

        if (checkSorted(temp))
            return true;

        return false;  
    }
};
*/

// optimal solution 
// tc = o(n)
// sc = o(1)
class Solution {
private:
    bool checkSorted(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
private:
    bool checkRestArr(vector<int>& nums, int startIndex) {
        int n = nums.size();
        for (int i = startIndex; i < n-1; i++) {
            if (i+1 < n && nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
    }     
public:
    bool check(vector<int>& nums) {
        if (checkSorted(nums)) return true;
        int n = nums.size();
        int count = 1, i = 0;
        while (i < n) {
            if ( i+1 < n && nums[i] <= nums[i+1]) {
                count++;
            }
            else {
                break;
            }
            i++;
        }

        bool result = checkRestArr(nums, count);
        if (result == true && nums[0] >= nums[n-1]) {
            return true;
        }
        
        return false;
    }
};