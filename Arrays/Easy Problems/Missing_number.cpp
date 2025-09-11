/*

268. Missing Number
Solved
Easy
Topics
premium lock icon
Companies
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8

Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

 
 

 

 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,292,707/4.7M
Acceptance Rate
70.6%
Topics

*/


#include <bits/stdc++.h>
using namespace std;



// recursive solution
class Solution {
private:
    int totalSum(int n) {
        if (n == 0) return 0;
        int partialAns = totalSum(n - 1);
        return n + partialAns;
    }
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        int n = nums.size();
        int total = totalSum(n);
        return total - sum;
    }
};