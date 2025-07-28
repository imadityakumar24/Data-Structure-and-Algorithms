/*

Count set bits
Difficulty: MediumAccuracy: 35.77%Submissions: 233K+Points: 4
You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).

Examples :

Input: n = 4
Output: 5
Explanation: For numbers from 1 to 4. For 1: 0 0 1 = 1 set bits For 2: 0 1 0 = 1 set bits For 3: 0 1 1 = 2 set bits For 4: 1 0 0 = 1 set bits Therefore, the total set bits is 5.
Input: n = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), the total number of set bits is 35.

*/




/*
// brute force solution
// tc = o(n^2)
// sc = O(n)   no of lenth
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
    
    int countBit(string ans) {
        int s = ans.size();
        int count = 0;
        for (int i = 0; i < s; i++) {
            if (ans[i] == '1') {
                count++;
            }
        }
        return count;
    }
// private section ends here    
public:
    int countSetBits(int n) {
        if (n < 0 || n == 0) {
           return 0;
        }
        
        int totalBit = 0;
       
        for (int i = 1; i <= n; i++) {
            string ans = deciToBin(i);
            totalBit += countBit(ans);
        }
        
        return totalBit;
    }
};
*/


// optimal solution uisng bit maniplation
// TC = O(n log n)
// SC = o(1)
class Solution {
private:
    // Using Brian Kernighan's algorithm
    int count(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }    
public:
    int countSetBits(int n) {
        if (n < 0 || n == 0) {
           return 0;
        }
        
        int totalBit = 0;
       
        for (int i = 1; i <= n; i++) {
            totalBit = totalBit + count(i);
        } 
        
        return totalBit;
    }
};
