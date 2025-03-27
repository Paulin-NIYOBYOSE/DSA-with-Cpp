#include <iostream>

#define MAX 5

class Queue{
  private:
    int arr[MAX];
    int front;
    int rear;

  public:
    Queue(){
      front = -1;
      rear = -1;
    };

    void enqueue(int value){
      if (rear == MAX-1){
        std::cout<<"Queue is full"<<std::endl;
        return;
      }
      arr[++rear] = value;
    }

    void dequeue(){
      if(rear == -1){
        std::cout<<"Nothing to dequeue"<<std::endl;
        return;
      }
      arr[front++];
    }

    int peek(){
      if(rear == -1){
        std::cout<<"Nothing to peek"<<std::endl;
        return -1;
      }
      return arr[front];
    }

    bool isEmpty(){
      return front == -1;
    }
    bool isFull(){
      return rear == MAX-1;
    }



};
