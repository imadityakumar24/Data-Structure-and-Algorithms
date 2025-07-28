/*

328. Odd Even Linked List
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106

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
// tc = nearly o(3n)
// sc = o(n) 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector <int> odd;
        vector <int> even;
        ListNode* temp = head;
        int index = 1;

        while (temp != nullptr) {
            if (index % 2 == 0) {       // means even index
                even.push_back(temp->val);
                index++;
            }   
            else {      // means odd index
                odd.push_back(temp->val);
                index++;
            }
                  
            temp = temp->next;     
        }

        for (int i = 0; i < even.size(); i++) {
            odd.push_back(even[i]);
        }

        int i = 0;
        temp = head;
        while (temp != nullptr) {
            temp->val = odd[i];
            i++;
            temp = temp->next;
        }
        
        return head;
    }
};
*/


// optimal solution
// tc = nearly o(n)
// sc = o(1) 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenHead;   // meging odd and even nodes 

        return head;
    }
};

