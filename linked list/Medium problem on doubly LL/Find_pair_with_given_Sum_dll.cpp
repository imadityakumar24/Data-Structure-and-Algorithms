/*

Find pairs with given sum in doubly linked list


Difficulty: EasyAccuracy: 66.01%Submissions: 88K+Points: 2Average Time: 10m
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.


Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
 

Example 2:

Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPairsWithGivenSum() which takes head node of the doubly linked list and an integer target as input parameter and returns an array of pairs. If there is no such pair return empty array.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
1 <= N <= 105
1 <= target <= 105

Topic Tags
Related Articles

*/








#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


/*
// Brute force solution
// tc = o(n) + o(n^2)
// sc = o(n)
class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<int> arr;
        Node *temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next; 
        }
        
        set <pair<int, int>> combination;
        
        for (int i = 0; i < arr.size(); i++) {
            pair<int, int> values;
            for (int j = i+1; j < arr.size(); j++) {
                if (arr[i] + arr[j] == target) {
                    values = make_pair(arr[i], arr[j]);
                    combination.insert(values);
                }
            }
        }
        
        vector<pair<int, int>> ans(combination.begin(), combination.end());
        return ans;
    }
};
*/


// Brute force solution
// tc = o(2n)
// sc = o(n)
class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    
        vector<int> arr;
        Node *temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next; 
        }
        
        set<pair<int, int>> values;
        int left = 0, right = arr.size()-1;
        
        while (left < right) {
            long long int sum = arr[left] + arr[right];
            if (sum == target) {
                values.insert( {arr[left], arr[right]} );
            }
            if (sum < target) left++;
            else right--;
        }
        
        vector<pair<int, int>> ans(values.begin(), values.end());
        return ans;
        
    }
};


