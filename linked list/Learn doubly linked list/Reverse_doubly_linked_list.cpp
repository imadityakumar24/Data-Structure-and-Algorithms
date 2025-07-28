/*

Reverse a Doubly Linked List


Difficulty: EasyAccuracy: 70.38%Submissions: 185K+Points: 2Average Time: 15m
Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

Examples:

Input: LinkedList: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3

Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104

Company Tags
D-E-ShawAdobe


*/





#include <bits/stdc++.h>
using namespace std;

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == nullptr) 
            return head;
        else  {
            vector <int> dllElements;
            DLLNode* temp = head;
            
            while (temp != nullptr) {
                dllElements.push_back(temp->data);
                temp = temp->next;
            }
            
            // reverse(dllElements.begin(), dllElements.end());
            int n = dllElements.size() - 1;
            
            DLLNode* newTemp = head;
            int i = n;
            while (newTemp != nullptr) {
                newTemp->data = dllElements[i];
                i--;
                newTemp = newTemp->next;
            }
        }  
        
        return head;
    }
};


