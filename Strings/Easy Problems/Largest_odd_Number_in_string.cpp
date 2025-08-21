/*

1903. Largest Odd Number in String
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 

Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
457,220/693.3K
Acceptance Rate
65.9%

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        if (num.empty()) return "";
        int j = 0;
        for (int i = n-1; i >= 0; i--) {
            if ((num[i] -  '0') % 2 != 0) {
                return num.substr(0, i+1);
            }
        }

        return "";
    }
};