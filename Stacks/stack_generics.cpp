#include <iostream>
using namespace std;

// Template class for Stack
template <typename T>  // T is the placeholder for any data type
class Stack {
private:
    T* arr;        // Dynamic array to store stack elements
    int top;       // Index for the top element
    int capacity;  // Capacity of the stack

public:
    // Constructor to initialize stack with a given capacity
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];  // Allocate memory dynamically
        top = -1;  // Stack is empty initially
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;  // Free the memory when the stack is destroyed
    }

    // Function to add an element to the stack
    void push(T value) {
        if (top == capacity - 1) {  // Check if stack is full
            cout << "Stack Overflow! Can't push " << value << endl;
            return;
        }
        arr[++top] = value;  // Add element and move top pointer
    }

    // Function to remove an element from the stack
    void pop() {
        if (top == -1) {  // Check if stack is empty
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        top--;  // Move top pointer to remove the element
    }

    // Function to get the top element without removing it
    T peek() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return T();  // Return default value of T (e.g., 0 for int, "" for string)
        }
        return arr[top];  // Return top element
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

// Main function to test generic stack
int main() {
    // Stack of integers
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();   // Output: Stack elements: 30 20 10
    cout << "Top element: " << intStack.peek() << endl;  // Output: 30
    intStack.pop();
    intStack.display();   // Output: Stack elements: 20 10

    // Stack of floats
    Stack<float> floatStack(5);
    floatStack.push(10.5);
    floatStack.push(20.3);
    floatStack.display();   // Output: Stack elements: 20.3 10.5
    cout << "Top element: " << floatStack.peek() << endl;  // Output: 20.3

    // Stack of strings
    Stack<string> stringStack(5);
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.display();   // Output: Stack elements: World Hello
    cout << "Top element: " << stringStack.peek() << endl;  // Output: World
}
