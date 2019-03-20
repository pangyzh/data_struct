#include "RHTree.hpp"
#include <iostream>

void RHTree::insertNode(RHNode*& root, const int &data) {
  if (!root) {
    root = new RHNode(data, NULL, NULL);
  } else {
    if (root->data >= data)
      insertNode(root->left, data);
    else
      insertNode(root->right, data);
  }
}

RHTree::RHTree() { root = NULL; }
RHTree::~RHTree() { deleteNode(root); }
void RHTree::insert(const int &data) { insertNode(root, data); }
RHNode* RHTree::getRoot() { return root; }

void RHTree::preOrder(RHNode *x) {
  if (!x) return;
  std::cout << " " << x->data;
  preOrder(x->left);
  preOrder(x->right);
}
void RHTree::inOrder(RHNode *x) {
  if (!x) return;
  inOrder(x->left);
  std::cout << " " << x->data;
  inOrder(x->right);
}
void RHTree::postOrder(RHNode *x) {
  if (!x) return;
  postOrder(x->left);
  postOrder(x->right);
  std::cout << " " << x->data;
}
void RHTree::deleteNode(RHNode *x) {
  if (!x) return;
  deleteNode(x->left);
  deleteNode(x->right);
  delete x;
}