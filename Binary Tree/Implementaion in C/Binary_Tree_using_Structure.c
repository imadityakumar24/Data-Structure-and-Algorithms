
/*

==========================  Binary tree using structure  ==========================

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
- Searching (if Binary Search Tree, BST)    : O(h), best case O(log n), worst O(n)
- Insertion (at left/right child)           : O(1) (if pointer known), O(n) (if search needed)
- Deletion                                  : O(n) (general), O(h) in BST
- Height/Depth Calculation                  : O(n)
- Space Complexity                          : O(n) (for pointers + recursion stack O(h))

*/

#include <stdio.h>
#include <stdlib.h>   // for malloc(), free()

struct node {
    struct node* left;
    int data;
    struct node* right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Preorder Traversal (Root -> Left -> Right)
void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Postorder Traversal (Left -> Right -> Root)
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    printf("\n\n");

    struct node* root = createNode(1);

    root->left  = createNode(2);
    root->right = createNode(4);

    root->left->left  = createNode(6);
    root->right->right = createNode(8);

    root->left->left->left = createNode(10);
    root->right->right->right = createNode(12);

    printf("\nPreOrder  : ");
    preOrder(root);
     
    printf("\nInOrder   : ");
    inOrder(root);
    
    printf("\nPostOrder : ");
    postOrder(root);

    printf("\n\n");
    return 0;
}

/*

========= OUTPUT =========

PreOrder  : 1 2 6 10 4 8 12
InOrder   : 10 6 2 1 4 8 12
PostOrder : 10 6 2 12 8 4 1

*/
