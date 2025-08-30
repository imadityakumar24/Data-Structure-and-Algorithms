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
 

// Preorder Traversal (Root -> Left -> Right)
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
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


    cout << "        2         " << endl;
    cout << "      /   \\      " << endl;
    cout << "     4     8      " << endl;
    cout << "   /  \\   /  \\  " << endl;
    cout << " 10   12 14   16  " << endl << endl;


    cout << "PreOrder : ";
    preOrder(root);


    cout << "\n\n";
    return 0;
}




/*

========== OUTPUT ==========

PreOrder  : 2 4 10 12 8 14 16


*/