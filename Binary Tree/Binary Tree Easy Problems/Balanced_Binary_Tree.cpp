/*

110. Balanced Binary Tree

Solved
Easy
Topics
premium lock icon
Companies
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,087,999/3.7M
Acceptance Rate
56.1%

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
 


// tc = o(n)
// sc = o(n) for stack space
class Solution {
private:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight  = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }    
public:
    bool isBalanced(TreeNode* root) {
        int height = maxDepth(root);
        if (height == -1) return false;
        return true;
    }
};