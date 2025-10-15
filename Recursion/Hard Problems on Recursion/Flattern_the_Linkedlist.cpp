
/*

Flattening a Linked List

Difficulty: MediumAccuracy: 51.53%Submissions: 197K+Points: 4Average Time: 40m
Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom points to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and → represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 10 is pointing to 20 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 30 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.
Constraints:
0 ≤ n ≤ 100
1 ≤ number of nodes in sub-linked list(mi) ≤ 50
1 ≤ node->data ≤ 104

Expected Complexities
Company Tags
PaytmFlipkartAmazonMicrosoftSnapdeal24*7 Innovation LabsPayuVisaGoldman SachsQualcommDrishti-Soft

*/



#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


/*
// using brute force method 
// tc = o(m * n) + o(m * n) + o(n)
//sc = o(m * n) + o(m * n) + o(n)
class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        vector <int> arr;
        Node *nextTemp = root;
        
        while (nextTemp != nullptr) {
            Node *depthTemp = nextTemp;
            while (depthTemp != nullptr) {
                arr.push_back(depthTemp->data);
                depthTemp = depthTemp->bottom;
            }
            nextTemp = nextTemp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        Node *head = nullptr;
        if (arr.size() == 0) return nullptr;
        else {
            head = new Node(arr[0]);
            Node *temp = head;
            for (int i = 1; i < arr.size(); i++) {
                Node *newNode = new Node(arr[i]);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
        }
        
        return head;
    }
};

*/



// optimal solution using recursion
// understand time complexity more on paper 
// TC = O(N*N*M)    
// SC : Auziliary Space = O(1) and O(N*M) – because of the recursion.
class Solution {
private:
    Node* mergeSortedList(Node *head1, Node *head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        
        Node *result;
        
        if (head1->data < head2->data) {
            result = head1;
            result->bottom = mergeSortedList(head1->bottom, head2);
        }
        else {
            result = head2;
            result->bottom = mergeSortedList(head1, head2->bottom);
        }
        
        return result;
    }
// private section ends here    
public:
    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL)
        return root;    
        
        Node *temp = flatten(root->next);
        return mergeSortedList(root, temp);
    }
};











