#include <iostream> // Including the input-output stream library

class Node { // Defining the Node class for linked list implementation
public:
    int data; // Variable to store the data of the node
    Node* next; // Pointer to the next node in the list

    Node(int val) : data(val), next(nullptr) {} // Constructor to initialize data and set next to null
};

class SimpleQueueLL { // Class definition for SimpleQueueLL using linked list
private:
    Node *front, *rear; // Pointers to the front and rear of the queue

public:
    SimpleQueueLL() : front(nullptr), rear(nullptr) {} // Constructor to initialize both front and rear to null

    void push(int value) { // Function to insert an element into the queue
        Node* newNode = new Node(value); // Creating a new node with the value
        if (!rear) { // If the queue is empty
            front = rear = newNode; // Set both front and rear to the new node
            return;
        }
        rear->next = newNode; // Point the current rear's next to the new node
        rear = newNode; // Move the rear pointer to the new node
    }

    void pop() { // Function to remove an element from the front of the queue
        if (!front) { // If the queue is empty
            std::cout << "Queue Underflow!\n"; // Displaying underflow message
            return;
        }
        Node* temp = front; // Storing the front node in temp
        front = front->next; // Moving the front pointer to the next node
        if (!front) rear = nullptr; // If the queue becomes empty, set rear to null
        delete temp; // Deleting the old front node
    }

    int Front() { // Function to get the front element of the queue
        if (!front) { // If the queue is empty
            std::cout << "Queue is empty!\n"; // Displaying empty message
            return -1; // Returning -1 to indicate empty queue
        }
        return front->data; // Returning the data of the front node
    }
};

int main() {
    SimpleQueueLL q; // Creating an instance of SimpleQueueLL
    q.push(10); // Adding 10 to the queue
    q.push(20); // Adding 20 to the queue
    std::cout << "Front: " << q.Front() << std::endl; // Displaying the front element, which should be 10
    q.pop(); // Removing the front element (10)
    std::cout << "Front after pop: " << q.Front() << std::endl; // Displaying the new front element, which should be 20
    return 0; // Ending the program
}
