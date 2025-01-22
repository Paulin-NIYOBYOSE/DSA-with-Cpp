#include <iostream> // Include the input/output library for using cout and endl
using namespace std;

// Definition of Node class for doubly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with a value and set prev and next pointers to nullptr
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Definition of DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head; // Pointer to the first node of the list
    Node* tail; // Pointer to the last node of the list

public:
    // Constructor to initialize the list with an empty head and tail
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to display all elements from head to tail
    void display() {
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            cout << current->data << " "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        cout << endl; // Print a newline after displaying all elements
    }

    // Function to display all elements from tail to head
    void displayReverse() {
        Node* current = tail; // Start from the tail of the list
        while (current != nullptr) { // Traverse until the beginning of the list
            cout << current->data << " "; // Print the data of the current node
            current = current->prev; // Move to the previous node
        }
        cout << endl; // Print a newline after displaying all elements
    }

    // Function to count the number of elements using a loop
    int count() {
        int count = 0; // Initialize count to 0
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            count++; // Increment the count for each node
            current = current->next; // Move to the next node
        }
        return count; // Return the total count
    }

    // Function to search for an element in the list
    Node* search(int value) {
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            if (current->data == value) return current; // If the value is found, return the node
            current = current->next; // Move to the next node
        }
        return nullptr; // Return nullptr if the value is not found
    }

    // Function to insert an element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        if (head == nullptr) { // If the list is empty
            head = tail = newNode; // Set the new node as both head and tail
        } else {
            newNode->next = head; // Link the new node to the current head
            head->prev = newNode; // Link the current head to the new node
            head = newNode; // Update the head to the new node
        }
    }

    // Function to insert an element at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        if (tail == nullptr) { // If the list is empty
            head = tail = newNode; // Set the new node as both head and tail
        } else {
            tail->next = newNode; // Link the current tail to the new node
            newNode->prev = tail; // Link the new node to the current tail
            tail = newNode; // Update the tail to the new node
        }
    }

    // Function to insert an element at a given position
    void insertAtPosition(int value, int position) {
        if (position < 1) return; // If position is invalid, do nothing

        if (position == 1) { // If inserting at the beginning
            insertAtBeginning(value); // Use insertAtBeginning() function
            return;
        }

        Node* newNode = new Node(value); // Create a new node with the given value
        Node* current = head; // Start from the head of the list

        for (int i = 1; current != nullptr && i < position - 1; i++) {
            current = current->next; // Move to the node before the target position
        }

        if (current == nullptr) return; // If position is out of bounds, do nothing

        newNode->next = current->next; // Link the new node to the next node
        if (current->next != nullptr) { // If the next node is not null
            current->next->prev = newNode; // Link the next node to the new node
        }
        newNode->prev = current; // Link the new node to the current node
        current->next = newNode; // Link the current node to the new node

        if (newNode->next == nullptr) { // If the new node is now the last node
            tail = newNode; // Update the tail
        }
    }

    // Function to delete the first element of the list
    void deleteFirst() {
        if (head == nullptr) return; // If the list is empty, do nothing
        Node* temp = head; // Store the current head in a temporary pointer
        if (head == tail) { // If there is only one node
            head = tail = nullptr; // Set both head and tail to nullptr
        } else {
            head = head->next; // Move the head to the next node
            head->prev = nullptr; // Remove the link to the old head
        }
        delete temp; // Delete the old head node
    }

    // Function to delete the last element of the list
    void deleteLast() {
        if (tail == nullptr) return; // If the list is empty, do nothing
        Node* temp = tail; // Store the current tail in a temporary pointer
        if (head == tail) { // If there is only one node
            head = tail = nullptr; // Set both head and tail to nullptr
        } else {
            tail = tail->prev; // Move the tail to the previous node
            tail->next = nullptr; // Remove the link to the old tail
        }
        delete temp; // Delete the old tail node
    }

    // Function to delete an element at a given position
    void deleteAt(int position) {
        if (position < 1 || head == nullptr) return; // If position is invalid or list is empty, do nothing

        if (position == 1) { // If deleting the first element
            deleteFirst(); // Use deleteFirst() function
            return;
        }

        Node* current = head; // Start from the head of the list
        for (int i = 1; current != nullptr && i < position; i++) {
            current = current->next; // Move to the target position
        }

        if (current == nullptr) return; // If position is out of bounds, do nothing

        if (current->next != nullptr) current->next->prev = current->prev; // Link the next node to the previous node
        if (current->prev != nullptr) current->prev->next = current->next; // Link the previous node to the next node

        if (current == head) head = current->next; // Update head if needed
        if (current == tail) tail = current->prev; // Update tail if needed

        delete current; // Delete the target node
    }
};

int main() {
    DoublyLinkedList list; // Create an instance of DoublyLinkedList

    list.insertAtEnd(10); // Insert 10 at the end of the list
    list.insertAtEnd(20); // Insert 20 at the end of the list
    list.insertAtEnd(30); // Insert 30 at the end of the list

    cout << "List: ";
    list.display(); // Display the list from head to tail

    cout << "Reverse List: ";
    list.displayReverse(); // Display the list from tail to head

    cout << "Count: " << list.count() << endl; // Count elements in the list

    list.insertAtBeginning(5); // Insert 5 at the beginning
    cout << "After inserting 5 at beginning: ";
    list.display();

    list.insertAtPosition(25, 3); // Insert 25 at position 3
    cout << "After inserting 25 at position 3: ";
    list.display();

    list.deleteFirst(); // Delete the first element
    cout << "After deleting first element: ";
    list.display();

    list.deleteLast(); // Delete the last element
    cout << "After deleting last element: ";
    list.display();

    list.deleteAt(2); // Delete the element at position 2
    cout << "After deleting element at position 2: ";
    list.display();

    return 0; // End of the program
}
