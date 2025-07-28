/*

61. Rotate List
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

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
// tc = o(3n) 0r o(n) because in big-o we ignore the constants
// sc = o(n)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;  // Edge case: empty list or no rotation
        vector <int> llElements;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            llElements.push_back(temp->val);
            temp = temp->next;
        }

        int arrSize = llElements.size();
        k = k % arrSize;  // Avoid unnecessary full rotations
        if (k == 0) return head;  // No change if k is a multiple of list size
        int start = arrSize - k;

        vector <int> rotatedArr;
        for (int i = start; i < arrSize; i++) {
            rotatedArr.push_back(llElements[i]);
        }
        for (int i = 0; i < start; i++) {
            rotatedArr.push_back(llElements[i]);
        }

        ListNode* newTemp = head;
        for (int i = 0; i < rotatedArr.size(); i++) {
            newTemp->val = rotatedArr[i];
            newTemp = newTemp->next;
        }

        return head;
    }
};
*/


// optimal solution
// tc = o(n)
// sc = o(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;  // Edge case: empty list or no rotation
        ListNode* temp = head;
        int count = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            count++;
        }

        int arrSize = count;
        k = k % arrSize;  // Avoid unnecessary full rotations
        if (k == 0) return head;  // No change if k is a multiple of list size
        int start = arrSize - k - 1;

        temp->next = head;
        ListNode* newTemp = head;
        for (int i = 0; i < start; i++) {
            newTemp = newTemp->next;
        }

        ListNode* newHead = newTemp->next;
        newTemp->next = nullptr;

       return newHead;
    }
};