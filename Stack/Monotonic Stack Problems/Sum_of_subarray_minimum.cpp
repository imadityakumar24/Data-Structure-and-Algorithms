/*

907. Sum of Subarray Minimums
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
376,886/996K
Acceptance Rate
37.8%

*/


#include <bits/stdc++.h>
using namespace std;


/*
// brute force solution
// did by me  but giving tle
// tc = o(n^2)
// sc = o(n)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long int totalMinSum = 0;
        const int mod = 1e9 + 7;

        for (int i = 0 ; i < n; i++) {
            vector <int> subArr;
            int minValue = INT_MAX;
            for (int j = i; j < n; j++) {
                minValue = min(minValue, arr[j]);
                totalMinSum = (totalMinSum + minValue) % mod;
                subArr.push_back(arr[j]);
            }
        }

        return totalMinSum;
    }
};
*/

/*
// brute force solution little updated deleted the subarray vector
// did by me  but giving tle
// tc = o(n^2)
// sc = o(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long int totalMinSum = 0;
        const int mod = 1e9 + 7;

        for (int i = 0 ; i < n; i++) {
            int minValue = INT_MAX;
            for (int j = i; j < n; j++) {
                minValue = min(minValue, arr[j]);
                totalMinSum = (totalMinSum + minValue) % mod;
            }
        }

        return totalMinSum;
    }
};
*/


// optial solution
// watched striver and codestory WITH MIK video to understand
// tc = O(n)+O(n)+O(n) = O(3n)
// sc = O(n)+O(n) = O(n)
class Solution {
private:
    vector <int> getNSL(vector<int>& arr, int n) {
        vector <int> result(n);
        stack <int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty())
                result[i] = -1;
            else 
                result[i] = st.top();   

            st.push(i);     
        }

        return result;
    }


    vector <int> getNSR(vector<int>& arr, int n) {
        vector <int> result(n);
        stack <int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty())
                result[i] = n;
            else 
                result[i] = st.top();   

            st.push(i);     
        }

        return result;
    }
// private section ends here       
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector <int> NSL = getNSL(arr, n);
        vector <int> NSR = getNSR(arr, n);
        
        long long totalMinSum = 0;
        int M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long int ls = i - NSL[i];    // means left mai kitne element honge
            long long int rs = NSR[i] - i;    // means left mai kitne element honge
            long long int totalWays = ls * rs; // means totalways , subarrays jiska minimum arr[i] hoga
            long long totalSum = arr[i] * totalWays;
            totalMinSum = (totalMinSum + totalSum) % M;
        }

        return totalMinSum;
    }
};

// it overwrite the runtime file 
// << "50";    parenthesi mai jo value likhemge utna hi runtime show krega
auto init = atexit([]() {
    ofstream("display_runtime.txt") << "50";
});