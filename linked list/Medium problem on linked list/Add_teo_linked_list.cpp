/*

2. Add Two Numbers
Solved
Medium
Topics
premium lock icon
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

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
// but it is mot working for all the test cases 
class Solution {
private:
    vector <int> findDigits(int total) {
        vector <int> llValues;
        if (total == 0) {
            llValues.push_back(0);
            return llValues;
        }
        
        long long int copy, dublicate, number = 0;
        copy = dublicate = total;
            
        while (copy != 0) {
            number = copy;
            number = number % 10;
            llValues.push_back(number);
            copy = copy / 10;
        }

        reverse(llValues.begin(), llValues.end());
        return llValues;
    }   
private:
    long long int findValue(ListNode*& head) {
        ListNode* temp = head;
        if (head == nullptr) return 0;
        long long int total = 0;
        long long int value = 0;

        while (temp != nullptr) {
            int dt = temp->val;
            value = (value * 10) + dt;
            temp = temp->next;
        }

        return value;
    }

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if (l1 == nullptr && l2 == nullptr) {
        //     int val = 0;
        //     ListNode* newNode = new ListNode(val);
        //     return newNode;
        // }
        long long value1 = findValue(l1);
        long long value2 = findValue(l2);
        long long total = value1 + value2;

        vector <int> nums = findDigits(total);
        reverse(nums.begin(), nums.end());
        ListNode* head = nullptr;

        for (int i = 0; i < nums.size(); i++) {
            insertAtEnd(head, nums[i]);
        }

        return head;
    }
};
*/

// optimal aproach
// tc = o(n)
// sc = 0(n)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL) {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            sum = sum + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }

        if (carry == 1) {
            ListNode* Node = new ListNode(1);
            temp->next = Node;
        }

        ListNode* head = dummyNode->next;
        return head;
    }        
};    