#include <iostream>
#include <stack>
#include <string>

std::string reverseString(const std::string& input) {
  std::stack<char> stack;

  // Push all characters of the string onto the stack
  for (char c : input) {
    stack.push(c);
  }

  // Pop characters from the stack to form the reversed string
  std::string reversed;
  while (!stack.empty()) {
    reversed += stack.top();
    stack.pop();
  }

  return reversed;
}

int main() {
  std::string input = "hello";
  std::string result = reverseString(input);
  std::cout << "Reversed String: " << result << std::endl;

  return 0;
}
