#pragma once
#include <iostream>

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