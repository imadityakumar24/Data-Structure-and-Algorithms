/*


Code


Testcase
Test Result
Test Result
206. Reverse Linked List
Solved
Easy
Topics
premium lock icon
Companies
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?


Seen this question in a real interview before?
1/5
Yes
No
Accepted
5,386,935/6.8M
Acceptance Rate
79.3%

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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // stack <int> llElements;
        // ListNode* temp = head;
        // while (temp != nullptr) {
        //     llElements.push(temp->val);
        //     temp = temp->next;
        // }
        // ListNode* newtemp = head;
        // while (!llElements.empty()) {
        //     newtemp->val = llElements.top();
        //     llElements.pop();
        //     newtemp = newtemp->next;
        // }

        // return head;

        ListNode* temp = head;
        ListNode* previous = nullptr;

        while (temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = previous;
            previous = temp;
            temp = front;
        }
        
        return previous;
    }
};
*/

// recursive solution
// tc = o(n)
// sc = o(1)
class Solution {
private:
    void reverseLL(ListNode* head, ListNode*& newHead) {
        if (head == nullptr || head->next == NULL) {
            newHead = head;
            return;
        }

        reverseLL(head->next, newHead);
        // Reverse the link
        head->next->next = head;
        head->next = nullptr;
    }    
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* newHead = nullptr;
        reverseLL(head, newHead);
        return newHead;
    }
};

