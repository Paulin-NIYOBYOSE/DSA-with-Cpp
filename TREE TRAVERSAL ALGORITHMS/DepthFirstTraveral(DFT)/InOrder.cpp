void InorderTraversal(TreeNode* root){
  if (root == nullptr){
    return;
  }
  InorderTraversal(root->left);// visit left sub tree
  std::cout<<root-> data<<""; //Visit Root
  InorderTraversal(root->right); // Visit right subtree
}