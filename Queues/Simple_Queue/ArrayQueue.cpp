#include <iostream>

class Queue {
private:
    int arr[5];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == 4) {
            std::cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            std::cout << "Queue is empty\n";
            return;
        }
        front++;
    }

    void display() {
        if (front == -1 || front > rear) {
            std::cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
}
