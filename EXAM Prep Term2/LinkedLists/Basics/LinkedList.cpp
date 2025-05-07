#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList() {
    head = nullptr;
  }

  // 1. Inserting at the beginning
  void insertAtBeginning(int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  // 2. Inserting at the end
  
  void insertAtEnd(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
    } else {
      Node *temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  // 3. Inserting at a specific position
  void insertAtPosition(int data, int position) {
    // If inserting at position 1 (beginning)
    if (position == 1) {
      insertAtBeginning(data);
      return;
    }

    Node *newNode = new Node(data);
    Node *temp = head;

    // Traverse the list until the position before the target position
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
      temp = temp->next;
    }
    // If position is more than the number of nodes
    if (temp == nullptr) {
      cout << "Position out of range!" << endl;
      delete newNode;
      return;
    }

    // Insert newNode after temp
    newNode->next = temp->next;
    temp->next = newNode;
  }

  // 4. Deleting from the beginning
  void deleteAtBeginning() {
    if (head == nullptr) return; // List is empty
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  // 5. Deleting from the end
  void deleteAtEnd() {
    if (head == nullptr) return; // List is empty
    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr) {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }

  // 6. Deleting from a specific position
  void deleteAtPosition(int position) {
    // If the list is empty
    if (head == nullptr) {
      cout << "List is empty!" << endl;
      return;
    }

    // If deleting from the beginning (position 1)
    if (position == 1) {
      deleteAtBeginning();
      return;
    }

    Node *temp = head;

    // Traverse the list until the position before the target position
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
      temp = temp->next;
    }

    // If position is more than the number of nodes
    if (temp == nullptr || temp->next == nullptr) {
      cout << "Position out of range!" << endl;
      return;
    }

    // Node temp->next is the node to be deleted
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
  }

  // 7. Traversing the list
  void traverse() {
    Node *temp = head;
    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }

  // 8. Reversing the list
  void reverse() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
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

  list.insertAtPosition(15, 2); // List: 20 -> 15
}