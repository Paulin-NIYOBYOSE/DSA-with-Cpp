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

class Stack{
    private:
      Node* top;
      public:
        Stack(){
          top = nullptr;
        }

      void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
      }
      void pop(){
        if(top == nullptr){
          cout<<"Stack is empty"<<endl;
          return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
      }
      int peek(){
        if(top == nullptr){
          cout<<"Nothing to peek"<<endl;
          return 0;
        }
        return top->data;
      }

      void display(){
        if(top == nullptr){
          cout<<"Stack is empty"<<endl;
          return;
        }
        Node* temp = top;
        while(temp != nullptr){
          cout<<temp->data<<" ";
        }
        cout<<endl;
      }
};