#include "BSTNode.cpp"
class BST {

public:
  BSTNode *root;

  BST() { root = nullptr; }

  void insert(int value) {
    BSTNode *newnode = new BSTNode();
    newnode->value = value;
    newnode->left = nullptr;
    newnode->right = nullptr;

    BSTNode *p, *previous;

    if (root == nullptr) {
      root = newnode;
    } else {
      p = root;
      while (p != nullptr) {
        previous = p;
        if (p->value > newnode->value) {
          p = p->left;
        } else {
          p = p->right;
        }
      }
    }

    if (previous -> value > newnode -> value) {
      previous -> left = newnode;
    }else {
      previous -> right = newnode;
    }
  }

  // void remove(int value) {
  //  if (root == NULL)
  //       return root;
  //   if (value < root->value)
  //       root->left = deleteNode(root->left, value);
  //   else if (value > root->value)
  //       root->right = deleteNode(root->right, value);
  //   else {
  //       if (root->left==NULL and root->right==NULL)
  //           return NULL;
  //       else if (root->left == NULL) {
  //           struct node* temp = root->right;
  //           free(root);
  //           return temp;
  //       }
  //       else if (root->right == NULL) {
  //           struct node* temp = root->left;
  //           free(root);
  //           return temp;
  //       }
  //       struct node* temp = minValueNode(root->right);
  //       root->value = temp->value;
  //       root->right = deleteNode(root->right, temp->value);
  //   }
  // }

  // int get_depth(int value) {
  //   if (root == NULL)
  //   return 0;

  //   int leftDepth = maxDepth(root->left);
  //   int rightDepth = maxDepth(root->right);
  //   if (leftDepth > rightDepth)
  //     return leftDepth + 1;
  //   else
  //     return rightDepth + 1;
  //   //return -1;
  // }
};
