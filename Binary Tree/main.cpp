#include <iostream>
#include "Tree.h"


int main() 
{
    system("chcp 1251 > nul");
    Tree tree;

    tree.insert(51);
    tree.insert(48);
    tree.insert(36);
    tree.insert(73);
    tree.insert(29);
    tree.insert(66);
    tree.insert(80);
    tree.insert(90);
    tree.insert(110);

    std::cout << "������ �����: ";
    tree.preorderTraversal();

    std::cout << "������������ �����: ";
    tree.inorderTraversal();

    std::cout << "�������� �����: ";
    tree.postorderTraversal();

    std::cout << "����� �� ����� 73: " << (tree.search(73) ? "�������" : "�� �������") << std::endl;
    std::cout << "����� �� ����� 55: " << (tree.search(55) ? "�������" : "�� �������") << std::endl;
    tree.visualizeTree();
    tree.remove(80);
    std::cout << "������������ ����� ����� �������� 80: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    tree.visualizeTree();
    return 0;
}