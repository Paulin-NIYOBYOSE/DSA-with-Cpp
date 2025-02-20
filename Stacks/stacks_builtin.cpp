#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;  // Create a stack of integers

    // Push elements onto the stack
    s.push(10);  
    s.push(20);  
    s.push(30);  

    // Display top element
    cout << "Top element: " << s.top() << endl;  // Output: 30

    // Pop the top element
    s.pop();  // Removes 30
    cout << "Top element after pop: " << s.top() << endl;  // Output: 20

    // Check the size of the stack
    cout << "Stack size: " << s.size() << endl;  // Output: 2

    // Check if the stack is empty
    if (s.empty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;  // Output: Stack is not empty!
    }

    // Pop remaining elements
    s.pop();  // Removes 20
    s.pop();  // Removes 10

    // Check if the stack is empty again
    if (s.empty()) {
        cout << "Stack is now empty!" << endl;  // Output: Stack is now empty!
    }

    return 0;
}
