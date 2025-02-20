#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of queue

class Queue {
private:
    int arr[SIZE];  // Array for queue storage
    int front, rear;  // Front and rear pointers

public:
    Queue() { front = rear = -1; }  // Constructor: Queue is empty

    // Enqueue function to add an element
    void enqueue(int value) {
        if (rear == SIZE - 1) {  // Check if queue is full
            cout << "Queue Overflow! Can't enqueue " << value << endl;
            return;
        }
        if (front == -1) front = 0;  // First element condition
        arr[++rear] = value;  // Insert at rear
    }

    // Dequeue function to remove an element from front
    void dequeue() {
        if (front == -1 || front > rear) {  // Check if queue is empty
            cout << "Queue Underflow! Nothing to dequeue.\n";
            return;
        }
        front++;  // Move front forward
    }

    // Function to get the front element
    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];  // Return front element
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Function to display the queue elements
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();   // Output: Queue elements: 10 20 30
    cout << "Front element: " << q.peek() << endl; // Output: 10
    q.dequeue();
    q.display();   // Output: Queue elements: 20 30
}
