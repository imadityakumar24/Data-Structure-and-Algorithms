#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Iterative method to reverse a singly linked list
ListNode* reverseListIterative(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  // Store the next node
        curr->next = prev; // Reverse the pointer
        prev = curr;       // Move prev one step forward
        curr = next;       // Move curr one step forward
    }
    return prev; // prev is the new head
}

// Recursive method to reverse a singly linked list
ListNode* reverseListRecursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Base case: empty or single-node list
    }

    ListNode* reversedTail = reverseListRecursive(head->next); // Recursive call

    head->next->next = head; // Reverse the pointer
    head->next = nullptr;    // Set the original next to nullptr

    return reversedTail; // Returns the new head
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample singly linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    // Reverse the list using the iterative method
    ListNode* reversedHeadIterative = reverseListIterative(head);
    std::cout << "Reversed List (Iterative): ";
    printList(reversedHeadIterative);

    // Restore the original list (for demonstration of recursive method)
    head = reverseListIterative(reversedHeadIterative); // Reuse iterative to get original
    std::cout << "Original List (Restored): ";
    printList(head);

    // Reverse the list using the recursive method
    ListNode* reversedHeadRecursive = reverseListRecursive(head);
    std::cout << "Reversed List (Recursive): ";
    printList(reversedHeadRecursive);

    // Clean up memory (important to prevent memory leaks)
    ListNode* current;
    ListNode* next;

    current = reversedHeadRecursive; // Use the final reversed list
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}
