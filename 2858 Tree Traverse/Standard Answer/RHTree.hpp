#ifndef RHTREE_HPP_
#define RHTREE_HPP_
#include <cstddef>

struct RHNode {
  int data;
  RHNode *left, *right;
  RHNode(int data, RHNode *left = NULL, RHNode *right = NULL) {
    this->data = data;
    this->left = left;
    this->right = right;
  }
};
class RHTree {
private:
  RHNode *root;
  void insertNode(RHNode*& root, const int &data);
public:
  RHTree();
  RHNode* getRoot();
  void insert(const int &data);
  void preOrder(RHNode *x);
  void inOrder(RHNode *x);
  void postOrder(RHNode *x);
  void deleteNode(RHNode *x);
  ~RHTree();
};

#endif