/*

543. Diameter of Binary Tree

Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
 
Discover more
Coding Challenges App
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,190,921/3.4M
Acceptance Rate
64.2%

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
// brute force solution
// tc = o(n^2)
// sc = 
class Solution {
private:
    int maxDepth(TreeNode* root) {     // o(n)
        if (root == nullptr) {
            return 0;
        }

        int leftHeight  = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return max(leftHeight, rightHeight) + 1;
    }    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDiameter    = diameterOfBinaryTree(root->left);
        int rightDiameter   = diameterOfBinaryTree(root->right);
        int currentDiameter = maxDepth(root->left) + maxDepth(root->right);

        return max(currentDiameter, max(leftDiameter, rightDiameter));
    }
};
*/


// optimal solution
// tc = o(n)
// sc = o(n)
class Solution {
public:

    int ans = 0;

    int maxDepth(TreeNode* root) {     // o(n)
        if (root == nullptr) {
            return 0;
        }

        int leftHeight  = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int currentDiameter = leftHeight + rightHeight;

        ans = max(ans, currentDiameter);

        return max(leftHeight, rightHeight) + 1;
    }    

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        maxDepth(root);

        return ans;
    }
};