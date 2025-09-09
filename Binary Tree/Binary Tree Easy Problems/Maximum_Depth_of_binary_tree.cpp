
/*

==========================  104. Maximum Depth of Binary Tree  ==========================

Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
4,238,093/5.5M
Acceptance Rate
77.4%
Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree

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
 

// Optimal solution using recursion
// to understnd dry run on paper you get the thought process
// TC = O(n)  for traversing all the nodes
// SC = O(h), where h is the height of the tree (O(n) worst case, O(log n) best case).
// There is no extra data structure used (no arrays, vectors, hashmaps, etc.).
// But recursion itself uses the function call stack.  

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight  = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
};