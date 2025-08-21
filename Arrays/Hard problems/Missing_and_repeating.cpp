/*

Missing And Repeating
Difficulty: EasyAccuracy: 24.83%Submissions: 629K+Points: 2Average Time: 30m
Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and the missing number is 2.
Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.
Constraints:
2 ≤ n ≤ 106
1 ≤ arr[i] ≤ n



*/




#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n = arr.size();
       int max = *max_element(arr.begin(), arr.end());
       
       vector <int> hash(n+1, 0);
       for (int i = 0; i < n; i++) {
           hash[arr[i]]++;
       }
       
       int repeating = -1, missing = -1;
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) repeating = i;
            else if (hash[i] == 0) missing = i;

            if (repeating != -1 && missing != -1)
                break;
        }
        
       return {repeating, missing};
    }
};


/*

// giving tle

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
       
        int missing = -1, repeating = -1;
        int num = 1;
        for (int i = 1; i <= n; i++) {
            int count = 0;
            int find = false;
            for (int j = 0; j < n; j++) {
                if (arr[j] == i) count++;
                if (arr[j] == i) find = true;
            }
            if (count >= 2) repeating = i;
            if (find == false) missing = i;
        }
        
        vector<int> ans = {repeating, missing};
        return ans;
    }
};

*/