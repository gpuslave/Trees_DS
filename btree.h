#pragma once
#include <fstream>
#include <iostream>
#include <string>

typedef int data_t;

struct TreeNode {
  data_t data;
  TreeNode* left;
  TreeNode* right;
};

typedef TreeNode* TTree;

// �������� �� �������
bool isTreeEmpty(const TTree& root);

void viewTree(TTree root);

// 1) �������� �������
void init(TTree& root);

// 2) �������� � ����� �����
void init(TTree& root, data_t elem);

// 8.1) ������������� � ����� ������ ���������
bool attachLeftSubTree(TTree root, TTree subTree);
// 8.2) ������������� � ����� ������ ���������
bool attachRightSubTree(TTree root, TTree subTree);

// 3) �������� ��������� ������ �� ��������� ����� � ���� �������� �����������
// ����� �����.
void init(TTree& root, data_t elem, TTree leftSubTree, TTree rightSubTree);

// 9.1) ������������ ������ ���������
void detachLeftSubTree(TTree root, TTree& leftSubTree);

// 9.2) ������������ ������� ���������
void detachRightSubTree(TTree root, TTree& rightSubTree);

// 10) �������� ����� ������
void copyTree(TTree root, TTree& newRoot);

// 11.1) ��������� ����� ������ ���������
TTree getLeftSubTree(TTree root);

// 11.2) ��������� ����� ������� ���������
TTree getRightSubTree(TTree root);

// 12) �������� ��������� ������
void destroyTree(TTree& root);

// ���������� �����
void preOrderView(TTree root);

// �������� ��������� ������ � ������� ...

// ����� � ������ �� �������
void breadthFirstSearch(TTree root);

// �����������(������������) ����� � ������� � ������� �����
void inorderIterative(TTree root);

// ���������������� ������
void createBalancedTree(TTree& root, std::string filename);

// ������� � ������ ������
void insert(TTree& root, data_t elem);

bool search(TTree root, data_t elem) {
  if (root != nullptr) {
    if(root->data == elem)
      return true;
    else if (root->data > elem) {
      return search(root->left, elem);
    }
    else {
      return search(root->right, elem);
    }
  } else
    return false;
}

data_t findSuccessor(TTree p) {
  TTree cur = p;
  while (cur->left != nullptr) {
    cur = cur->left;
  }
  data_t elem = cur->data;
  TTree temp = cur;
  cur = cur->right;
  delete temp;
  return elem;
}

void deleteNode(TTree& pnode) {
  if (pnode->left == nullptr && pnode->right == nullptr) {
    delete pnode;
    pnode = nullptr;
  } else if (pnode->left == nullptr || pnode->right == nullptr) {
    TTree temp = pnode;
    if (pnode->left != nullptr) {
      pnode = pnode->left;
    } else {
      pnode = pnode->right;
    }
    delete temp;
  } else {
    pnode->data = findSuccessor(pnode->right);
  }
}

// ��������
void remove(TTree root, data_t elem) {
  if (root != nullptr) {
    if (root->data == elem)
      deleteNode(root);
    else if (root->data > elem) {
      remove(root->left, elem);
    } else {
      remove(root->right, elem);
    }
  }
}
