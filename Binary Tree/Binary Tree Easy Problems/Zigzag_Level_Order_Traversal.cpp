/*

103. Binary Tree Zigzag Level Order Traversal

Solved
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,585,942/2.5M
Acceptance Rate
62.3%

*/




#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



/*
============ Aproach ===========

i will use the level order traversal exact same code
after the level order traversal
i will reverse the odd position vector 
so it become the zig zig traveresal
*/

/*
// brute force solution
// tc = o(n) + o(n) for reversing 
// sc = o(n) for ans o(n) for stack space
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr) return ans;
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector <int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* data = q.front();
                q.pop();
                if (data->left != nullptr) q.push(data->left);
                if (data->right != nullptr) q.push(data->right);
                level.push_back(data->val);
            }
            ans.push_back(level);
        }

        // now reverse the ith postiion vector 
        // because ans all indexex storing the vector 
        for (int i = 1; i < ans.size(); i = i+2) {
            reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};
*/





/*

============ Aproach ===========

i will use the level order traversal exact same code
after the level order traversal
i will reverse the odd position vector 
so it become the zig zig traveresal

*/
// better solution
// tc = o(n) 
// sc = o(n) for ans o(n) for stack space
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr) return ans;
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector <int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* data = q.front();
                q.pop();
                if (data->left != nullptr) q.push(data->left);
                if (data->right != nullptr) q.push(data->right);
                level.push_back(data->val);
            }
            // now reverse the ith postiion vector who index is odd
            // because ans all indexex storing the vector
            if (ans.size() % 2 != 0) {
                reverse(level.begin(), level.end());
                ans.push_back(level);
            } 
            else {
                ans.push_back(level);
            }
        }

        return ans;
    }
};