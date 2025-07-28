/*

875. Koko Eating Bananas
Solved
Medium
Topics
premium lock icon
Companies
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long int calculateTotalHours(vector<int>& v, int hourly) {
        long long int totalH = 0;
        int n = v.size();
        // find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil(v[i] / (double)hourly);
            // totalH += (v[i] + hourly - 1) / hourly;
        }
        return totalH;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(), piles.end());
        int left = 1, right = maxElement;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long int reqTime = calculateTotalHours(piles, mid);
            if (reqTime <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};