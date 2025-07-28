/*

25. Reverse Nodes in k-Group
Solved
Hard
Topics
premium lock icon
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?



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



// brute force solution
// tc = o(n^2) + o(n)
// sc =  o(n)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector <int> finalArr;
        vector <int> arr;
        ListNode* temp = head;

        while (temp != NULL) {
            arr.push_back(temp->val);
            if (arr.size() == k) {
                int n = arr.size();
                for (int i = n-1; i >= 0; i--) {
                    finalArr.push_back(arr[i]);
                }
                // Clear all elements
                arr.clear();
                // Free unused memory
                arr.shrink_to_fit();
            }
            temp = temp->next;
        }
        // if elements are still left
        if (arr.size() >= 0) {
            int n = arr.size();
            for (int i = 0; i < n; i++) {
                finalArr.push_back(arr[i]);
            }
        }

        int i = 0;
        ListNode* newTemp = head;
        while (newTemp != nullptr) {
            newTemp->val = finalArr[i];
            i++;
            newTemp = newTemp->next;
        }
        
        return head;
    }
};



