/*

42. Trapping Rain Water
Solved
Hard
Topics
premium lock icon
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,014,789/4.6M
Acceptance Rate
65.7%

*/



#include <bits/stdc++.h>
using namespace std;

/*
// brute force solution
// tc = o(n^2)
// sc = o(1)
class Solution {
private:
    int findLeftMax(int index, vector<int>& height) {
        int maxH = 0;
        for (int i = index; i >=0; i--) {
            maxH = max(maxH, height[i]);
        }
        return maxH;
    } 

    int findRightMax(int index, vector<int>& height) {
        int maxH = 0;
        for (int i = index; i < height.size(); i++) {
            maxH = max(maxH, height[i]);
        }
        return maxH;
    } 
// private section ends here 
public:
    int trap(vector<int>& height) {
        int trapedWater = 0;
        int n = height.size();
        
        for (int i = 0; i < n; i++) {
            int leftMax = findLeftMax(i, height);
            int rightMax = findRightMax(i, height);

            trapedWater += min(leftMax, rightMax) - height[i];
        }

        return trapedWater;
    }
};
*/


/*
// better solution
// Approach Used: DP with Prefix & Suffix Arrays
// tc = o(3n)
// sc = o(n) + o(m)
class Solution {
public:
    int trap(vector<int>& height) {
        int trapedWater = 0;
        int n = height.size();
        vector <int> leftMax(n,0);      
        vector <int> rightMax(n,0);  
        
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        } 

        rightMax[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            trapedWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return trapedWater;
    }
};
*/

// litte better
// we can solve this question using stack also but it little confussing so i am used two pointer apraoch which is simple 


// optimal solution using two pointer
// watched sharadha khapre video
// tc = O(n)
// sc = O(1)
class Solution {
public:
    int trap(vector<int>& height)  {
        int water = 0;
        int n = height.size();
        int left = 0, right = n-1, leftMax = 0, rightMax = 0;

        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            // Calculate the trapped water based on the lower maximum height encountered so far (between left_max and right_max)
            // If left_max is less than right_max, the current height at index l can trap water, otherwise, the current height at index r can trap water
            if (leftMax < rightMax) {
                water += leftMax - height[left];
                left++;
            }
            else {
                water += rightMax - height[right];
                right--;
            }
        } 

        return water;
    }
};