/*

Smallest window containing 0, 1 and 2

Difficulty: EasyAccuracy: 49.73%Submissions: 59K+Points: 2
Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. If no such substring exists, then return -1.

Example 1:

Input:
S = 10212
Output:
3
Explanation:
The substring 102 is the smallest substring
that contains the characters 0, 1 and 2.
Example 2:

Input: 
S = 12121
Output:
-1
Explanation: 
As the character 0 is not present in the
string S, therefor no substring containing
all the three characters 0, 1 and 2
exists. Hence, the answer is -1 in this case.
Your Task:
Complete the function smallestSubstring() which takes the string S as input, and returns the length of the smallest substring of string S that contains all the three characters 0, 1 and 2.

Expected Time Complexity: O( length( S ) )
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length( S ) ≤ 105
All the characters of String S lies in the set {'0', '1', '2'}

*/


#include <bits/stdc++.h>
using namespace std;



/*
// Brute force
// tc = o(n)
// sc = o(1)
class Solution {
  public:
    int smallestSubstring(string S) {
        int n = S.size();
        int zero, one, two;
        int ans = INT_MAX;
        zero = one = two = -1;
         
        for (int i = 0; i < n; i++) {
            char ch = S[i];
            if (ch == '0') zero = i;
            else if (ch == '1') one = i;
            else if (ch == '2')  two = i;
            
            if (zero != -1 && one != -1 && two != -1) {
                int mini = min(zero, min(one, two));
                int maxi = max(zero, max(one, two));
                ans = min(ans, (maxi - mini + 1));
            }
            
        }
        
        if (ans != INT_MAX)
            return ans;
            
        return -1;    
    }
};
*/


// Sliding Window Approach
// TC = O(n)
// SC = O(1)
class Solution {
  public:
    int smallestSubstring(string S) {
        int n = S.size();
        int l = 0;
        int minLen = INT_MAX;
        vector<int> freq(3, 0);  // to count '0', '1', '2'

        for (int r = 0; r < n; r++) {
            char ch = S[r];
            if (ch >= '0' && ch <= '2') {
                freq[ch - '0']++;
            }

            // shrink window from left while all three characters are present
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                minLen = min(minLen, r - l + 1);

                // shrink window
                if (S[l] >= '0' && S[l] <= '2') {
                    freq[S[l] - '0']--;
                }
                l++;
            }
        }

        return (minLen == INT_MAX) ? -1 : minLen;
    }
};

