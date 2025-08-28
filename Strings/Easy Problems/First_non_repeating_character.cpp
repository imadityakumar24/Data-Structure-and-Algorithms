/*

Non Repeating Character

Difficulty: EasyAccuracy: 40.43%Submissions: 310K+Points: 2Average Time: 30m
Given a string s consisting of lowercase English Letters. return the first non-repeating character in s. If there is no non-repeating character, return '$'.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.
Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.
Input: s = "aabbccc"
Output: '$'
Explanation: All the characters in the given string are repeating.
Constraints:
1 ≤ s.size() ≤ 105

Expected Complexities
Company Tags
FlipkartAmazonMicrosoftD-E-ShawMakeMyTripOla CabsPayuTeradataGoldman SachsMAQ SoftwareInfoEdgeOATS SystemsTejas Network

*/





#include <bits/stdc++.h>
using namespace std;


// TC = O(2n)
// Sc = o(1)
class Solution {
public:
    char nonRepeatingChar(string &s) {
        int size = s.size();
        unordered_map <int, int> mp;
        
        for (int i = 0; i < size; i++) {
            mp[s[i]]++;
        }
        
        for (auto ch : s) {
            if (mp[ch] == 1) 
                return ch;
        }
        
        return '$';
    }
};