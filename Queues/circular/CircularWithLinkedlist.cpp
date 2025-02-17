#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueueLL {
private:
    Node* front;
    Node* rear;

public:
    CircularQueueLL() : front(nullptr), rear(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        if (!front) {
            front = rear = newNode;
            rear->next = front; // Circular link
            return;
        }
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Circular link
    }

    void pop() {
        if (!front) {
            std::cout << "Queue is empty!\n";
            return;
        }
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    int Front() {
        if (!front) {
            std::cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    CircularQueueLL q;
    q.push(10);
    q.push(20);
    q.pop();
    std::cout << "Front: " << q.Front() << std::endl;
    return 0;
}
