#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Dequeue elements
    std::cout << "Front element: " << q.front() << std::endl;
    q.pop(); // Removes 10

    std::cout << "Front after pop: " << q.front() << std::endl;

    return 0;
}
