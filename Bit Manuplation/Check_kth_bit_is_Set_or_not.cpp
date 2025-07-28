/*

Given two positive integer n and  k, check if the kth index bit of n is set or not.
 Note: A bit is called set if it is 1. 

Examples : 

Input: n = 4, k = 0
Output: false
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Input: n = 4, k = 2
Output: true
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
Input: n = 500, k = 3
Output: false
Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.

*/



/*
// Brute force solution
// did by myself 
// tc = o(n)    for converting decimal to binary
// sc = o(1) or O(lenth of string)
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
    bool checkKthBit(int n, int k) {
        string bits = deciToBin(n);
        int size = bits.size();
        if (k < 0 || k > size) 
            return false;
         
         
        if (bits[size-k-1] == '1') { // if 1 means bit is set otherwise is not set 
            return true;
        }    
        
        return false;
    }
};
*/


// Optimal solution using bit maniplation
// tc = o(1)
// sc = 0(1)
class Solution {
public:
    bool checkKthBit(int n, int k) {
        
        int ans = n & (1 << k);
        if (ans > 0) 
            return true;
        
        return false;
    }
};
