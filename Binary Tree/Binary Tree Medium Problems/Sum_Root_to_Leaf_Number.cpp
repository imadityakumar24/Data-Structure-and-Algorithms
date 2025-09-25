/*

129. Sum Root to Leaf Numbers
Solved
Medium
Topics
premium lock icon
Companies
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,173,472/1.7M
Acceptance Rate
69.0%
Topics
Tree
Depth-First Search
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

/*
class Solution {
private:
    int calculate(TreeNode* root, int rootValue){
        if (root == nullptr) return 0;
        rootValue = rootValue * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return rootValue;
        }
        int left  = calculate(root->left,  rootValue);
        int right = calculate(root->right, rootValue); 
        return left + right; 
    }   
// private section ends here     
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        int rootValue = 0;
        return calculate(root, rootValue);
    }
};
*/



class Solution {
private:
    int dfs(TreeNode* node, int currentSum) {
        if (node == nullptr) return 0;
        currentSum = currentSum * 10 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
