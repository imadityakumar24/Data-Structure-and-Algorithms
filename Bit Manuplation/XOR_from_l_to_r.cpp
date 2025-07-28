/*

Find XOR of numbers from L to R.
Difficulty: EasyAccuracy: 50.0%Submissions: 66K+Points: 2Average Time: 10m
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
Your Task:

Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).

Expected Auxiliary Space: O(1).

Constraints:

1<=l<=r<=109

*/

// refer TUF article for beter understanding


// User function Template for C++

/*
// Brute force solution using bit manuplation
// but giving tle
// tc = O(l - r)
// sc = O(1)
class Solution {
  public:
    int findXOR(int l, int r) {
        
        int result = 0;
        for (int i = l; i <= r; i++) {
            result = result ^ i;
        }
        return result;
        
    }
};
*/

// Brute force solution using xor cyclic behavoir of xor of consecutive number
// tc = O(l)
// sc = O(1)
class Solution {
private:
    int xorOfNumber(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n+1;
        if (n % 4 == 3) return 0;
        return 0;
    }
public:    
    int findXOR(int l, int r) {
        
        int xorOfL = xorOfNumber(l-1); 
        int xorOfR = xorOfNumber(r);
        
        return xorOfL ^ xorOfR;
    }
};

/*

int xorFrom1ToN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}


*/