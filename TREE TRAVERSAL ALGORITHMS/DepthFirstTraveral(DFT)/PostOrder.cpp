void postOrderTraversal(TreeNode* root){
  if (root == nullptr){
    return;
  }
  postOrderTraversal(root->left); //Visit left subtree
  postOrderTraversal(root->right); // visit right subree
  std::cout<<root->data<<"";  //visit root
}