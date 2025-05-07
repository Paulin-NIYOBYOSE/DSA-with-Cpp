#include <queue>

void levelOrderTraversal(TreeNode* root) {
  if (root == nullptr) return;

  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* current = q.front();
    q.pop();

    std::cout << current->data << " ";

    if (current->left != nullptr)
      q.push(current->left);
    if (current->right != nullptr)
      q.push(current->right);
  }
}