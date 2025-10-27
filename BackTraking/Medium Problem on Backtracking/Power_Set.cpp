/*

Power Set
Difficulty: MediumAccuracy: 43.3%Submissions: 110K+Points: 4
Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.

Example 1:

Input : 
s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.
Example 2:

Input: 
s = "aa"
Output: 
a a aa
Explanation : 
There are a total 3 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.
Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically sorted order.

Expected Time Complexity: O( n*2n  )
Expected Space Complexity: O( n * 2n )

Constraints: 
1 <= n <= 16
s constitutes of lower case english alphabets

Company Tags
Snapdeal

*/


#include <bits/stdc++.h>
using namespace std;

// recursiove solution
// same question as subset leetcode
// TC = O(2^n) + nlogn  for sort
// SC = o(n)
class Solution {
private:
    void solve (string &s, string &temp, vector<string> &result, int i) {
        if (i == s.size()) {
            if (!temp.empty()) {
                result.push_back(temp);
                // return;
            }
            return;
        }

        temp.push_back(s[i]);
        // don't use i++
        solve(s, temp, result, i+1);     // answer mai le liya or take case of value
        temp.pop_back();
        // don't use i++
        solve(s, temp, result, i+1);     // answer mai nhi liya or not take case of value
    }
public:
    vector<string> AllPossibleStrings(string s) {
        
        vector<string> result;
        if (s.empty()) return result;
        
        string temp;
        solve(s, temp, result, 0);
        sort(result.begin(), result.end());
        
        return result;
    }
};