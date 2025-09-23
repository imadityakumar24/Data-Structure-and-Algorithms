/*

101. Symmetric Tree
Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,611,675/4.4M
Acceptance Rate
59.9%
Topics

*/




#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) 
            return true;
        if (left == nullptr || right == nullptr) 
            return false;

        if (left->val != right->val) 
            return false;

        // Must check both sides for symmetry
        return check(left->left, right->right) && check(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return check(root->left, root->right);
    }
};

// Example usage
int main() {
    /*
         1
        / \
       2   2
      / \ / \
     3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    if (sol.isSymmetric(root))
        cout << "Tree is symmetric" << endl;
    else
        cout << "Tree is not symmetric" << endl;

    return 0;
}
