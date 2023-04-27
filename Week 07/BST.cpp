#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root == nullptr){
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if(node == nullptr){
        node = new struct node;
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
    }else if(key <= node->key){
        node->left = insertNode(node->left, key);
    }else{
        node->right = insertNode(node->right, key);
    }
    return node;
}

// Finding minimum Element
node* minElement(node* root){
    if(root == nullptr){
        return root;
    }
    else if(root->left == nullptr){
        return root;
    }
    return minElement(root->left);
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr){
        return root;
    }else if (key > root->key){
        root->right = deleteNode(root->right, key);
    }else if (key < root->key){
        root->left = deleteNode(root->left, key);
    }else{
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }else if (root->left == nullptr){
            node* temp = root;
            root = root->right;
            delete temp;
        }else if (root->right == nullptr){
            node* temp = root;
            root = root->left;
            delete temp;
        }else {
            node* temp = minElement(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = nullptr;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  traverseInOrder(root);
}