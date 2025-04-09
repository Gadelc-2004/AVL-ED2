#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class TreeNode 
{
  private:
    int data;
    TreeNode* left;
    TreeNode* right;
        
    TreeNode* minValueNode(TreeNode* node);
    
  public:
    //construtor
    TreeNode(int val);

    //Metodos de acesso
    int getData() const;
    TreeNode* getLeft() const;
    TreeNode* getRight() const;

    //setters
    void setLeft(TreeNode* node);
    void setRight(TreeNode* node);

    ~TreeNode();

    void printTree(const string& prefix = "", bool isLeft = true);
    // Busca um valor 'key' na árvore:
    bool search(int key);
    // Calcula a altura da árvore, retornando a maior profundidade entre os sub-ramos
    int height();
    // Exclui um nó com o valor 'key' da árvore, mantendo as regras da BST.
    // Casos de deleção:
    //  1. Nó folha (sem filhos)
    //  2. Nó com apenas um filho (esquerdo ou direito)
    //  3. Nó com dois filhos (troca pelo sucessor ou predecessor e deleta o substituído)
    TreeNode* deleteNode(int key);
    // Libera recursivamente todos os nós da subárvore
    // transformando o nó atual em uma árvore vazia
    void clear();
    // Retorna o valor mínimo da árvore
    int getMin();
    // Retorna o valor máximo da árvore
    int getMax();
    // Retorna a contagem total de nós na subárvore
    int countNodes();
    // Retorna a contagem de folhas (nós sem filhos)
    int countLeaves();

    int BalanceDiference(TreeNode* root);
    int balanceCheck(TreeNode* root);

    TreeNode* rotationL(TreeNode* root);
    TreeNode* rotationR(TreeNode* root);
    TreeNode* rotationRL(TreeNode* root);
    TreeNode* rotationLR(TreeNode* root);

    TreeNode* balance(TreeNode* root);
};

#endif
