#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;

  Node(int value){
    data = value;
    next = nullptr;
  }

};

class Queue{
  private:
    Node* front;
    Node* rear;

  public:
    Queue(){
      front = nullptr;
      rear = nullptr;
    }
    void enqueue(int value){
      Node* newNode = new Node(value);
      if(rear == nullptr){
        front= rear = newNode;
      }else{
        rear->next= newNode;
        rear = newNode;
      }
      cout<<"Enqueued value: "<<value<<endl;
    }

    void dequeue(){
      if (front == nullptr){
        cout<<"Queue is empty"<<endl;
        return;
      }
      Node* temp = front;
      front = front->next;
      if(front == nullptr){
        rear = nullptr;
      }
      cout<<"Dequeued value: "<<temp->data<<endl;
      delete temp;
    }

    int peek(){
      if (front == nullptr){
        cout<<"Queue is empty"<<endl;
        return -1;
      }
      return front->data;
    }

    bool isEmpty(){
      return front == nullptr;

    }
};
