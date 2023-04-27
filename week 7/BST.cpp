#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root == NULL){
        return;
    }
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root_node, int key) {
    if(root_node == NULL){
        node *new_node = new node;
        new_node->key = key;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    else if(key >= root_node->key){
        root_node->right = insertNode(root_node->right,key);
    }
    else if(key < root_node->key){
        root_node->left = insertNode(root_node->left,key);
    }

    return root_node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root == NULL){
        return root;
    }
    if(key < root->key){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right,key);
    }

    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }

        else if(root->left == NULL){
            node *temp = root;
            root = root->right;
            delete temp;
        }

        else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            delete temp;
        }

        else{
            node *temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
        return root;
    }
}

// Driver code
int main() {
  struct node *root = NULL;

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
