//This is a doubly linkedlist : each node points to its previous and next neighbors , allowing bidirectional traversal 
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; //Pointer to the next node
    Node* prev; //Pointer to the previoud node
};

void printList(Node* head){
    while (head!=NULL){
        cout << head->data << "<->";
        head = head -> next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node * head = new Node{1, NULL, NULL};
    Node* second = new Node{2, NULL, head};
    Node* third = new Node {3, NULL, second};

    head-> next = second;
    second->next =third;
    
    printList(head);
    return 0;
}
