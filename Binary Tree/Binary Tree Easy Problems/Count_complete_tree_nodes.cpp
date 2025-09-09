/*
  
=====================  222. Count Complete Tree Nodes  =====================


Solved
Easy
Topics
premium lock icon
Companies
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
 
Discover more
Coding Courses
programming
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,033,617/1.5M
Acceptance Rate
70.8%

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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftNodeCount  = countNodes(root->left);
        int rightNodeCount = countNodes(root->right);

        return leftNodeCount + rightNodeCount + 1;
    }
};