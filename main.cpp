#include <iostream>
#include "Tree.cpp"

int main() {
    Tree<int> tree;
    tree.add(12);
    tree.add(11);
    tree.add(5);
    tree.print();
    std::cout << "-----------------\n";
    tree.add(1);
    tree.print();
    std::cout << "-----------------\n";
    tree.add(0);
    tree.print();
    std::cout << "-----------------\n";

    return 0;
}
