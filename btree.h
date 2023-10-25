#pragma once
#include <iostream>

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