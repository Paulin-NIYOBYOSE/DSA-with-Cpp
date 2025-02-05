#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;  // Initialize an empty stack
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;  // Link new node to the top
        top = newNode;  // Update top to the new node
        cout << data << " pushed to stack." << endl;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow! No elements to pop." << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;  // Move top to the next node
        delete temp;  // Free memory of the old top
        return poppedValue;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;  // Return the top element
    }

    bool isEmpty() {
        return top == nullptr;  // Check if stack is empty
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;

    cout << "Stack is empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
}
