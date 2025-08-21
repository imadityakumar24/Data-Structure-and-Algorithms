/*

Largest subarray with 0 sum
Difficulty: MediumAccuracy: 41.84%Submissions: 429K+Points: 4Average Time: 20m
Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]
Constraints:
1 ≤ arr.size() ≤ 106
−103 ≤ arr[i] ≤ 103

Expected Complexities
Company Tags
AmazonMicrosoftMakeMyTrip
Topic Tags

*/



#include <bits/stdc++.h>
using namespace std;


/*You are required to complete this function*/
// tc = O(N)
// SC = O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int lenth = 0, maxLenth = 0;
        int i = 0, j = i;
        long long sum = 0;
        int count = 0;
        
        while (i < n && j < n) {
            sum = sum + arr[j];
            count++;
            if(sum == 0) {
                lenth = count;
            }
            maxLenth = max(maxLenth, lenth);
            j++;
            if(j == n) {
                i++;
                j = i;
                sum = count = 0;
            }
        }
        
        return maxLenth;
    }
};
/*
// tc = O(N ^ 2)
// SC = O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int lenth = 0, maxLenth = 0;
        
        for (int i = 0; i < n; i++) {
            long long int sum = 0;
            int count = 0;
            for (int j = i; j < n; j++) {
                sum = sum + arr[j];
                count++;
                if (sum == 0) {
                    lenth = count;
                }
                maxLenth = max(maxLenth, lenth);
            }
        }
        
        return maxLenth;
    }
};

*/
