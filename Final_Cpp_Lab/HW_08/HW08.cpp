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

  void remove(int value) {
    int i = 0;
    bool pointing, moving;
    BSTNode *p, *previous, *x, *y = new BSTNode;
    p = root;

    if (p == nullptr) {
      return;
    }

    while (p -> value != value) {

      if (p == nullptr) {
        return;
      }
      i ++;
      previous = p;

      if (p -> value > value) {
        p = p -> left;
        pointing = true;
      }else {
        p = p -> right;
        pointing = false;
      }
    }

    // NO CHILD !!!!!!

    if (p -> left == nullptr && p -> right == nullptr) {
      if (pointing == true) {
        previous -> left = nullptr;
      }else {
        previous -> right = nullptr;
      }
      free_node(x);
    }

    // HAVE 2 CHILD !!!!!!!

    else if ((p -> left != nullptr && p -> right == nullptr) || (p -> left == nullptr &&  p -> right != nullptr)) {

      if (p -> left != nullptr) {
        if (pointing == true) {
          x = previous -> left;
          previous -> left = x -> left;  
        }else {
          x = previous -> right;
          previous -> right = x -> right;
        }
        free_node(x);
      }else {
        if (pointing == true) {
          previous -> left = x -> right;
        }
      }
    }

  }
  int get_depth(int value) {
    BSTNode *newnode = new BSTNode();
    newnode->value = value;
    newnode->left = nullptr;
    newnode->right = nullptr;
    BSTNode *p;
    
    int dist = 0;
    if (root == nullptr) {
      return dist ;
    }else {
      p = root;
      while (p -> value != value && p != nullptr) {
        if (p->value > value) {
          p = p -> left; 
        } else {
          p = p -> right;
        } dist += 1;
      }
    }

    if (p == nullptr) {
      return dist;
    }else {
      return -1;
    }    
  }

 void free_node(BSTNode *x){

  x -> left = nullptr;
  x -> right = nullptr;
  delete x;
 } 
};
