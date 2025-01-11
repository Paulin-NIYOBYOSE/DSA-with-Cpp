#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next; // Pointer to the next node
};

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) { // Use NULL instead of nullptr
        cout << head->data << " -> ";
        head = head->next; // Move to the next node
    }
    cout << "NULL" << endl; // Use NULL instead of nullptr
}

int main() {
    // Create nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Initialize node values and links
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL; // Use NULL instead of nullptr

    // Print the linked list
    printList(head);

    return 0;
}
