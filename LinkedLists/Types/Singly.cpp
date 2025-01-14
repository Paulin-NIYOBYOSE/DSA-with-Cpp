#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; //Pointer to the next node
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout <<"NULL" <<endl;
}

int main (){
    Node* head = new Node{1, NULL};
    Node* second = new Node{2, NULL};
    Node* third = new Node{3, NULL};

    head->next = second; // Linking nodes
    second->next = third;

    printList(head);
    return 0;

}