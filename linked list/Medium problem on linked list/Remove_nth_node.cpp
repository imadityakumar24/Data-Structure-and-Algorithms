/*

19. Remove Nth Node From End of List
Medium
Topics
premium lock icon
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?

*/


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
// brute force solution
// tc = o(2n) + 
// sc = o(n)
class Solution {
private:
    void insert(ListNode*& head, int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }    

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = NULL;
        temp = head;
        vector <int> llValues;

        while (temp != NULL) {
            if (temp->val) != n) 
                llValues.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* newhead = nullptr;
        for (int i = 0; i < llValues.size(); i++) {
            insert(head, llValues[i]);
        }

        return newHead;
    }
};
*/

// better solution in one pass
// tc = o(n)
// sc = o(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        ListNode* temp = NULL;
        temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            if (count == n+1 && temp->next->next != nullptr) {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
 
        return head;
    }
};