/*


=============== Postorder Traversal of Binary Tree using recurrsion =============== 

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


    cout << "        2         " << endl;
    cout << "      /   \\      " << endl;
    cout << "     4     8      " << endl;
    cout << "   /  \\   /  \\  " << endl;
    cout << " 10   12 14   16  " << endl << endl;
     

    cout << "\nPostOrder : ";
    postOrder(root);

    cout << "\n\n";
    return 0;
}


/*

========== OUTPUT ==========

PostOrder : 10 12 4 14 16 8 2


*/