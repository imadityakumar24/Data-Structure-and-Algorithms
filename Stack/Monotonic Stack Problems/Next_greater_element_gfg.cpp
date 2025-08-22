/*

Next Greater Element
 
Difficulty: MediumAccuracy: 32.95%Submissions: 475K+Points: 4Average Time: 20m
Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Examples

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
Input: arr[] = [10, 20, 30, 50]
Output: [20, 30, 50, -1]
Explanation: For a sorted array, the next element is next greater element also except for the last element.
Input: arr[] = [50, 40, 30, 10]
Output: [-1, -1, -1, -1]
Explanation: There is no greater element for any of the elements in the array, so all are -1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 109

*/


#include <bits/stdc++.h>
using namespace std;


/*
// brute force giving tle
// tc = o(n^2)
// sc = o(n)
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        vector <int> ans;
        
        for (int i = 0; i < arr.size(); i++) {
            bool found = false;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] > arr[i]) {
                    ans.push_back(arr[j]);
                    found = true;
                    break;
                }
            }
            if (!found)
                ans.push_back(-1);
        }

        return ans;
    }
};
*/



// brute force giving tle
// tc = o(n)
// sc = o(n)
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1); // initialize all values as -1
        stack<int> st; // stack to store indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};