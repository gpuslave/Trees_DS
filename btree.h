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

// Проверка на пустоту
bool isTreeEmpty(const TTree& root);

void viewTree(TTree root);

// 1) Создание пустого
void init(TTree& root);

// 2) Создание с одним узлом
void init(TTree& root, data_t elem);

// 8.1) Присоединение к корню левого поддерева
bool attachLeftSubTree(TTree root, TTree subTree);
// 8.2) Присоединение к корню левого поддерева
bool attachRightSubTree(TTree root, TTree subTree);

// 3) Создание бинарного дерева по заданному корню и двум бинарным поддеревьям
// этого корня.
void init(TTree& root, data_t elem, TTree leftSubTree, TTree rightSubTree);

// 9.1) Отсоединение левого поддерева
void detachLeftSubTree(TTree root, TTree& leftSubTree);

// 9.2) Отсоединение правого поддерева
void detachRightSubTree(TTree root, TTree& rightSubTree);

// 10) Создание копии дерева
void copyTree(TTree root, TTree& newRoot);

// 11.1) Получение копии левого поддерева
TTree getLeftSubTree(TTree root);

// 11.2) Получение копии правого поддерева
TTree getRightSubTree(TTree root);

// 12) Удаление бинарного дерева
void destroyTree(TTree& root);

// префиксный обход
void preOrderView(TTree root);

// дописать остальные обходы в глубину ...

// Обход в ширину на очереди
void breadthFirstSearch(TTree root);

// Итеративный(симметричный) обход в глубину с помощью стека
void inorderIterative(TTree root);

// Сбалансированное дерево
void createBalancedTree(TTree& root, std::string filename);

// Вставка в дерево поиска
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

// Удаление
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
