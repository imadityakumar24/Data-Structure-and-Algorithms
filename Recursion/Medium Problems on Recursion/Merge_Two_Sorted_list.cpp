/*

21. Merge Two Sorted Lists
Solved
Easy
Topics
premium lock icon
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
5,656,335/8.4M
Acceptance Rate
67.4%
Topics
Linked List
Recursion

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
 

/*
class Solution {
private:
    void insertAtEnd(ListNode* &head, int value) {
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> llElements;
        ListNode* temp1 = list1;
        while (temp1 != nullptr) {
            llElements.push_back(temp1->val);
            temp1 = temp1->next;
        }

        ListNode* temp2 = list2;
        while (temp2 != nullptr) {
            llElements.push_back(temp2->val);
            temp2 = temp2->next;
        }
        sort(llElements.begin(), llElements.end());
        ListNode* head = nullptr;
        for (int i = 0; i < llElements.size(); i++) {
            insertAtEnd(head, llElements[i]);
        }

        return head;
    }
};
*/

 
class Solution {   
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        

        ListNode* result = nullptr;

        if (list1->val < list2->val) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        }
        else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
};