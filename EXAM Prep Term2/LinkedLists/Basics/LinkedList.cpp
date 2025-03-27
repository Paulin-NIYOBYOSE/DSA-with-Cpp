#include <iostream>;
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int data) :data(data),next(NULL){}
};

class LinkedList{
  private:
    Node * head;

  public:
    LinkedList() : head(NULL){}

    // 1.Inserting at the beginning
    void insertAtBeginning(int data){
      Node * newNode = new Node(data);
      newNode->next = head;
      head = newNode;
    }

    //2.Inserting at the end
    void insertAtEnd(int data){
      Node * newNode = new Node(data);
      if (head == NULL){
        head = newNode;
      }else{
        Node * temp = head;
        while(temp->next != NULL){
          temp = temp->next;
        }
        temp->next = newNode;
      }
    }

    //3.Deleting from the beginning
    void deleteAtBeginning(){
      Node * temp = head;
      head = head->next;
      delete temp;
    }

    //deleting from the end
    void deleteAtEnd(){
      if (head == NULL){return;}
      if (head->next == NULL){
        delete head;
        head = NULL;
        return;
      }
      Node * temp = head;
      while(temp->next != NULL && temp->next->next != NULL){
        temp = temp->next;
      }
      delete temp->next;
      temp->next = NULL;
    }

    //5. Traversing
    void traverse(){
      Node * temp = head;
      while(temp != NULL){
        cout << temp->data << "";
        temp = temp->next;
      }
      cout<<"NULL" << endl;
    }

    //6. Reversing the list
    void reverse(){
      Node * temp = head;
      Node * current = temp->next;
      Node * next = NULL;

      while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }

    }
};
int main() {
  LinkedList list;

  list.insertAtBeginning(10);  // List: 10
  list.insertAtEnd(20);        // List: 10 -> 20
  list.insertAtEnd(30);        // List: 10 -> 20 -> 30
  list.insertAtBeginning(5);   // List: 5 -> 10 -> 20 -> 30

  cout << "Original List: ";
  list.traverse(); // Output: 5 -> 10 -> 20 -> 30 -> NULL

  list.reverse();
  cout << "Reversed List: ";
  list.traverse(); // Output: 30 -> 20 -> 10 -> 5 -> NULL

  list.deleteAtBeginning(); // List: 20 -> 10 -> 5
  cout << "After Deletion from Beginning: ";
  list.traverse(); // Output: 20 -> 10 -> 5 -> NULL

  list.deleteAtEnd(); // List: 20 -> 10
  cout << "After Deletion from End: ";
  list.traverse(); // Output: 20 -> 10 -> NULL

  return 0;
}
