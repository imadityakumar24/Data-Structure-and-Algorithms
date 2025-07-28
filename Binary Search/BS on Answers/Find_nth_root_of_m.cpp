/*

Find nth root of m
Difficulty: EasyAccuracy: 25.06%Submissions: 215K+Points: 2Average Time: 15m
You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

Examples :

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 1, m = 14
Output: 14
Constraints:
1 <= n <= 30
1 <= m <= 109

Expected Complexities
Company Tags
DirectiAccenture

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int nthRoot(int n, int m) {
        
        for (int i = 1; i <= m; i++) {
            int j = 1, sr = 1;
            while (j <= n) {
                sr = sr * i;
                j++;
            }
            if (sr == m) return i;
            if (sr > m) break;
        }
    
        return -1;
    }
};