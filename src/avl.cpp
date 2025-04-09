#include "BinaryTree.h"
#include "TreeNode.h"

TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

int TreeNode::getData() const { return data; }
TreeNode* TreeNode::getLeft() const { return left; }
TreeNode* TreeNode::getRight() const { return right; }

void TreeNode::setLeft(TreeNode* node) { left = node; }
void TreeNode::setRight(TreeNode* node) { right = node; }

TreeNode::~TreeNode() {}

TreeNode* TreeNode::minValueNode(TreeNode* node) 
{
  TreeNode* current = node;
  // Continua indo para a esquerda até encontrar o menor valor
  while (current && current->left != nullptr)
      current = current->left;
  return current;
}

void TreeNode::printTree(const string& prefix, bool isLeft) 
{
    // Caso exista filho à direita, chama recursivamente para ele
    if (right)
        right->printTree(prefix + (isLeft ? "│   " : "    "), false);

    // Exibe o prefixo (indentação) e o tipo de aresta (└── ou ┌──)
    cout << prefix;
    cout << (isLeft ? "└── " : "┌── ");
    cout << data << endl;

    // Caso exista filho à esquerda, chama recursivamente para ele
    if (left)
        left->printTree(prefix + (isLeft ? "    " : "│   "), true);
}

bool TreeNode::search(int key) 
{
    if (data == key)
        return true;
    if (key < data && left)
        return left->search(key);
    if (key > data && right)
        return right->search(key);
    return false;
}

int TreeNode::height() 
{
    int leftHeight = left ? left->height() : 0;
    int rightHeight = right ? right->height() : 0;
    return 1 + max(leftHeight, rightHeight);
}

TreeNode* TreeNode::deleteNode(int key) 
{
    if(key < data && left)
    {
        left = left->deleteNode(key);
    }
    else if (key < data && right)
    {
        right = right->deleteNode(key);
    }
    else if (key == data)
    {
        // Caso 1: sem filho a esq
        if(!left){
            TreeNode* temp = right;
            this->right = nullptr;
            delete this;
            return temp;
        }
        //Caso 2: sem filho a dir
        if (!right)
        {
            TreeNode* temp = left;
            this->left = nullptr;               
            delete this;
            return temp;
        }
        TreeNode* temp = minValueNode(right);
        data = temp->data;
        right = right->deleteNode(temp->data);
        cout << "\nDeletado\n";
    }
    // Retorna o ponteiro atual (em caso de não remoção)
    return this;
}

void TreeNode::clear() 
{
    if (left)
    {
        left->clear();
        delete left;
    }
    if (right)
    {
        right->clear();
        delete right;
    }
}

int TreeNode::getMin() 
{
    if (!left) return data;
    return left->getMin();
}

int TreeNode::getMax() 
{
    if (!right) return data;
    return right->getMin();     
}

int TreeNode::countNodes() 
{
    int count = 1;
    if(left)
        count += left->countNodes();
    if(right)
        count += right->countNodes();
    return count;
}

int TreeNode::countLeaves() 
{
    if(!left && !right)
        return 1;
    int leaves = 0;
    if(left)
        leaves += left->countLeaves();
    if(right)
        leaves += right->countLeaves();
    return leaves;
}

int TreeNode::BalanceDiference(TreeNode* root)
{
  int lHeight = root->left ? root->left->height() : 0;
  int rHeight = root->right ? root->right->height() : 0;
  int diference = lHeight - rHeight;
  return diference;
}

int TreeNode::balanceCheck(TreeNode* root)
{
  int d = BalanceDiference(root);
  if((d < -1) || (d > 1)) return 0;
  return 1;
}

TreeNode* TreeNode::rotationL(TreeNode* root)
{
  TreeNode *a = root->right;
  TreeNode *b = a->left;

  a->left = root;
  root->right = b;
  return a;
}

TreeNode* TreeNode::rotationR(TreeNode* root)
{
  TreeNode *a = root->left;
  TreeNode *b = a->right;

  a->right = root;
  root->left = b;
  return a;
}

TreeNode* TreeNode::rotationRL(TreeNode* root)
{
  root->right = rotationR(root->right);
  return rotationL(root);
}

TreeNode* TreeNode::rotationLR(TreeNode* root)
{
  root->left = rotationL(root->left);
  return rotationR(root);
}

TreeNode* TreeNode::balance(TreeNode* root)
{
  if(BalanceDiference(root) > 1)
  {
    if(BalanceDiference(root->left) >= 0)
    {
      root = rotationR(root);
    }
    else{
      root = rotationLR(root);
    }
  }
  if(BalanceDiference(root) < -1)
  {
    if(BalanceDiference(root->right) <= 0)
    {
      root = rotationL(root);
    }
    else{
      root = rotationRL(root);
    }
  }
  return root;
}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree()
{
  deleteTree(root);
  std::cout << "Arvore Deletada";
}

TreeNode* BinaryTree::insert(TreeNode* node, int val)
{
  if(node == nullptr)
  {
    return new TreeNode(val);
  }
  if(val < node -> getData())
  {
    node->setLeft(insert(node->getLeft(), val));
  } else if(val > node->getData())
  {
    node->setRight(insert(node->getRight(), val));
  }
  node = node->balance(node);
  return node;
}

void BinaryTree::deleteTree(TreeNode* node) 
{
  if (node != nullptr) 
  {
    deleteTree(node->getLeft());
    deleteTree(node->getRight());
    delete node;
  }
}

void BinaryTree::preO(TreeNode* rootA)
{
  if(rootA != nullptr)
  {
    std::cout << rootA->getData() << " | ";
    preO(rootA->getLeft());
    preO(rootA->getRight());
  }
}

void BinaryTree::iO(TreeNode* rootA)
{
  if(rootA != nullptr)
  {
    iO(rootA->getLeft());
    std::cout << rootA->getData() << " | ";
    iO(rootA->getRight());
  }
}

void BinaryTree::poO(TreeNode* rootA)
{
  if(rootA != nullptr)
  {
    poO(rootA->getLeft());
    poO(rootA->getRight());
    std::cout << rootA->getData() << " | ";
  }
}

void BinaryTree::insertVal(int val)
{
  root = insert(root, val);
}

void BinaryTree::preOrder()
{
  preO(root);
}

void BinaryTree::inOrder()
{
  iO(root);
}

void BinaryTree::postOrder()
{
  poO(root);
}

void BinaryTree::printTree()
{
  if(root) root->printTree();
}

void BinaryTree::balanceamento()
{
  if(root) std::cout << "Diferença de balanceamento: " << root->BalanceDiference(root) << std::endl;
}

void BinaryTree::remove(int val)
{
  if(root) root = root->deleteNode(val);
}
