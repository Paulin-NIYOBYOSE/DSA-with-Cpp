#include <iostream>
#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE], front, rear, count;

public:
    CircularQueue() : front(0), rear(-1), count(0) {}

    void push(int value) {
        if (count == SIZE) {
            std::cout << "Queue is full!\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
    }

    void pop() {
        if (count == 0) {
            std::cout << "Queue is empty!\n";
            return;
        }
        front = (front + 1) % SIZE;
        count--;
    }

    int Front() {
        if (count == 0) {
            std::cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue q;
    q.push(10);
    q.push(20);
    q.pop();
    std::cout << "Front: " << q.Front() << std::endl;
    return 0;
}
