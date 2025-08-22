
/*

Remove Consecutive Characters
Difficulty: EasyAccuracy: 53.35%Submissions: 104K+Points: 2
You are given a string s, consisting of lowercase alphabets. Your task is to remove consecutive duplicate characters from the string. 

Example:

Input: s = "aabb"
Output:  "ab" 
Explanation: 
The character 'a' at index 2 is the same as 'a' at index 1, so it is removed.
Similarly, the character 'b' at index 4 is the same as 'b' at index 3, so it is removed.
The final string is "ab".
Input:s = "aabaa"
Output: "aba"
Explanation: 
The character 'a' at index 2 is the same as 'a' at index 1, so it is removed.
The character 'a' at index 5 is the same as 'a' at index 4, so it is removed.
The final string is "aba".
Input: s = "abcddcba"
Output: "abcdcba"
Explanation: 
The character 'd' at index 5 is the same as 'd' at index 4, so it is removed.
No other consecutive duplicates exist.
The final string is "abcdcba".
Constraints:
1 ≤ n ≤ 106
All characters in the string are lowercase English alphabets.

*/




#include <bits/stdc++.h>
using namespace std;



/*
// brute force solution
// tc = o(n)
// sc = o(1)
class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        if (s.empty()) return "";
        string ans = "";
        ans = s[0];
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) 
                ans = ans + s[i];
        }
        
        return ans;
    }
};
*/

/*
// Recursive solution
// tc = o(n)
// sc = o(1)
class Solution {
private:
    string removeDublicate(string& s, string& ans, int index) {
        if (index == s.size()) {
            return ans;
        }    
        if (s[index] != s[index-1]) {
            ans = ans + s[index];
            index++;
            return removeDublicate(s, ans, index);
        }
        else {  
            index++;
            return removeDublicate(s, ans, index);
        }    
    }
public:
    string removeConsecutiveCharacter(string& s) {
        if (s.empty()) return "";
        string ans = "";
        ans = s[0];
        removeDublicate(s, ans, 1);
        
        return ans;
    }
};
*/



// optimized Recursive solution
// tc = o(n)
// sc = o(1)
class Solution {
private:
    void removeDublicate(string& s, string& ans, int index) {
        if (index == s.size()) {
            return;
        }    
        if (s[index] != s[index-1]) {
            ans.push_back(s[index]);
        }
            
        removeDublicate(s, ans, index+1);
    }
public:
    string removeConsecutiveCharacter(string& s) {
        if (s.empty()) return "";
        string ans = "";
        ans.push_back(s[0]);
        removeDublicate(s, ans, 1);
        
        return ans;
    }
};