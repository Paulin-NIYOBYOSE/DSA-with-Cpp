#include <iostream> // Including the input-output stream library
#define SIZE 5 // Defining the size of the queue

class SimpleQueue { // Class definition for SimpleQueue
private:
    int arr[SIZE], front, rear; // Declaring an array of fixed size, and two integer variables for front and rear pointers

public:
    SimpleQueue() : front(0), rear(-1) {} // Constructor to initialize the front and rear pointers

    void push(int value) { // Function to insert an element into the queue
        if (rear == SIZE - 1) { // If the queue is full
            std::cout << "Queue Overflow!\n"; // Displaying overflow message
            return; // Exiting the function if the queue is full
        }
        arr[++rear] = value; // Increment rear pointer and assign the value to the queue
    }

    void pop() { // Function to remove an element from the front of the queue
        if (front > rear) { // If the queue is empty (front pointer is beyond the rear)
            std::cout << "Queue Underflow!\n"; // Displaying underflow message
            return; // Exiting the function if the queue is empty
        }
        front++; // Increment the front pointer to remove the front element
    }

    int Front() { // Function to get the front element of the queue
        if (front > rear) { // If the queue is empty
            std::cout << "Queue is empty!\n"; // Displaying empty message
            return -1; // Returning -1 as an indicator of empty queue
        }
        return arr[front]; // Returning the front element
    }

    bool isEmpty() { // Function to check if the queue is empty
        return front > rear; // If front is ahead of rear, the queue is empty
    }
};

int main() {
    SimpleQueue q; // Creating an instance of SimpleQueue
    q.push(10); // Adding 10 to the queue
    q.push(20); // Adding 20 to the queue
    std::cout << "Front: " << q.Front() << std::endl; // Displaying the front element, which should be 10
    q.pop(); // Removing the front element (10)
    std::cout << "Front after pop: " << q.Front() << std::endl; // Displaying the new front element, which should be 20
    return 0; // Ending the program
}
