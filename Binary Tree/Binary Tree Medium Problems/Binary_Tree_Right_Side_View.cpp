/*

199. Binary Tree Right Side View

Solved
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,973,784/2.9M
Acceptance Rate
68.2%
Topics
Tree
Depth-First Search
Breadth-First Search
Binary Tree
icon
Companies
Similar Questions

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
// DID BT ME
// ==========  Aproach  =============
// i will be using the level order traversaL and from the each level i will pick the last index values
// brute force solution
// TC = o(n)
// SC = o(n) 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> rightView;          
        if (root == nullptr) return rightView;
       
        queue <TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector <int> level;
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                if (currentNode->left  != nullptr) q.push(currentNode->left);
                if (currentNode->right != nullptr) q.push(currentNode->right);
                level.push_back(currentNode->val);
            }
            
            // inserting the last value of level
            if (level.size() >= 1) {
                int size = level.size();
                rightView.push_back(level[size-1]);
            }
        }
        
        return rightView; 
    }
};
*/

/*
// ======== APROACH ==========  just insert the last value for the level form right side here we  are not using the extra vectors
// better solution
// TC = o(n)
// SC = o(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector <int> rightView;          
        if (root == nullptr) return rightView;
       
        queue <TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* currentNode = q.front();
                q.pop();
                // inserting the last value
                if (i == size-1) rightView.push_back(currentNode->val);

                if (currentNode->left  != nullptr) q.push(currentNode->left);
                if (currentNode->right != nullptr) q.push(currentNode->right);
                
            }
            
        }
        
        return rightView; 
    }
};
*/



// Approach: BFS (level-order traversal)
// Capture the last node of each level → Right Side View
// Time Complexity: O(n)
// Space Complexity: O(n)
// more cleaner and readable code 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        if (root == nullptr) return rightView;
       
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                
                // if this is the last node of the level
                if (i == levelSize - 1) {
                    rightView.push_back(currentNode->val);
                }

                if (currentNode->left)  nodeQueue.push(currentNode->left);
                if (currentNode->right) nodeQueue.push(currentNode->right);
            }
        }
        
        return rightView;
    }
};
