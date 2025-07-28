/*

Two numbers with odd occurrences
Difficulty: MediumAccuracy: 49.49%Submissions: 78K+Points: 4
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:

Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explanation: 5 and 1 have odd occurrences.

Example 2:

Input:
N = 8
Arr = {1 7 5 7 5 4 7 4}
Output: {7, 1}
Explanation: 7 and 1 have odd occurrences.

Your Task:
You don't need to read input or print anything. Your task is to complete the function twoOddNum() which takes the array Arr[] and its size N as input parameters and returns the two numbers in decreasing order which have odd occurrences.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/


#include <bits/stdc++.h>
using namespace std;


/*
// Brute force solution using map 
// tc = o(2n)
// sc = O(n)    // for hasing 
class Solution {
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        
        // int size = sizeof(Arr) / sizeof(Arr[0]); // this is not safe when array is passed a a funciton
        map <int, int> mp;
        for (int i = 0; i < N; i++) {
            mp[Arr[i]]++;
        }
        
        vector <long long int> ans;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            // if ( ((*it).second) % 2 == 1  || ((*it).second) % 2  != 0 ) {
            //     ans.push_back((*it).second);
            // }
            int count = it->second;
            if (count % 2 != 0) {
                ans.push_back(it->first);
            }
        }
        
        if (ans[1] > ans[0]) {
            int temp = ans[0];
            ans[0]= ans[1];
            ans[1] = temp;
        } 
        
        return ans;
    }
};
*/


// Optimal solution using bit manipulation
// tc = o(2n)
// sc = o(1)
class Solution {
  public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        int xorr = 0;
        for (int i = 0; i < N; i++) {
            xorr = xorr ^ Arr[i];
        }
        
        long int rightMost = (xorr & xorr-1) ^ xorr;    // use long bcs if xor is 10^-31  and xor & xor-1 is execeding the int lenth 1-^-31 - 1 so use long 
        int bucket1 = 0, bucket2 = 0;
        
        for (int i = 0; i < N; i++) {
            if (Arr[i] & rightMost)     // if right most bit is set  
                bucket1 = bucket1 ^ Arr[i];
            else 
                bucket2 = bucket2 ^ Arr[i];
        }
        
        vector <long long int> ans;
        ans.push_back(bucket1);
        ans.push_back(bucket2);
        if (ans[1] > ans[0]) 
            swap(ans[0], ans[1]);
            
        return ans;
    }
};