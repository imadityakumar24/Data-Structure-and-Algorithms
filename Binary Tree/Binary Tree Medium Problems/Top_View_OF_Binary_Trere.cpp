/*


Top View of Binary Tree

Difficulty: MediumAccuracy: 38.43%Submissions: 411K+Points: 4Average Time: 45m
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note: 

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
Examples:

Input: root[] = [1, 2, 3] 
 
Output: [2, 1, 3]
Input: root[] = [10, 20, 30, 40, 60, 90, 100]
 
Output: [40, 20, 10, 30, 100]
Explanation: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

Expected Complexities
Company Tags
PaytmOla CabsWalmart
Topic Tags
Binary Search TreeTreeData Structures

*/




#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
private:
    // DFS Helper to store top view nodes
    void dfs(Node* node, int hd, int level, 
             map<int, pair<int, int>>& topNodes) {
      
        if (!node) return;
    
        // If horizontal distance is encountered for 
        // the first time or if it's at a higher level
        if (topNodes.find(hd) == topNodes.end() || 
            topNodes[hd].second > level) {
            topNodes[hd] = {node->data, level};
        }
    
        // Recur for left and right subtrees
        dfs(node->left, hd - 1, level + 1, topNodes);
        dfs(node->right, hd + 1, level + 1, topNodes);
    }
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;
        
        // Horizontal distance -> {node's value, level}
        map<int, pair<int, int>> topNodes; 
        
        // Start DFS traversal
        dfs(root, 0, 0, topNodes);
    
        // Collect nodes from the map
        for (auto it : topNodes) {
            result.push_back(it.second.first);
        }
    
        return result;
    }
};