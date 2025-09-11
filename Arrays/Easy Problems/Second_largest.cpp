/*

Second Largest
Difficulty: EasyAccuracy: 26.72%Submissions: 1.3MPoints: 2Average Time: 15m
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

Expected Complexities
Company Tags
SAP LabsRockstand

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
       if (arr.empty() || arr.size() == 1) return -1;
       sort(arr.begin(), arr.end());
       int largest = arr[arr.size()-1];
       bool found = false;
       for (int i = arr.size()-2; i >= 0; i--) {
           if (arr[i] < largest) {
               found = true;
               largest = arr[i];
               break;
            //   return arr[i];
           }
       }
       if (found == true) {
            return largest;
       }
       return -1;
    }
};