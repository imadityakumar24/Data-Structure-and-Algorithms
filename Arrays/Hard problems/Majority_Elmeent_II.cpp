/*

229. Majority Element II
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,059,177/1.9M
Acceptance Rate
54.9%


*/



#include <bits/stdc++.h>
using namespace std;


// tc = O(N ^ 2)
// sc = O(1) because we are only string 2 elemet whichis very small size so we can neglect this
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> list;

        for(int i = 0; i < n; i++) {
            if(list.size() == 0 || list[0] != nums[i]) {
                int count = 0;
                for(int j = 0; j < n; j++) {
                    if(nums[j] == nums[i]) 
                        count++;
                }
                if(count > (n/3)) {
                    list.push_back(nums[i]);
                }
            }
            if(list.size() == 2) 
                break;
        }

        return list;
    }
};


/*
// tc = 
// sc = 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> result;
        unordered_map<int, int> countMap;  // O(1)

        // Count occurrences of each element
        for(int num : nums) {
            countMap[num]++;
        }

        // Threshold for being a majority element
        int threshold = n / 3;

        // Find elements that appear more than threshold times
        for(auto &entry : countMap) {
            if(entry.second > threshold) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};
*/


/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> result;
        unordered_map<int, int> countMap;  // O(1)

        // Count occurrences of each element
        for(int num : nums) {
            countMap[num]++;
        }

        // Threshold for being a majority element
        int threshold = n / 3;

        // Find elements that appear more than threshold times
        for(auto &entry : countMap) {
            if(entry.second > threshold) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};
*/

/*
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector <int> result;
        unordered_map<int, int> countMap;  // O(1)

        // Count occurrences of each element
        for(int num : nums) {
            countMap[num]++;
        }

        // Threshold for being a majority element
        int threshold = n / 3;

        // Find elements that appear more than threshold times
        for(auto &entry : countMap) {
            if(entry.second > threshold) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};
*/