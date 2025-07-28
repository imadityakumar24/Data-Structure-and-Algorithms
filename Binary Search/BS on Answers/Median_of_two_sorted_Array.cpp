/*

4. Median of Two Sorted Arrays
Solved
Hard
Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/


/*
// working code
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        double ans = 0;

        vector<int> VS;
        for (auto& val : nums1) {
            VS.push_back(val);
        }
        for (auto& val : nums2) {
            VS.push_back(val);
        }
        sort(VS.begin(), VS.end());

        int n = VS.size() - 1;
        double i = 0;
        i = n / 2;
        if (n % 2 == 0) {

            ans = VS[i];
            return ans;
        }
        return ((double)((VS[i] + VS[i + 1])) / 2.0);
    }
};
*/





#include <bits/stdc++.h>
using namespace std;


// not working
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        double ans = 0;
        set<int> s;

        for (auto& val : nums1) {
            s.insert(val);
        }
        for (auto& val : nums2) {
            s.insert(val);
        }

        vector<int> VS;
        for (auto data : s) {
            VS.push_back(data);
        }

        int n = VS.size() - 1;
        double i = 0;
        i = n / 2;
        if (n % 2 == 0) {

            ans = VS[i];
            return ans;
        }
        return ((double)((VS[i] + VS[i + 1]))/2.0);
    }
};




/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        stack <int> value;
        vector <int> newArr;
        for (auto i : nums1) value.push(i);
        for (auto i : nums2) value.push(i);
        
        // Extract all elements from stack into vector
    while (!value.empty()) {
        newArr.push_back(value.top());
        value.pop();
    }

        sort(newArr.begin(), newArr.end());
        int n = newArr.size();

        if (n % 2 == 0) {   // even sized arr
            double ans =( newArr[n/2] + newArr[n/2 - 1] ) / 2;
        }
        
        double ans = (newArr[n/2]) / 2;

        return ans;
    }
};
*/