/*

84. Largest Rectangle in Histogram

Solved
Hard
Topics
premium lock icon
Companies
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,285,750/2.7M
Acceptance Rate
48.0%

*/



#include <bits/stdc++.h>
using namespace std;


/*
// Brute force aproach giving TLE
// tc = p(n^2)
// sc = o(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        if (n == 0) return 0;
        if (n == 1) return heights[0];
        if (n == 2) {
            if (heights[1] <= 0) 
                return heights[0];
            if (heights[0] <= 0)   
                return heights[1];

            if (heights[1] > heights[0]) {
                int diff = heights[1] - heights[0];
                return heights[0] + (heights[1] - diff);
            }
            else {
                int diff = heights[0] - heights[1];
                return heights[1] + (heights[0] - diff);
            }
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int minHeight = INT_MAX;
            for (int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j - i + 1));
            }
        }

        return maxArea;
    }
};
*/


// Better apraoch using stack 
// tc = o(2n) + o(2n) + o(n)
// sc = o(1)
class Solution {
private:
    vector <int> getNSL(vector<int>& arr, int n) {
        vector <int> result(n);
        stack <int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty())
                result[i] = -1;
            else 
                result[i] = st.top();   

            st.push(i);     
        }

        return result;
    }


    vector <int> getNSR(vector<int>& arr, int n) {
        vector <int> result(n);
        stack <int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty())
                result[i] = n;
            else 
                result[i] = st.top();   

            st.push(i);     
        }

        return result;
    }
// private section ends here 
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> NSL = getNSL(heights, n);
        vector <int> NSR = getNSR(heights, n);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // int area = ((NSR[i] - NSL[i]) + 1) * heights[i];
            // int area = heights[i] * (NSR[i] - NSL[i] + 1);
            int width = NSR[i] - NSL[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};