/*

121. Best Time to Buy and Sell Stock
Solved
Easy
Topics
premium lock icon
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
 
Seen this question in a real interview before?
1/5

*/





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, cost = 0;
        int mini = prices[0];

        for(int i = 0; i < n; i++) {
           cost = prices[i] - mini;
           profit = max(profit, cost);
           mini = min(mini, prices[i]);
        }

        return profit;  
    }
};



/*

// Time limit exceded
// tc = O(N^2)   for loop is n and *max_element( ); id n so it become n square
// SC = O(N)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, maxProfit = 0, maxElement;

        for(int i = 0; i < n; i++) {
            maxElement = *max_element(prices.begin()+i, prices.end());
            if(maxElement > prices[i]) {
                profit = maxElement - prices[i];
            }
            maxProfit = max( maxProfit, profit);
        }

        return maxProfit;  
    }
};

*/

/*

// Time limit exceded
// tc = O(N^2)
// SC = O(N)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, maxProfit = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(prices[j] > prices[i]) {
                    profit = prices[j] - prices[i];
                }
                maxProfit = max( maxProfit, profit);
            }
        }

        return maxProfit;  
    }
};

*/