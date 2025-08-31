/*

102. Binary Tree Level Order Traversal

Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,002,804/4.2M
Acceptance Rate
71.2%

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


// TC = O(n)
// SC = O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr) return ans;
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector <int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* data = q.front();
                q.pop();
                if (data->left != nullptr) q.push(data->left);
                if (data->right != nullptr) q.push(data->right);
                temp.push_back(data->val);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};