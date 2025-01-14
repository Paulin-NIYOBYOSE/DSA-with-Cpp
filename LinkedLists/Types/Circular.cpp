// The list forms a loop. Traversal continues indefinitely if not stopped manually.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void printList(Node* head){
    if (head == NULL) return;
    Node* temp = head;
    do{
        cout << temp->data <<" -> ";
        temp = temp->next;
    }while(temp != head);
    cout << "(back to head)" << endl;
}

int main(){
    Node* head = new Node{1, NULL};
    Node* second = new Node{2, NULL};
    Node* third = new Node{3, NULL};

    head -> next = second;
    second -> next = third;
    third -> next = head; //Circular link
    printList(head);
    return 0;
}