#include <iostream>
#include "BinaryTreeNodeStructure.h"
using namespace std;

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {
  }
};