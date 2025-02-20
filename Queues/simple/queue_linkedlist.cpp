#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) { data = value; next = nullptr; }
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() { front = rear = nullptr; }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { front = rear = newNode; return; }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) { cout << "Queue Underflow!\n"; return; }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() { return front ? front->data : -1; }

    void display() {
        if (!front) { cout << "Queue is empty!\n"; return; }
        Node* temp = front;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
}
