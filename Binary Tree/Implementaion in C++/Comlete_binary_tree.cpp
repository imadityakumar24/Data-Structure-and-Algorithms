/*


===============  Complete Binary Tree  =============== 

Complete Binary Tree: all levels filled except last, filled left to right

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
     cout << "\n\n";

    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(10);
    root->left->right = new Node(12);

    root->right->left = new Node(14);
    root->right->right = new Node(16);


    /*
    
                         2
                      /    \
                     4       8
                   /  \    /   \
                 10   12  14    16
    */

    // cout <<          "2" << endl;
    // cout <<       "/    \" << endl;
    // cout <<      "4       8" << endl;
    // cout <<    "/  \    /   \" << endl;
    // cout <<  "10   12  14    16" << endl;

    cout << "        2"         << endl;
    cout << "      /   \\"      << endl;
    cout << "     4     8"      << endl;
    cout << "   /  \\   /  \\"  << endl;
    cout << " 10   12 14   16"  << endl << endl;
     

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

========== OUTPUT ==========

PreOrder  : 2 4 10 12 8 14 16
InOrder   : 10 4 12 2 14 8 16
PostOrder : 10 12 4 14 16 8 2


*/