#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

class BinaryTree
{
  private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int val);
    void deleteTree(TreeNode* node);
    void preO(TreeNode* rootA);
    void iO(TreeNode* rootA);
    void poO(TreeNode* rootA);
  public:
    BinaryTree();
    ~BinaryTree();
    void insertVal(int val);
    void preOrder();
    void inOrder();
    void postOrder();
    void printTree();
    void balanceamento();
    void remove(int val);
};

#endif
