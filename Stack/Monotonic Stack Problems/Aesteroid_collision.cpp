/*

735. Asteroid Collision

Solved
Medium
Topics
premium lock icon
Companies
Hint
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
853,214/1.9M
Acceptance Rate
45.9%

*/





#include <bits/stdc++.h>
using namespace std;



/*
// brute force solution using 2 stack
// did by me
// tc = o(n^2) + o(n)
// sc = o(lst) + o(rst)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack <int> rst, lst;

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                rst.push(asteroids[i]);
            }
            else {
                lst.push(asteroids[i]);
                while (!rst.empty() && !lst.empty()) {
                    int lstValue = -1 * lst.top();
                    // int lstValue = lst.top();
                    if (rst.top() == lstValue) {
                        rst.pop();
                        lst.pop();
                        break; // stop, nothing left to collide now
                    }
                    else if (rst.top() < lstValue) {
                        rst.pop();
                        if (rst.empty()) break; // no more right asteroids
                    }
                    else {
                        lst.pop();
                        break;
                    }
                }
            }
        }

        vector <int> ans;
        // negative stack
        if (lst.empty()) {
            while (!rst.empty()) {
                ans.push_back(rst.top());
                rst.pop();
            }
            reverse(ans.begin(), ans.end());
        }
        else {
            vector <int> nValues;  // for string negative value
            while (!lst.empty()) {
                nValues.push_back(lst.top());
                lst.pop();
            }
            reverse(nValues.begin(), nValues.end());

            vector <int> pValues;
            while (!rst.empty()) {
                pValues.push_back(rst.top());
                rst.pop();
            }
            reverse(pValues.begin(), pValues.end());


            for (int i = 0; i < nValues.size(); i++) {
                ans.push_back(nValues[i]);
            }
            for (int i = 0; i < pValues.size(); i++) {
                ans.push_back(pValues[i]);
            }
        }


        // vector<int> ans;
        // vector<int> negVals, posVals;

        // while (!lst.empty()) {
        //     negVals.push_back(lst.top());
        //     lst.pop();
        // }
        // reverse(negVals.begin(), negVals.end());

        // while (!rst.empty()) {
        //     posVals.push_back(rst.top());
        //     rst.pop();
        // }
        // reverse(posVals.begin(), posVals.end());

        // ans.insert(ans.end(), negVals.begin(), negVals.end());
        // ans.insert(ans.end(), posVals.begin(), posVals.end());

        return ans;
    }
};
*/

// optimal solution using 1 stack
// did by me
// tc = o(n)
// sc = o(st) + o(n) for string ans
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                // int value = -1 * asteroids[i];
                // if (!st.empty() && st.top() == value) {
                //     st.pop();
                //     continue;
                // }

                // if (st.empty()) st.push(asteroids[i]);
                // else if (!st.empty() && st.top() < value) {
                //     while (!st.empty() && st.top() <= value) {
                //         st.pop();
                //     }
                // }
                // // else  (!st.empty() && value < st.top()) {
                // else {
                //     continue;
                // }

                int value = -asteroids[i];

                // while there is a right-moving asteroid that collides
                while (!st.empty() && st.top() > 0 && st.top() < value) {
                    st.pop(); // smaller right asteroid destroyed
                }

                if (!st.empty() && st.top() > 0 && st.top() == value) {
                    st.pop(); // both destroyed
                } else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]); // survives, push negative
                }
                // else: current negative destroyed (do nothing)
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};