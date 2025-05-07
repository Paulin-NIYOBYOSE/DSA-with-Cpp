#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

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

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "In-order traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    levelOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}