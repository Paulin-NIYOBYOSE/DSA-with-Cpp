#include <iostream>
using namespace std;

#define SIZE 5  // Define maximum size of stack

class Stack {
private:
    int arr[SIZE]; // Array to store stack elements
    int top;  // Variable to track the top of the stack

public:
    Stack() { top = -1; }  // Constructor: Initialize stack as empty

    // Function to push an element onto the stack
    void push(int value) {
        if (top == SIZE - 1) {  // Check if stack is full
            cout << "Stack Overflow! Can't push " << value << endl;
            return;
        }
        arr[++top] = value;  // Increment top and insert element
    }

    // Function to pop (remove) the top element
    void pop() {
        if (top == -1) {  // Check if stack is empty
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        top--;  // Decrement top to remove element
    }

    // Function to get the top element without removing it
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];  // Return the top element
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to display the stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";  // Print stack from top to bottom
        cout << endl;
    }
};

// Main function to test stack
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
