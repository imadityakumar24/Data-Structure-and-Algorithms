/*

1248. Count Number of Nice Subarrays

Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
400,067/540.9K
Acceptance Rate
74.0%

*/









#include <bits/stdc++.h>
using namespace std;

/*
// brute force solution giving TLE
// tc = o(n^2)
// sc = o(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int odd = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 != 0) {
                    odd++;
                }
                if(odd == k) {
                    count++;
                    //break;
                }
            }
        }

        return count;
    }
};
*/


/*
// Better solution
// tc = O(3n)
// sc = O(n) temp vector and o(logn) for map
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int subArrayCount = 0;
        vector <int> temp(n,0);

        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1) == 0) 
                temp[i] = 0;
            else {
                temp[i] = 1;
            }    
        }

        vector <int> prefixSum(n, 0);
        prefixSum[0] = temp[0];

        for (int i = 1; i < temp.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + temp[i];
        }
        
        unordered_map <int, int> mp;
        int sum = 0;
        
        for (int i = 0; i < temp.size(); i++) {
            if (prefixSum[i] == k) {
                subArrayCount++;
            }
            int remainingValue = prefixSum[i] - k;

            if (mp.find(remainingValue) != mp.end()) {
                subArrayCount += mp[remainingValue];
            }
            // if (mp.find(remainingValue) == mp.end()) {  // unordered_map always initializes missing keys with 0 
            //     mp[prefixSum[i]] = 0;
            // }

            mp[prefixSum[i]]++;
        }

        return subArrayCount;
    }
};
*/


/*
// Little Better solution
// tc = O(2n)
// sc = O(n) temp vector and o(logn) for map
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int subArrayCount = 0;
        vector <int> temp(n,0);

        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1) == 0) 
                temp[i] = 0;
            else {
                temp[i] = 1;
            }    
        }

        int sum = 0;
        unordered_map <int, int> mp;
        
        for (int i = 0; i < temp.size(); i++) {
            sum += temp[i];
            if (sum == k) {
                subArrayCount++;
            }
            int remainingValue = sum - k;

            if (mp.find(remainingValue) != mp.end()) {
                subArrayCount += mp[remainingValue];
            }

            mp[sum]++;
        }

        return subArrayCount;
    }
};
*/


// ⚡ Approach (Sliding Window Counting)
// Use two pointers: left and right.
// Expand right pointer:
//   - If nums[right] is odd → increase oddCount.
//   - Reset prefixCount (because new odd resets valid window starts).
// When oddCount == k:
//   - Move left forward until oddCount < k.
//   - Count how many times we could move left. This count (prefixCount) is the number of valid starting positions.
// Add prefixCount to result for every right.
// Continue until end of array.
//
// Time Complexity: O(n)   (each element processed at most twice)

// Space Complexity: O(1)
// Optimal solution
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount = 0;      // number of odd elements in current window
        int prefixCount = 0;   // number of valid starting points for current window
        int result = 0;        // final answer
        int left = 0;          // left pointer

        for (int right = 0; right < n; right++) {
            // If nums[right] is odd, increase odd count and reset prefixCount
            if (nums[right] % 2 == 1) {
                oddCount++;
                prefixCount = 0;
            }

            // When window has exactly k odds
            while (oddCount == k) {
                if (nums[left] % 2 == 1) {
                    oddCount--;
                }
                left++;
                prefixCount++;
            }

            // Add all valid subarrays ending at 'right'
            result += prefixCount;
        }

        return result;
    }
};
