/*

3. Longest Substring Without Repeating Characters

Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
7,988,096/21.4M
Acceptance Rate
37.4%

*/




#include <bits/stdc++.h>
using namespace std;


/*
// brute force solution
// tc = o(n^2) + o(n)
// sc = O(n^2) , o(n) for map and 0(n) for vector str
class Solution {
private:
    string fetchChar(unordered_set<char>& ch) {
        string value = "";
        for (char c : ch) {
            value += c;
        }
        return value;
    }

public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        vector<string> str;

        int size = s.size();
        for (int i = 0; i < size; i++) {
            unordered_set<char> ch;
            // for (int j = i; j >= i; j++) {
            //     auto it = ch.find(s[j]);
            //     if (it == ch.end()) {
            //         ch.insert(s[j]);
            //     }
            // }

            for (int j = i; j < s.size(); j++) {
                if (ch.find(s[j]) != ch.end())
                    break;
                ch.insert(s[j]);
            }

            string temp = fetchChar(ch);
            str.push_back(temp);
        }

        int largest = INT_MIN;
        for (int i = 0; i < str.size(); i++) {
            int size = str[i].size();
            largest = max(size, largest);
        }

        return largest;
    }
};
*/


/*
// better  solution
// did by me 
// tc = o(n^2) 
// sc = o(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int longest = INT_MIN;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            unordered_set<char> charMap;
            for (int j = i; j < s.size(); j++) {
                if (charMap.find(s[j]) != charMap.end()){
                    break;
                }    
                charMap.insert(s[j]);
            }
            int mpSize = charMap.size();
            longest = max(longest, mpSize); 
        }

        return longest;
    }
};
*/



// optimal solution using sliding window algorithm
// did by me 
// tc = o(n)
// sc = o(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int longest = INT_MIN;
        int size = s.size();
        int l = 0, r = 0;
        vector <int> hash(256, -1);

        while (r < size) {
            if (hash[s[r] != -1]) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            int lenth = r - l + 1;
            longest = max(lenth, longest); 
            hash[s[r]] = r;
            r++;
        }

        return longest;
    }
};