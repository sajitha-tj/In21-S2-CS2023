#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL){
    return;
  }
  //traverse through the left side of the key
  traverseInOrder(root->left);
  //prints the root key
  cout << root->key << " ";
  //traverse through the right side of the key
  traverseInOrder(root->right);
  
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  // creates a new root if the tree is empty
  if (node == NULL){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
  }

  // adds the value to the left if the value is less than root
  if(key < node->key){
    node->left = insertNode(node->left,key);
  }
  // adds the value to the right if the value is greater than root
  else{
    node->right = insertNode(node->right, key);
  }
  return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL){
    return root;
  }
  // if the key is less than the root, goes to the left side
  if(key < root->key){
    root->left = deleteNode(root->left, key);
  }
  // if the key is greater than the root, goes to the right side
  else if (key > root->key){
    root->right = deleteNode(root->right, key);
  }
  else{
    // if root has no child nodes
    if(root->left == NULL and root->right == NULL){
      return NULL;
    }
    // if root has only one child node
    else if(root->left == NULL){
      // only child is in right
      struct node* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      // only child is in left
      struct node* temp = root->left;
      free(root);
      return temp;
    }
    // if root has both childs
    else{
      // finding the minimum value of the right side tree of the root
      struct node* minNode = root->right;
      while (minNode->left != NULL){
        minNode = minNode->left;
      }
      // assigning the minimum value to the root
      root->key = minNode->key;

      // delete the minimum value from the right side
      root->right = deleteNode(root->right, minNode->key);
      free(minNode);
    }
  }
  return root;
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