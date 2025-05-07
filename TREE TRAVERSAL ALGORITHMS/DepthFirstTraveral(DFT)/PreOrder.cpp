void preOrderTraversal(TreeNode* root){
  if (root == nullptr) return;
  std::cout<<root->data<<""; //visit root
  preOrderTraversal(root->left);//Visit left subtree
  preOrderTraversal(root->right);//visit right subtree
}
