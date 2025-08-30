

/*


==========================  Binary tree using array  ==========================


Properties of Array Representation:

1. Root is stored at index 0
2. For node at index i:
   -> Left child  = 2*i + 1
   -> Right child = 2*i + 2
   -> Parent      = (i-1)/2
3. Works best for Complete Binary Trees (like Heaps)
4. Wastes memory for sparse trees


Properties of Array Representation (Index starting from 1):

1. Root is stored at index 1
2. For a node at index i:
   -> Left child  = 2 * i
   -> Right child = 2 * i + 1
   -> Parent      = i / 2   (integer division)
3. Works best for Complete Binary Trees (like Heaps)
4. Wastes memory for sparse trees



Additional Properties of Binary Trees:

5. Maximum nodes at level l = 2^l
6. Maximum nodes in a tree of height h = 2^(h+1) - 1
7. Minimum height for n nodes = ⌈log2(n+1)⌉ - 1
8. In any non-empty binary tree, leaf nodes (n0) = internal nodes with 2 children (n2) + 1
9. Full Binary Tree: every node has either 0 or 2 children
10. Perfect Binary Tree: all internal nodes have 2 children and all leaves are at the same level
11. Complete Binary Tree: all levels completely filled except possibly the last, filled from left to right
12. Degenerate (Skewed) Binary Tree: each parent has only one child (like a linked list)


Time Complexity of Operations (Array Representation):

- Accessing a node (by index): O(1)
- Insertion at the end: O(1)
- Insertion in between: O(n) (requires shifting elements)
- Deletion of a node: O(n) (shifting needed to maintain structure)
- Traversals (InOrder, PreOrder, PostOrder): O(n)
- Searching: O(n) (linear search, unless it’s a BST stored in array)


Example Tree Built:
          1
        /   \
       2     4
      /       \
     6         8
    /           \
   10            12

*/


#include <stdio.h>
#define MAX 100   // maximum size of tree

int tree[MAX];    // array to store binary tree
int n = 0;        // number of nodes

// insert node into tree
void insert(int value) {
    if (n >= MAX) {
        printf("Tree is full!\n");
        return;
    }
    tree[n++] = value;
}

// Inorder Traversal (Left -> Root -> Right)
void inOrder(int index) {
    if (index < n) {
        inOrder(2*index + 1);   // left child
        printf("%d ", tree[index]);
        inOrder(2*index + 2);   // right child
    }
}

// Preorder Traversal (Root -> Left -> Right)
void preOrder(int index) {
    if (index < n) {
        printf("%d ", tree[index]);
        preOrder(2*index + 1);  // left child
        preOrder(2*index + 2);  // right child
    }
}

// Postorder Traversal (Left -> Right -> Root)
void postOrder(int index) {
    if (index < n) {
        postOrder(2*index + 1); // left child
        postOrder(2*index + 2); // right child
        printf("%d ", tree[index]);
    }
}

int main() {
    printf("\n\n");

    // Creating tree
    insert(1);   // root
    insert(2);   // left child of root
    insert(4);   // right child of root
    insert(6);   // left child of node 2
    insert(8);   // right child of node 4
    insert(10);  // left child of node 6
    insert(12);  // right child of node 8

    printf("PreOrder  : ");
    preOrder(0);

    printf("\nInOrder   : ");
    inOrder(0);

    printf("\nPostOrder : ");
    postOrder(0);


    printf("\n\n");
    return 0;
}

/*

========= OUTPUT =========

PreOrder  : 1 2 6 10 4 8 12
InOrder   : 10 6 2 1 4 8 12
PostOrder : 10 6 2 12 8 4 1

*/
