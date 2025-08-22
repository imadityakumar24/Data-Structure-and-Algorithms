/*

503. Next Greater Element II


Solved
Medium
Topics
premium lock icon
Companies
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
640,668/957K
Acceptance Rate
66.9%

*/




#include <bits/stdc++.h>
using namespace std;

/*
// brute force solution
// tc = o(N^2) + o(n)
// sc = o(n)
class Solution {
private:
    int findMax(vector<int>& nums, int target, int lastIndex) {
        for (int i = 0; i < lastIndex; i++) {
            if (nums[i] > target) 
                return nums[i];
        }
        return -1;
    }    
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> nge(n, 0);
    
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = i+1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    found = true;
                    nge[i] = nums[j];
                    break;
                }
            } 
            if (found == false) {
                nge[i] = findMax(nums, nums[i], i);
            }  
        }
    
        return nge;
    }
};
*/


/*
// better solution using concept of curcular array
// tc = o(N^2)
// sc = o(n)
class Solution {   
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> nge(n, -1);
        // hypotheticly increasing the size of arrays

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < i + n; j++) {
                int index = j % n;
                if (nums[index] > nums[i]) {
                    nge[i] = nums[index];
                    break;
                }
            } 
        }
    
        return nge;
    }
};
*/


// optimal solution using monotonic stack
// tc = o(4n)
// sc = o(2n) for stack  o(n) for returning ans
class Solution {   
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> nge(n, 0);
        stack <int> st;

        for (int i = 2*n-1; i >= 0; i--) {   // 2n
            int index = i % n;

            while (!st.empty() && st.top() <= nums[index] ) {    // 2n
                st.pop();
            }
            if (i < n) {
                // if (st.empty()) 
                //     nge[index] = -1;
                // else 
                //     nge[index] = st.top();
                nge[index] = st.empty() ? -1 : st.top();
            }

            st.push(nums[index]);    
        }
    
        return nge;
    }
};