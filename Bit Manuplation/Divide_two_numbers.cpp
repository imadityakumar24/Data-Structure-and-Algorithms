/*

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0

*/



/*
// copied solution by watching video of striver
// tc = O(logn)^2
// sc = (1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) 
            return 1;
        bool sign = true;
        if (dividend >= 0 && divisor < 0) sign = false;
        else if (dividend <= 0 && divisor > 0) sign = false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        divisor = abs(divisor);

        unsigned int quotient  = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }
            quotient += 1 << cnt;
            n -= (d << cnt);
        }

        if (quotient == (1 << 31) && !sign) {
            return INT_MAX;
        }

        return sign ? quotient : -quotient;
    }
};
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case directly
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert both numbers to long long to prevent overflow
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        // Subtract multiples of divisor using bit shifting
        while (n >= d) {
            long long temp = d;
            long long multiple = 1;

            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            quotient += multiple;
        }

        // Determine the sign of the result
        bool isPositive = (dividend > 0) == (divisor > 0);
        quotient = isPositive ? quotient : -quotient;

        return (int)quotient;
    }
};
