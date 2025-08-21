/*

151. Reverse Words in a String
Solved
Medium
Topics
premium lock icon
Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,533,190/4.8M
Acceptance Rate
53.1%

*/




#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length(), i = 0;
        reverse(s.begin(), s.end());
        string ans = "";

        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;

            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if (!ans.empty()) 
                ans += " ";
            // if (word.length() > 0) {
            //     ans += word;
            // }
            ans += word;
        }

        return ans;
    }
};