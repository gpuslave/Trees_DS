// ������ - ������� ���� ��� ������.
// �������� ������ - �� ����� 2 �����.
// ������ ������ - ���������� �����, ������������� �� ����� ������� ���� �� ����� � �����.
// ������ ������ ���������� ��� �����, � �� ����.
// ������ ������ - ��� ���� � �������� ��� ������������ �����.
// ���� - ��� ���� � �������� ��� �������� �����.
// ��������� - ���������� ���� �� ������ ����.
// � ������ ������ ������� ���������, ������� ���������� �����-�� ��������.
// � ��������� ������ ���� ����� � ������ �������� ����.


/* ���������� �������� ������, ��� � ����� ������, ��� ����� ���� ���������� ����������.
  �� ����:
  1) ������ ������.
  2) ���� � ��� ���������: T_left , T_right --- �������� �������.
*/

//�������� ��� �������� �������:
// +1) �������� �������.
// +2) �������� ��������� ������, ����������� ���� ����, �� ��������� ��������.
// +3) �������� ��������� ������ �� ��������� ����� � ���� �������� ����������� ����� �����.
// +4) �������� ��������� ������.
// +5) �������� �� �������.
// -6) ����������� ��� ��������� ������, ���������� � ����� ��������� ������.
// -7) ������������� � ����� ������ ������� ��� ������ ��������� ����.
// +8) �������������� � ����� ������ ������ ��� ������� ���������.
// +9) ������������ �� ����� ������ ��� ������� ���������.
// +10) �������� ������ ����� ������.
// +11) ��������� ����� ������ ��� ������� ��������� ����� ��������� ������.

// ������ �������:
// ((a+b)*(c-d))*f
//
//       *
//      / \
//     *   f
//    / \
//   +   -
//  /\   /\
// a  b c  d
//

// ���������� ��� ���� ������ - � �������(� ���� �� �����), � ������(�� ��������).
// 
// ���������� ��� �������� ������ � ������� - ����������, �����������, ���������.
//   A
//  / \
// B   C
// 
//  1) ABC - �������(������)
//  2) BAC - ������(������������)
//  3) BCA - ��������(��������)
// 
// 
// ����� � ������ � ������� �������.


// �������� ���������������� ������ - ��� ����� ������, ��� ��� ������� ���� ����� ����� � ����� � ������ �����������
// ���������� �� ����� ��� �� �������.
// ����� �������� ���������� - ����������� ������ ���� � �������� �����, ����� �������� ����� ���������������� ���������
// � ������ ����� n_l = n div 2 , � ��������� ������ ���������������� ���������� � ������ ����� n_r = n - n_l - 1.
// �������� ������ � ����� �������� - ������� ���������� �����, � ����� ��������������� ��� ���� ������.

/* �������� ������ ������ - �������� ������, ��� �������� �������� ������������� �������, �������� ���� ������, 
   ��� �������� � ����� ��� ������� ��������� � �����, ��� �� ���� ����� ������ ���������: 
   (����� ��������� ������ � �������)

//       *
//      / \
//     *   f
//    / \
//   +   -
//  /\   /\
// a  b c  d
  
  ��������:
  1) �������� ������� ������
  2) �������/��������
  3) �������� �� �������

  4) ������� �������� (�������� ������ ����������� � ����)
  5) �������� �������� ( ��� �������� �������� ��� ������: ������� - ����(������ ���������), 
                                                           ������� - ����� ������ �������(������ ��� �������, �� ���� ������� ������ �� ������ ������������
                                                           ����������� �� ����� ���������� ��������, � ��� ���������� ����������� ��������� ��������),
                                                           ������� - ����� ����� ��������(������ ��� ��������� ��������(���� � ���������� ������, ������������� ������� ��������� ���������� ����, ���� ���� ���� ������ �� ����� ��������, ���� ����� ������ ������� �������, ��� ��� � ��������� ������ �� �� ��� �� ����������, ���������� ����������� �� ��� ������ ���������) ��� ��������� ��������������)
                       )
  6) ����� �������� �� �����


*/



/* 11/9/23  
trie-trees(���������� ������, ���, ���):
    ������������ ��� �������� ��������� �� �����, ��� ������ �������� �����.

    ������������� ���� ������:
    1) � ���� �������� ������, ��� ������ ������� ������� ������������ ������ ����� ��������
    2) ����������� ������

    ����� ������ ������ ������������� ���������� ������ �������� �������.
*/





#include <iostream>
#include "btree.h"

int main()
{
  TTree tree = new TreeNode;
  TTree copy = nullptr;
  init(tree, 1);
  init(tree->left, 2);
  init(tree->right, 3);
  init(tree->left->left, 4);

  viewTree(tree);
  copyTree(tree, copy);
  viewTree(copy);
  destroyTree(tree);
  std::cout << tree;
}

