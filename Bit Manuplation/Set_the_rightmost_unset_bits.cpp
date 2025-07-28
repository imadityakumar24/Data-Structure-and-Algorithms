/*

Set the rightmost unset bit
Difficulty: BasicAccuracy: 47.64%Submissions: 64K+Points: 1
Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

Examples :

Input: n = 6
Output: 7
Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.
Input: n = 15
Output: 31
Explanation: The binary representation of 15 is 01111. After setting right most bit it becomes 11111 which is 31.
Expected Time Complexity: O(Logn)
Expected Auxiliary Space: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string deciToBin(int n) {
        string ans = "";
    
        while (n > 0) {
            if (n % 2 == 1) 
                ans = ans + "1";
            else 
                ans = ans + "0";
    
            n = n / 2;    
        }
    
        reverse(ans.begin(), ans.end());
        return ans;
    }
       
public:
    int setBit(int n) {
        if (n < 0) return 0;
        if (n == 1) return 1;
        
        string binary = deciToBin(n);
        int size = binary.size();
        for (int i = size-1; i >=0; i++) {
            if (binary[i] == 0) {
                binary[i] == 1;
            }
        }
        
        int ans;

        
    }
};