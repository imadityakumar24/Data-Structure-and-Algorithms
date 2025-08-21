/*

205. Isomorphic Strings
Solved
Easy
Topics
premium lock icon
Companies
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,886,864/4M
Acceptance Rate
47.2%


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int mapST[256], mapTS[256];
        fill(begin(mapST), end(mapST), -1);
        fill(begin(mapTS), end(mapTS), -1);
        
        for (int i = 0; i < s.length(); i++) {
            char chS = s[i], chT = t[i];
            
            if (mapST[chS] == -1 && mapTS[chT] == -1) {
                mapST[chS] = chT;
                mapTS[chT] = chS;
            } else {
                if (mapST[chS] != chT || mapTS[chT] != chS) {
                    return false;
                }
            }
        }
        return true;
    }
};