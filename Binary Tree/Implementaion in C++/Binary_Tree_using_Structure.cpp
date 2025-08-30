

/*

==========================  Binary tree using Structure  ==========================

Properties of Binary Tree:

1. Maximum nodes at level l = 2^l
2. Maximum nodes in tree of height h = 2^(h+1) - 1
3. Minimum height for n nodes = ⌈log2(n+1)⌉ - 1
4. In a binary tree, leaf nodes (n0) = nodes with 2 children (n2) + 1
5. Full Binary Tree: each node has 0 or 2 children
6. Perfect Binary Tree: all levels filled, total nodes = 2^(h+1) - 1
7. Complete Binary Tree: all levels filled except last, filled left to right
8. Height of single node tree = 0
9. Binary Tree of height h has at least h+1 nodes
10. A skewed tree (all left or all right children) behaves like a linked list


--------------------------------------------
Time Complexity of Operations (Linked Tree):
--------------------------------------------
- Traversals (Inorder, Preorder, Postorder) : O(n)
- Searching (general binary tree)           : O(n)
- Searching (if Binary Search Tree, BST)    : O(h), best O(log n), worst O(n)
- Insertion (at left/right child)           : O(1) (if pointer known), O(n) (if search needed)
- Deletion                                  : O(n) (general), O(h) in BST
- Height/Depth Calculation                  : O(n)
- Space Complexity                          : O(n) (pointers + recursion stack O(h))


*/


#include <iostream>
using namespace std;

// Node class for binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder Traversal (Left -> Root -> Right)
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Preorder Traversal (Root -> Left -> Right)
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Postorder Traversal (Left -> Right -> Root)
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    // Creating the tree manually
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);

    root->left->left = new Node(6);
    root->right->right = new Node(8);

    root->left->left->left = new Node(10);
    root->right->right->right = new Node(12);

    cout << "PreOrder  : ";
    preOrder(root);

    cout << "\nInOrder   : ";
    inOrder(root);

    cout << "\nPostOrder : ";
    postOrder(root);

    cout << "\n\n";
    return 0;
}




/*
Output:

PreOrder  : 1 2 6 10 4 8 12
InOrder   : 10 6 2 1 4 8 12
PostOrder : 10 6 2 12 8 4 1

*/

