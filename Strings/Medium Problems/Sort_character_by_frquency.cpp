/*

451. Sort Characters By Frequency
Solved
Medium
Topics
premium lock icon
Companies
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
969,342/1.3M
Acceptance Rate
74.5%

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Store characters and their frequencies in a vector
        vector<pair<int, char>> freqVec;
        for (auto &it : freq) {
            freqVec.push_back({it.second, it.first});
        }

        // Step 3: Sort the vector in decreasing order of frequency
        sort(freqVec.rbegin(), freqVec.rend());

        // Step 4: Build the result string
        string result = "";
        for (auto &it : freqVec) {
            result += string(it.first, it.second); // Append character 'it.first' times
        }

        return result;
    }
};