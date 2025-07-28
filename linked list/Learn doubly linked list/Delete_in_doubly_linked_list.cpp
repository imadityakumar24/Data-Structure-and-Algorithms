/*

Delete in a Doubly Linked List


Difficulty: EasyAccuracy: 42.98%Submissions: 201K+Points: 2Average Time: 40m
Given a Doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 <--> 3
Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 <--> 2 <--> 9
Explanation:

Constraints:
2 <= size of the linked list <= 106
1 <= x <= size of the linked list 
1 <= node->data <= 104

Expected Complexities
Company Tags
AmazonWalmart

*/



#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// better solution
// tc = o(n)   worst case
// sc = o(1)
class Solution {
private:
    void deleteFromBegining(Node *& head) {
        Node* temp = head;
        head = temp->next;
        if (head != nullptr) 
            head->prev = nullptr;
        delete(temp);
    }
// private section ends here    
public:
    Node* deleteNode(Node* head, int x) {
        if (x < 1 || head == nullptr) return head;
        if (x == 1) {
            deleteFromBegining(head);
            return head;
        }
        else {
            Node* temp = head;
            int i = 1;
            while (i < x && temp != nullptr) {
                temp = temp->next;
                i++;
            }
            
            if (temp == nullptr) return head;
            
            // temp->prev->next = temp->next;
            // temp->next->prev = temp->prev;
            
            // Handle normal case
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
            //  Handle last node case
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            
            delete(temp);
        }
        
        return head;
    }
};


