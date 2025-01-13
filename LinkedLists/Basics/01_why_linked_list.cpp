#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;       // Data field
    Node* next;     // Pointer to the next node
};

int main() {
    // Dynamically creating three nodes
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Assigning data and linking the nodes
    head->data = 10;       // Data for first node
    head->next = second;   // Link to the second node

    second->data = 20;     // Data for second node
    second->next = third;  // Link to the third node

    third->data = 30;      // Data for third node
    third->next = nullptr; // End of the list

    // Display the linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Free the memory
    delete head;
    delete second;
    delete third;

    return 0;
}
