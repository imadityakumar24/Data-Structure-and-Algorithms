/*

493. Reverse Pairs
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
294,618/902.2K
Acceptance Rate
32.7%

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
private:
    void mergeArray(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        // if elements are still present in left half
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        // if elements are still present in righ half
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

    } // function ends here
    
private:
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > (long long)arr[right] * 2) 
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

private:
    int mergeSort(vector<int>& arr, int l, int r) {
        int count = 0;
        int low = l;
        int high = r;
        if (low >= high)
            return count;
        int mid = low + (high - low) / 2;
        count += mergeSort(arr, low, mid);        // left half
        count += mergeSort(arr, mid + 1, high);   // right half
        count += countPairs(arr, low, mid, high); // Modification
        mergeArray(arr, low, mid, high);
        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};