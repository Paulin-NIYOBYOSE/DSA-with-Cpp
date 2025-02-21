#include <iostream>
#include <queue>  // Include queue header
using namespace std;

int main() {
    queue<int> q;  // Declare a queue of integers

    // Enqueue (Push elements into the queue)
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;  // 10
    cout << "Back element: " << q.back() << endl;    // 30

    // Dequeue (Remove elements from the front)
    q.pop();
    cout << "Front after pop: " << q.front() << endl;  // 20

    // Queue size
    cout << "Queue size: " << q.size() << endl;  // 2

    // Check if queue is empty
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
