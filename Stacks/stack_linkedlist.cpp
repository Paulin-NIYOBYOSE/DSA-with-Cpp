#include <iostream>
using namespace std;

// Node structure for the linked list stack
struct Node {
    int data;
    Node* next;
    Node(int value) {  // Constructor to initialize node
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;  // Pointer to the top node

public:
    Stack() { top = nullptr; }  // Constructor: Stack is initially empty

    // Push function to add a new element at the top
    void push(int value) {
        Node* newNode = new Node(value);  // Create new node
        newNode->next = top;  // Link new node to the previous top
        top = newNode;  // Update top pointer
    }

    // Pop function to remove the top element
    void pop() {
        if (top == nullptr) {  // Check if stack is empty
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        Node* temp = top;  // Store current top node
        top = top->next;  // Move top pointer to next node
        delete temp;  // Delete old top node
    }

    // Peek function to check the top element
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;  // Return top element
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the stack elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;  // Move to next node
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();   // Output: Stack elements: 30 20 10
    cout << "Top element: " << s.peek() << endl; // Output: 30
    s.pop();
    s.display();   // Output: Stack elements: 20 10
}
