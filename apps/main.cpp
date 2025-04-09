#include "BinaryTree.h"

int main()
{
  BinaryTree tree;
  
  tree.insertVal(5);
  tree.insertVal(3);
  tree.insertVal(4);
  tree.insertVal(7);
  tree.insertVal(6);
  tree.insertVal(8);
  tree.insertVal(10);
  tree.insertVal(11);
  tree.insertVal(12);
  tree.insertVal(13);
  tree.insertVal(14);
  tree.insertVal(15);
  tree.insertVal(16);
  tree.insertVal(17);
  tree.insertVal(18);
  tree.insertVal(19);

  /*tree.preOrder();
  std::cout << std::endl; 
  tree.inOrder();
  std::cout << std::endl; 
  tree.postOrder();
  std::cout << std::endl;*/
  
  std::cout << "Impressão da Arvore\n-------------------\n"; 
  tree.printTree();
  std::cout << std::endl;
  tree.balanceamento();

  tree.remove(10);
  std::cout << "Impressão da Arvore" << std::endl << "-------------------" << std::endl; 
  tree.printTree();
  std::cout << std::endl;
  tree.remove(7);
  std::cout << "Impressão da Arvore" << std::endl << "-------------------" << std::endl; 
  tree.printTree();
  std::cout << std::endl;

  return 0;
}
