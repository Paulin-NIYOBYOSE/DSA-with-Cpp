#include <iostream>
using namespace std;

// Definition of Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Definition of LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Display all elements using a loop
    void display() {
        Node* current = head;
        while (current != nullptr) { // Traverse until the end of the list
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl; // Print a newline after displaying all elements
    }

    // Display all elements using recursion
    void displayRecursive(Node* current) {
        if (current == nullptr) {
            cout << endl;
            return;
        }
        cout << current->data << " ";
        displayRecursive(current->next);
    }

    // Search for an element
    Node* search(int value) {
        Node* current = head;
        while (current != nullptr) {// Traverse until the end of the list
            if (current->data == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    // Count the number of elements using a loop
    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) { // Traverse until the end of the list
            count++; // Increment the count for each node
            current = current->next;
        }
        return count;
    }

    // Count the number of elements using recursion
    int countRecursive(Node* current) {
        if (current == nullptr) return 0;
        return 1 + countRecursive(current->next);// Count current node then go to the next
    }

    // Delete the first element
    void deleteFirst() {
        if (head == nullptr) return; // If the list is empty, do nothing
        Node* temp = head;// Store the current head in a temporary pointer
        head = head->next;// Move the head to the next node
        delete temp;
    }

    // Delete the last element
    void deleteLast() {
        if (head == nullptr) return;  // If the list is empty, do nothing
        if (head->next == nullptr) { // If the list has only one node
            delete head;  // Delete the single node
            head = nullptr; // Set the head to nullptr
            return;
        }
        Node* current = head; // Start from the head of the list
        while (current->next->next != nullptr) { // Traverse to the second-to-last node
            current = current->next; // Move to the next node
        }
        delete current->next; //Delete the node
        current->next = nullptr; // Set the next pointer of the second-to-last node to nullptr
    }

    // Delete an element at a given position
    void deleteAt(int position) {
        if (position < 1 || head == nullptr) return;

        if (position == 1) {
            deleteFirst();
            return;
        }

        Node* current = head;
        for (int i = 1; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) return;

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Insert an element at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert an element at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Insert an element at a given position
    void insertAtPosition(int value, int position) {
        if (position < 1) return;

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;

        for (int i = 1; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) return;

        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to get the head for recursive functions
    Node* getHead() {
        return head;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "List: ";
    list.display();

    cout << "Recursive Display: ";
    list.displayRecursive(list.getHead());

    cout << "Count: " << list.count() << endl;

    cout << "Count (Recursive): " << list.countRecursive(list.getHead()) << endl;

    cout << "Search for 20: ";
    Node* found = list.search(20);
    if (found) cout << "Found " << found->data << endl;
    else cout << "Not Found" << endl;

    list.insertAtBeginning(5);
    cout << "After inserting 5 at beginning: ";
    list.display();

    list.insertAtPosition(25, 3);
    cout << "After inserting 25 at position 3: ";
    list.display();

    list.deleteFirst();
    cout << "After deleting first element: ";
    list.display();

    list.deleteLast();
    cout << "After deleting last element: ";
    list.display();

    list.deleteAt(2);
    cout << "After deleting element at position 2: ";
    list.display();
    
    return 0;
}



