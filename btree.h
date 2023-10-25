#pragma once

typedef int data_t;

struct TreeNode {
  data_t data;
  TreeNode* left;
  TreeNode* right;
};

typedef TreeNode* TTree;

// 1) �������� �������
void init(TTree& root) { root = nullptr; }

bool isTreeEmpty(const TTree& root) { return root == nullptr; }

// 2) �������� � ����� �����
void init(TTree& root, data_t elem) {
  root = new TreeNode;
  root->data = elem;
  root->left = nullptr;
  root->right = nullptr;
}

// 8) ������������� � ����� ������ ���������
bool attachLeftSubTree(TTree root, TTree subTree) {
  bool canAttach = false;
  if (root->left == nullptr) {
    root->left = subTree;
    canAttach = true;
  }
  return canAttach;
}

bool attachRightSubTree(TTree root, TTree subTree) {
  bool canAttach = false;
  if (root->right == nullptr) {
    root->right = subTree;
    canAttach = true;
  }
  return canAttach;
}

// 3)
void init(TTree& root, data_t elem, TTree leftSubTree, TTree rightSubTree) {
  init(root, elem);
  attachLeftSubTree(root, leftSubTree);
  attachRightSubTree(root, rightSubTree);
}

// ������������ ������ ���������
void detachLeftSubTree(TTree root, TTree& leftSubTree) {
  leftSubTree = root->left;
  root->left = nullptr;
}

// �������� ����� ������
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

// ��������� ����� ������ ���������
TTree getLeftSubTree(TTree root) {
  TTree toReturn = nullptr;
  copyTree(root->left, toReturn);
  return toReturn;
}

// �������� ��������� ������
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