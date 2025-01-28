#include <iostream> // Include the input/output library for using cout and endl
using namespace std; // Use the standard namespace for convenience

// Node definition for Doubly Linked List
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize a new node
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;     // Pointer to the first node
    Node* tail;     // Pointer to the last node

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        if (head == nullptr) { // Check if the list is empty
            head = tail = newNode; // Set both head and tail to the new node
        } else {
            newNode->next = head; // Link the new node's next to the current head
            head->prev = newNode; // Link the current head's prev to the new node
            head = newNode; // Update head to the new node
        }
    }

    // Function to insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        if (head == nullptr) { // Check if the list is empty
            head = tail = newNode; // Set both head and tail to the new node
        } else {
            newNode->prev = tail; // Link the new node's prev to the current tail
            tail->next = newNode; // Link the current tail's next to the new node
            tail = newNode; // Update tail to the new node
        }
    }

    // Function to insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 1) { // Check if the position is invalid
            cout << "Invalid position" << endl; // Print an error message
            return; // Exit the function
        }

        if (position == 1) { // If the position is the beginning
            insertAtBeginning(value); // Use the insertAtBeginning function
            return; // Exit the function
        }
        
        Node* newNode = new Node(value); // Create a new node with the given value
        Node* current = head; // Start from the head of the list
        for (int i = 1; i < position - 1 && current != nullptr; i++) { // Traverse to the node before the position
            current = current->next; // Move to the next node
        }

        if (current == nullptr) { // Check if the position is out of bounds
            cout << "Position out of bounds" << endl; // Print an error message
            return; // Exit the function
        }

        newNode->next = current->next; // Link the new node's next to the current node's next
        newNode->prev = current; // Link the new node's prev to the current node

        if (current->next != nullptr) { // Check if the new node is not being added at the end
            current->next->prev = newNode; // Link the next node's prev to the new node
        } else {
            tail = newNode; // Update the tail if inserting at the end
        }

        current->next = newNode; // Link the current node's next to the new node
    }

    // Function to delete the first node
    void deleteFirst() {
        if (head == nullptr) { // Check if the list is empty
            cout << "List is empty" << endl; // Print an error message
            return; // Exit the function
        }

        Node* temp = head; // Store the current head in a temporary pointer
        if (head == tail) { // Check if there's only one node in the list
            head = tail = nullptr; // Set both head and tail to nullptr
        } else {
            head = head->next; // Move the head to the next node
            head->prev = nullptr; // Set the new head's prev to nullptr
        }
        delete temp; // Free memory of the deleted node
    }

    // Function to delete the last node
    void deleteLast() {
        if (head == nullptr) { // Check if the list is empty
            cout << "List is empty" << endl; // Print an error message
            return; // Exit the function
        }

        Node* temp = tail; // Store the current tail in a temporary pointer
        if (head == tail) { // Check if there's only one node in the list
            head = tail = nullptr; // Set both head and tail to nullptr
        } else {
            tail = tail->prev; // Move the tail to the previous node
            tail->next = nullptr; // Set the new tail's next to nullptr
        }
        delete temp; // Free memory of the deleted node
    }

    // Function to delete a node at a specific position
    void deleteAtPosition(int position) {
        if (position < 1 || head == nullptr) { // Check if the position is invalid or the list is empty
            cout << "Invalid position or empty list" << endl; // Print an error message
            return; // Exit the function
        }

        if (position == 1) { // If the position is the beginning
            deleteFirst(); // Use the deleteFirst function
            return; // Exit the function
        }

        Node* current = head; // Start from the head of the list
        for (int i = 1; i < position && current != nullptr; i++) { // Traverse to the target position
            current = current->next; // Move to the next node
        }

        if (current == nullptr) { // Check if the position is out of bounds
            cout << "Position out of bounds" << endl; // Print an error message
            return; // Exit the function
        }

        if (current->next != nullptr) { // Check if the node to be deleted is not the last node
            current->next->prev = current->prev; // Link the next node's prev to the current node's prev
        } else {
            tail = current->prev; // Update the tail if deleting the last node
        }

        if (current->prev != nullptr) { // Check if the node to be deleted is not the first node
            current->prev->next = current->next; // Link the previous node's next to the current node's next
        }

        delete current; // Free memory of the deleted node
    }

    // Function to display the list forward
    void displayForward() {
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            cout << current->data << " "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        cout << endl; // Print a newline after displaying all elements
    }

    // Function to display the list backward
    void displayBackward() {
        Node* current = tail; // Start from the tail of the list
        while (current != nullptr) { // Traverse until the beginning of the list
            cout << current->data << ""; // Print the data of the current node
            current = current->prev; // Move to the previous node
        }
        cout << endl; // Print a newline after displaying all elements
    }

    // Function to search for a value in the list
    Node* search(int value) {
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            if (current->data == value) { // Check if the current node's data matches the value
                return current; // Return the current node
            }
            current = current->next; // Move to the next node
        }
        return nullptr; // Return nullptr if the value is not found
    }
};

// Main function
int main() {
    DoublyLinkedList dll; // Create an instance of DoublyLinkedList

    dll.insertAtBeginning(10); // Insert 10 at the beginning
    dll.insertAtBeginning(20); // Insert 20 at the beginning
    dll.insertAtEnd(30); // Insert 30 at the end
    dll.insertAtEnd(40); // Insert 40 at the end
    dll.insertAtPosition(25, 3); // Insert 25 at position 3

    cout << "List Forward: ";
    dll.displayForward(); // Display the list forward

    cout << "List Backward: ";
    dll.displayBackward(); // Display the list backward

    cout << "Deleting first node..." << endl;
    dll.deleteFirst(); // Delete the first node
    dll.displayForward(); // Display the list forward

    cout << "Deleting last node..." << endl;
    dll.deleteLast(); // Delete the last node
    dll.displayForward(); // Display the list forward

    cout << "Deleting node at position 2..." << endl;
    dll.deleteAtPosition(2); // Delete the node at position 2
    dll.displayForward(); // Display the list forward

    cout << "Searching for 30: ";
    Node* found = dll.search(30); // Search for the value 30
    if (found) { // Check if the node was found
        cout << "Found: " << found->data << endl; // Print the found node's data
    } else {
        cout << "Not Found" << endl; // Print not found message
    }

    return 0; // Exit the program
}
