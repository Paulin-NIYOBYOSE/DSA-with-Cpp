#include<iostream>
using namespace std;

class Stack{
   int *arr;
   int nextIndex;
   int capacity;

public:
   Stack() {
      capacity = 4;
      arr = new int[capacity];
      nextIndex = 0;
   }

   Stack(int cap) {
      capacity = cap;
      arr = new int[capacity];
      nextIndex = 0;
   }

   int size() { return nextIndex; }

   bool isEmpty() {
      return nextIndex == 0;
   }

   void push(int ele) {
      if (nextIndex == capacity) {
         cout << "Stack full" << endl;
         return;
      }
      arr[nextIndex] = ele;
      nextIndex++;
      cout << "Pushed: " << ele << endl;  // Added for clarity
   }

   void pop() {
      if (isEmpty()) {
         cout << "Stack empty" << endl;
         return;
      }
      nextIndex--;
   }

   int top() {
      if (isEmpty()) {
         cout << "Stack empty" << endl;
         return 0;
      }
      return arr[nextIndex - 1];
   }
};

int main() {
   Stack s(4);
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50); // This will print "Stack full"

   cout << s.top() << endl;  // Should print 40
   s.pop();
   cout << s.top() << endl;  // Should print 30
   s.pop();
   cout << s.top() << endl;  // Should print 20
   s.pop();

   cout << s.size() << endl;  // Should print 1 (Only 10 left)
   cout << s.isEmpty() << endl;  // Should print 0 (not empty)

   Stack s2(10);
   for (int i = 1; i <= 10; i++) {
      s2.push(i);
   }

   // Print content of stack
   while (!s2.isEmpty()) {
      cout << s2.top() << endl;
      s2.pop();
   }

   cout << s2.size() << endl;  // Should print 0 (stack is empty)
   return 0;
}


