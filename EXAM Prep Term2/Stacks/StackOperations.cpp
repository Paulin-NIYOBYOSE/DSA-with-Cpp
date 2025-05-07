#include <iostream>
#include <stdexcept>

#define MAX 5

class Stack{
  private:
    int array[MAX];
    int top;

  public:
    Stack(){
      top= -1;
    }

    //push
    void push(int x){
      if(top== MAX-1){
        std::cout<<"Stack Overflow"<<std::endl;
        return;
      }
      array[++top] = x;
    }

    //pop
    void pop(){
      if (top == -1){
        std::cout<<"Stack underflow"<<std::endl;
        return;
      }
      array[top--];
    }

    int peek(){
      if(top == -1){
        std::cout<<"Nothing to peek"<<std::endl;
        return -1;
      }
      return array[top];
    }

    bool isEmpty(){
      return top == -1;
    }
    bool isFull(){
      return top == MAX-1;
    }


};
int main() {
  Stack stack; // Create a stack object

  // Perform stack operations
  stack.push(10); // Push 10
  stack.push(20); // Push 20
  stack.push(30); // Push 30
  stack.push(40); // Push 40
  stack.push(50); // Push 50

  // Trying to push when the stack is full
  stack.push(60); // Stack Overflow

  // Peek the top element
  std::cout << "Top element is: " << stack.peek() << std::endl;

  // Pop elements from the stack
  stack.pop(); // Pop 50
  stack.pop(); // Pop 40

  // Peek again after pops
  std::cout << "Top element after pops: " << stack.peek() << std::endl;

  // Checking if the stack is empty
  std::cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

  return 0;
}