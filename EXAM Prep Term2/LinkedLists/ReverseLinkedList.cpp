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

Node* reverse(Node* head){
  Node* prev = nullptr;;
  Node* curr = head;
  Node* next = nullptr;

  while(curr != nullptr){
    next = curr->next;
    curr->next = prev;
    prev= curr;
    curr = next;
  }

}

void display(Node* head){
  Node* temp = head;
  while(temp != nullptr){
    std::cout<<temp->data<<" ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}
