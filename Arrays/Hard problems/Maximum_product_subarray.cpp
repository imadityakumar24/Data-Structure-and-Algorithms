/*

152. Maximum Product Subarray

Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,742,976/4.9M
Acceptance Rate
35.3%

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN;
        int suffix = 0, prefix = 0;

        for (int i = 0; i < n; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            maxProduct = max(maxProduct, max(prefix, suffix));
        }
        
        return maxProduct;
    }
};

/*
// better solution 
// tc = o(n)
// sc = o(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = INT_MIN, product = 1;
        if (n == 1)
            return nums[0];
        else {
            for (int i = 0; i < n; i++) {
                    product = product * nums[i];
                    maxProduct = max(maxProduct, product);
                    if (product < 0) 
                        product = 1;
            }
        }
        return maxProduct;
    }
};
*/

/*
// brute force
// tc = o(n^2)
// sc = o(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct, product = 1;
        if (n == 1)
            return nums[0];
        else {
            for (int i = 0; i < n; i++) {
                product = 1;
                for (int j = i; j < n; j++) {
                    product = product * nums[j];
                    maxProduct = max(maxProduct, product);
                }
            }
        }
        return maxProduct;
    }
};
*/