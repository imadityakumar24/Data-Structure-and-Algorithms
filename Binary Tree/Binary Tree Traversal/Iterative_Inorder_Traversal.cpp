/*


===============  Iterative Inorder Traversal of Binary Tree  =============== 


*/


/*

Inorder Traversal
Difficulty: EasyAccuracy: 67.15%Submissions: 197K+Points: 2Average Time: 15m
Given a Binary Tree, your task is to return its In-Order Traversal.

An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

Follow Up: Try solving this with O(1) auxiliary space.

Examples:

Input: root[] = [1, 2, 3, 4, 5] 
      
Output: [4, 2, 5, 1, 3]
Explanation: The in-order traversal of the given binary tree is [4, 2, 5, 1, 3].
Input: root[] = [8, 1, 5, N, 7, 10, 6, N, 10, 6]
      
Output: [1, 7, 10, 8, 6, 10, 5, 6]
Explanation: The in-order traversal of the given binary tree is [1, 7, 10, 8, 6, 10, 5, 6].
Constraints:

1 <= number of nodes <= 105
0 <= node->data <= 105
Expected Complexities
Company Tags
AmazonSnapdealAdobe

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



/*
Approach:
- Use a stack to simulate recursion.
- Start from the root node and push all left children into the stack until reaching NULL.
- Pop the top node from the stack, process it (add value to result), and then move to its right child.
- Repeat until both stack is empty and current node is NULL.

Time Complexity: O(n)  
    - Each node is pushed and popped from the stack once.
Space Complexity: O(n)  
    - In the worst case (skewed tree), stack stores O(n) nodes.
*/
/*
class Solution {
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        stack<Node*> st;
        Node* current = root;

        while (current != nullptr || !st.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Current is NULL here, so pop the top of the stack
            current = st.top();
            st.pop();

            // Add the node's value to result
            result.push_back(current->data);

            // Visit the right subtree
            current = current->right;
        }

        return result;
    }
};
*/




// using 2 stack
// first time visit : right node left
// second time visit : pront node
class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack <Node*> st;
        stack <bool>   visited;
        
        if (root == NULL) return ans;
        
        st.push(root);
        visited.push(0);
        
        while (!st.empty()) {
            Node* temp = st.top();     st.pop();
            bool flag = visited.top(); visited.pop();
            
            // first time visit
            if (flag == 0) {
                // right
                if (temp->right) {
                    st.push(temp->right);
                    visited.push(0);
                }
                // node
                st.push(temp);
                visited.push(1);
                // left
                if (temp->left) {
                    st.push(temp->left);
                    visited.push(0);
                }
            }
            else {  // second time visit
                ans.push_back(temp->data);
            }
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
     
    vector <int> ans = obj.inOrder(root); 

    cout << "\nInorderOrder : ";
    for (auto i : ans) cout << i << " ";
    

    cout << "\n\n";
    return 0;
}
























