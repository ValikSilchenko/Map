#include <iostream>
#include "Tree.cpp"

int main() {
    Tree<int> tree;
    tree.add(12);
    tree.add(11);
    tree.add(5);
    tree.add(1);
    tree.add(0);
    tree.add(7);
    tree.add(25);
    tree.add(6);
    tree.print();
    std::cout << "-----------------\n";
    tree.del(7);
    tree.print();
    std::cout << "-----------------\n";
    tree.del(11);
    tree.print();
    std::cout << "-----------------\n";
    tree.del(6);
    tree.print();
    std::cout << "-----------------\n";
    return 0;
}
