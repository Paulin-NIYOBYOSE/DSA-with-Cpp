#include <iostream> // Include the input/output library for using cout and endl
using namespace std;

// Definition of Node class
class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node

    // Constructor to initialize a node with a value and set the next pointer to nullptr
    Node(int value) : data(value), next(nullptr) {}
};

// Definition of LinkedList class
class LinkedList {
private:
    Node* head; // Pointer to the first node of the linked list

public:
    // Constructor to initialize the linked list with an empty head
    LinkedList() : head(nullptr) {}

    // Function to display all elements using a loop
    void display() {
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            cout << current->data << " "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        cout << endl; // Print a newline after displaying all elements
    }

    // Function to display all elements using recursion
    void displayRecursive(Node* current) {
        if (current == nullptr) { // Base case: if current node is null, stop recursion
            cout << endl; // Print a newline after all elements are displayed
            return;
        }
        cout << current->data << " "; // Print the data of the current node
        displayRecursive(current->next); // Recur for the next node
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

    // Function to count the number of elements using a loop
    int count() {
        int count = 0; // Initialize the count to 0
        Node* current = head; // Start from the head of the list
        while (current != nullptr) { // Traverse until the end of the list
            count++; // Increment the count for each node
            current = current->next; // Move to the next node
        }
        return count; // Return the total count
    }

    // Function to count the number of elements using recursion
    int countRecursive(Node* current) {
        if (current == nullptr) return 0; // Base case: if current node is null, return 0
        return 1 + countRecursive(current->next); // Count the current node and recurse for the rest
    }

    // Function to delete the first element of the list
    void deleteFirst() {
        if (head == nullptr) return; // If the list is empty, do nothing
        Node* temp = head; // Store the current head in a temporary pointer
        head = head->next; // Move the head to the next node
        delete temp; // Delete the old head node
    }

    // Function to delete the last element of the list
    void deleteLast() {
        if (head == nullptr) return; // If the list is empty, do nothing
        if (head->next == nullptr) { // If the list has only one node
            delete head; // Delete the single node
            head = nullptr; // Set the head to nullptr
            return;
        }
        Node* current = head; // Start from the head of the list
        while (current->next->next != nullptr) { // Traverse to the second-to-last node
            current = current->next; // Move to the next node
        }
        delete current->next; // Delete the last node
        current->next = nullptr; // Set the next pointer of the second-to-last node to nullptr
    }

    // Function to delete an element at a given position
    void deleteAt(int position) {
        if (position < 1 || head == nullptr) return; // If position is invalid or list is empty, do nothing

        if (position == 1) { // If deleting the first element
            deleteFirst(); // Use deleteFirst() function
            return;
        }

        Node* current = head; // Start from the head of the list
        for (int i = 1; current != nullptr && i < position - 1; i++) {
            current = current->next; // Move to the node before the target position
        }

        if (current == nullptr || current->next == nullptr) return; // If position is out of bounds, do nothing

        Node* temp = current->next; // Store the target node in a temporary pointer
        current->next = current->next->next; // Link the previous node to the next node
        delete temp; // Delete the target node
    }

    // Function to insert an element at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        newNode->next = head; // Set the next of the new node to the current head
        head = newNode; // Update the head to the new node
    }

    // Function to insert an element at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value); // Create a new node with the given value
        if (head == nullptr) { // If the list is empty
            head = newNode; // Set the new node as the head
            return;
        }
        Node* current = head; // Start from the head of the list
        while (current->next != nullptr) { // Traverse to the last node
            current = current->next; // Move to the next node
        }
        current->next = newNode; // Set the next of the last node to the new node
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
        current->next = newNode; // Link the previous node to the new node
    }

    // Function to get the head of the list for recursive functions
    Node* getHead() {
        return head; // Return the head pointer
    }
};

int main() {
    LinkedList list; // Create an instance of LinkedList

    list.insertAtEnd(10); // Insert 10 at the end of the list
    list.insertAtEnd(20); // Insert 20 at the end of the list
    list.insertAtEnd(30); // Insert 30 at the end of the list

    cout << "List: ";
    list.display(); // Display the list using a loop

    cout << "Recursive Display: ";
    list.displayRecursive(list.getHead()); // Display the list using recursion

    cout << "Count: " << list.count() << endl; // Count elements using a loop

    cout << "Count (Recursive): " << list.countRecursive(list.getHead()) << endl; // Count elements using recursion

    cout << "Search for 20: ";
    Node* found = list.search(20); // Search for the value 20
    if (found) cout << "Found " << found->data << endl;
    else cout << "Not Found" << endl;

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
