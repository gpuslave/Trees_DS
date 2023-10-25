#include "btree.h"

bool isTreeEmpty(const TTree& root) { return root == nullptr; }

void init(TTree& root) { root = nullptr; }

void init(TTree& root, data_t elem) {
  root = new TreeNode;
  root->data = elem;
  root->left = nullptr;
  root->right = nullptr;
}

bool attachLeftSubTree(TTree root, TTree subTree) {
  bool is_attached = false;
  if (root->left == nullptr) {
    root->left = subTree;
    is_attached = true;
  }
  return is_attached;
}

bool attachRightSubTree(TTree root, TTree subTree) {
  bool is_attached = false;
  if (root->right == nullptr) {
    root->right = subTree;
    is_attached = true;
  }
  return is_attached;
}

void init(TTree& root, data_t elem, TTree leftSubTree, TTree rightSubTree) {
  init(root, elem);
  attachLeftSubTree(root, leftSubTree);
  attachRightSubTree(root, rightSubTree);
}

void detachLeftSubTree(TTree root, TTree& leftSubTree) {
  leftSubTree = root->left;
  root->left = nullptr;
}

void detachRightSubTree(TTree root, TTree& rightSubTree) {
  rightSubTree = root->right;
  root->right = nullptr;
}

void copyTree(TTree root, TTree& newRoot) {
  if (root != nullptr) {
    newRoot = new TreeNode;
    newRoot->data = root->data;
    newRoot->left = nullptr;
    newRoot->right = nullptr;
    copyTree(root->left, newRoot->left);
    copyTree(root->right, newRoot->right);
  }
}

TTree getLeftSubTree(TTree root) {
  TTree toReturn = nullptr;
  copyTree(root->left, toReturn);
  return toReturn;
}

TTree getRightSubTree(TTree root) {
  TTree toReturn = nullptr;
  copyTree(root->right, toReturn);
  return toReturn;
}

void destroyTree(TTree& root) {
  if (root != nullptr) {
    destroyTree(root->left);
    destroyTree(root->right);
    root->left = nullptr;
    root->right = nullptr;
    delete root;
    root = nullptr;
  }
}

void viewTree(TTree root) {
  if (root != nullptr) {
    std::cout << root->data << std::endl;
    viewTree(root->left);
    viewTree(root->right);
  }
}