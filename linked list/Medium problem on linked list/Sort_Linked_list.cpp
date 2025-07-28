/*

148. Sort List
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

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
// tc = o(2n) + o(nlog)
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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector <int> sortedArr;

        while (temp != nullptr) {
            sortedArr.push_back(temp->val);
            temp = temp->next;
        }

        sort(sortedArr.begin(), sortedArr.end());

        ListNode* newHead = nullptr;
        int n = sortedArr.size();

        for (int i = 0; i < n; i++) {
            insert(newHead, sortedArr[i]);
        }

        return newHead;
    }
};
*/

// better solution
// tc = o(2n)
// sc = o(n)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector <int> sortedArr;

        while (temp != nullptr) {
            sortedArr.push_back(temp->val);
            temp = temp->next;
        }

        sort(sortedArr.begin(), sortedArr.end());

        ListNode* anothertemp = head;
        int i = 0;

        while (anothertemp != nullptr) {
            anothertemp->val = sortedArr[i];
            anothertemp = anothertemp->next;
            i++;
        }

        return head;
    }
};