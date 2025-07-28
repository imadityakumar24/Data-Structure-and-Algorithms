
#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Insert node at the end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(Node*& head, int key) {
    Node* temp = head;

    // If head node itself holds the key
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }

    // Search for the node to be deleted
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    // Node not found
    if (temp == nullptr) return;

    // Adjust the pointers
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
}

// Display the list from start to end
void display(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Doubly Linked List: ";
    display(head);

    // Delete a node
    deleteNode(head, 20);
    cout << "After deleting 20: ";
    display(head);

    return 0;
}
