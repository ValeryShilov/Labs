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

    std::cout << "Прямой обход: ";
    tree.preorderTraversal();

    std::cout << "Симметричный обход: ";
    tree.inorderTraversal();

    std::cout << "Обратный обход: ";
    tree.postorderTraversal();

    std::cout << "Поиск по ключу 73: " << (tree.search(73) ? "Найдено" : "Не найдено") << std::endl;
    std::cout << "Поиск по ключу 55: " << (tree.search(55) ? "Найдено" : "Не найдено") << std::endl;
    tree.visualizeTree();
    tree.remove(80);
    std::cout << "Симметричный обход после удаления 80: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    tree.visualizeTree();
    return 0;
}