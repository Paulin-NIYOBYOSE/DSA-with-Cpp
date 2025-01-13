#include <iostream>
using namespace std;
//This is how we creaate a node
struct Node {
    int data;       // Holds the value
    Node* next;     // Points to the next node
};
//Adding node at the beginning
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node();  // Create a new node
    newNode->data = value;       // Assign the value
    newNode->next = head;        // Point to the current head
    head = newNode;              // Update the head to the new node
}

// Inserting node at the end
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {  // If the list is empty
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;  // Update the last node's pointer
}

