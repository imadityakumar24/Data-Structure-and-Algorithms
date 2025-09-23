/*

Left View of Binary Tree

Difficulty: EasyAccuracy: 33.74%Submissions: 579K+Points: 2Average Time: 20m
Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.

Examples :

Input: root[] = [1, 2, 3, 4, 5, N, N]

Output: [1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

Constraints:
0 <= number of nodes <= 106
0 <= node -> data <= 105

Expected Complexities
Company Tags
Paytm Flipkart Accolite Amazon OYO Rooms Samsung Snapdeal MakeMyTrip Ola Cabs Adobe Qualcomm Twitter Knowlarity Open Solutions


*/



#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 
 

/* 
// DID BT ME
// ==========  Aproach  =============
// i will be using the level order traversaL and from the each level i will pick the first index values
// brute force solution
// TC = o(n)
// SC = o(n)
class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector <int> leftView;          
        if (root == nullptr) return leftView;
       
        queue <Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector <int> level;
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                Node *currentNode = q.front();
                q.pop();
                if (currentNode->left  != nullptr) q.push(currentNode->left);
                if (currentNode->right != nullptr) q.push(currentNode->right);
                level.push_back(currentNode->data);
            }
            
            // inserting the first value of level
            if (level.size() >= 1) {
                leftView.push_back(level[0]);
            }
        }
        
        return leftView; 
    }
};
*/


// better  solution
// here we are only using 1 vector to store the ans
// tc = o(n)
// sc = o(n)
class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector <int> leftView;          
        if (root == nullptr) return leftView;
       
        queue <Node*> q;
        q.push(root);
        
        while (!q.empty()) {
         
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                Node *currentNode = q.front();
                q.pop();
                // the first node of each level
                if (i == 0) {
                    leftView.push_back(currentNode->data);
                }
                if (currentNode->left  != nullptr) q.push(currentNode->left);
                if (currentNode->right != nullptr) q.push(currentNode->right);
            }
            
            
        }
        
        return leftView; 
    }
};
























