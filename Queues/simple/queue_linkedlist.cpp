#include <iostream>
using namespace std;
//Creation od node
struct Node {
    int data;
    Node* next;
    Node(int value) { data = value; next = nullptr; } 
};

class Queue {
private:
    Node *front, *rear; //initialize node with front and rear pointers

public:
    Queue() { front = rear = nullptr; } /// Start with an empty queue

    bool isEmpty (){
        return front == nullptr;
    }
    
    //Adding an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value); //create new node with the value to insert to the queue
        if (rear == nullptr) { front = rear = newNode; return; } //If the queue is empty, set the first element to the nodew we are inserting
        rear->next = newNode; //Set top's element next to the new node we are inserting
        rear = newNode; //Update the rear to make it the New node
    }
//Removing the top element 
    void dequeue() {
        if (front == nullptr) { cout << "Queue Underflow!\n"; return; } //Check if the queue is empty, if is you can see what the program does, hhhhh
        Node* temp = front; 
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() {
        if(isEmpty()){
        cout << "Nothing to return because the queue is empty";
        }
        return front->data;
}

    void display() {
        if (!front) { cout << "Queue is empty!\n"; return; }
        Node* temp = front;
        while (temp!= nullptr){ 
           cout << temp->data << "";
           temp = temp->next;
        }
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
    q.isEmpty();
    q.peek();

}
