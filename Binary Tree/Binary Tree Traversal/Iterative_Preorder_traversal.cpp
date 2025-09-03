/*


===============  Iterative Preorder Traversal of Binary Tree  =============== 


*/


/*

Preorder Traversal

Difficulty: BasicAccuracy: 62.73%Submissions: 186K+Points: 1Average Time: 15m
Given a binary tree, find its preorder traversal.

Examples:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: [1, 4, 4, 2]
Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: [6, 3, 1, 2, 2] 
Input:
         8
       / \
      3   10
     / \    \
    1   6   14
       / \   /
      4   7 13
Output: [8, 3, 1, 6, 4, 7, 10, 14, 13]
Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 106

Expected Complexities
Company Tags
FlipkartAmazonMicrosoftWalmart

*/






#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};



// Iterative Preorder Traversal of Binary Tree

/*
Approach:
- Preorder follows Root → Left → Right.
- Use a stack to simulate recursion.
- Push the root node into the stack.
- While stack is not empty:
    1. Pop the top node, process it (add its value to result).
    2. Push the right child first (if exists).
    3. Push the left child (if exists).
- This ensures left child is processed before the right child since stack is LIFO.
- Continue until stack is empty.

Time Complexity: O(n)  
    - Each node is visited exactly once.
Space Complexity: O(2n) ≈ O(n)  
    - O(n) for storing traversal result and O(n) for stack in worst case (skewed tree).
*/

// iterative preorder traversal of binary tree
// tc = o(n)
// sc = o(2n)  o(n) for stack and 0(n) for ans
class Solution {
public:
    // root left right
    vector<int> preorder(Node* root) {
        stack <Node*> st;
        st.push(root);
        vector <int> ans;
        
        while (!st.empty()) {
            Node* temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            
            // if (temp->right != nullptr)
            //     st.push(temp->right);
            // if (temp->left != nullptr)
            //     st.push(temp->left);  
            
            // above and below code is same
            
            if (temp->right)
                st.push(temp->right);
            if (temp->left)
                st.push(temp->left);          
        }
        
        return ans;
    }
};


int main() {
    cout << "\n\n";

    Solution obj;

    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(10);
    root->left->right = new Node(12);

    root->right->left = new Node(14);
    root->right->right = new Node(16);

    cout << "        2         " << endl;
    cout << "      /   \\      " << endl;
    cout << "     4     8      " << endl;
    cout << "   /  \\   /  \\  " << endl;
    cout << " 10   12 14   16  " << endl << endl;
     
    vector <int> ans = obj.preorder(root); 

    cout << "\nPreOrder : ";
    for (auto i : ans) cout << i << " ";
    

    cout << "\n\n";
    return 0;
}
