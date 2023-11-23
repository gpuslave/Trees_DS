#include <string>
const int d = 26;

// struct TrieNode
//{
//   TrieNode* alph[d+1];
// };

struct TrieNode {
  TrieNode* alph[d];
  bool end_of_word;
};

struct TrieNodeCh {
  char symbol;
  TrieNode* child;
  TrieNode* sibling;
};

// Общий алгоритм вставки 1)

// void insert(std::string str, std::size_t i, TrieNode* root) {
//   if (i < str.length()) {
//     if (root->alph[str[i] - 'a'] == nullptr) {
//       root->alph[str[i] - 'a'] = new TrieNode; // конструктор создавающий
//       insert(str, i + 1, root->alph[str[i] - 'a']);
//     }
//   }
//   root->end_of_word = true;
// }

/* AVL

TreeNode* RR_rotate(TreeNode* p) {
  TreeNode* q = p->left;
  p->left = q->right;
  q->right=p;
  fixheight(p); // пересчитывают высоту
  fixheight(q);
  return q;
}

TreeNode* LL_rotate(TreeNode* q) {
  TreeNode* p = q->right;
  q->right = p->left;
  p->left=q;
  fixheight(q);
  fixheight(p);
  return p;
}

// общая фукнция баланса
TreeNode* Balance(TreeNode* p) {
  fixHeight(p);
  if( balance(p) == 2 ) {
    if( balance(p->right) < 0 )
      p->right = RR_rotate(p->right);
      return LL_rotate(p);
  }

  if( balance(p) == -2 ) {
    if( balance(p->left) > 0 )
      p->left = LL_rotate(p->left);
    return RR_rotate(p);
  }

  return p;
}

// функция баланса
TreeNode* insert(TreeNode* pNode, int elem) {
  if(pNode == 0) {
    pNode = new TreeNode;
    pNode->data = elem;
    pNode->left = 0;
    pNode->right = 0;
    pNode->height = 1;
    return Balance(pNode);
  }

  if(elem < pNode->data) {
    pNode->left = insert(pNode->left, elem);
  }
  if(elem > pNode->data) {
    pNode->right = insert(pNode->right, elem);
  }
  return Balance(pNode);
}

// функция поиска
TreeNode* findMin(TreeNode* p) {
  return p->left ? findMin(p->left) : p;
}

TreeNode* removeMin(TreeNode* p) {
  if(p->left == 0)
    return p->right;
  p->left = removeMin(p->left);
  return Balance(p);
}

TreeNode* remove(TreeNode* pNode, int elem) {
  if(!pNode) return nullptr;
  if( elem < pNode->data ) {
    pNode->left = remove(pNode->left, elem);
  }
  else if( elem > pNode->data) {
    pNode->right = remove(pNode->right, elem);
  }
  else {
    TreeNode* q = pNode->left;
    TreeNode* r = pNode->right;
    delete pNode;
    if(!r) return q;
    TreeNode* minNode = findMin(r);
    minNode->right = removeMin(r);
    minNode->left = q;
    return Balance(minNode);
  }
  return Balance(pNode);
}


*/