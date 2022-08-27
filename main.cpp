#include <iostream>
#include "Tree.cpp"

int main() {
    Tree<int, int> tree;
    tree.add(12);
    tree.add(11);
    tree.add(10);
    tree.add(9);
    tree.add(6);
    tree.add(5);
    tree.add(8);
    tree.add(7);
    tree.add(15);
    tree.add(13);

    tree.print();
    std::cout << "-----------------\n";
    tree.del(12);
    tree.print();
    std::cout << "-----------------\n";
    tree.del(11);
    tree.print();
    std::cout << "-----------------\n";
    tree.del(9);
    tree.print();
    std::cout << "-----------------\n";
    tree.del(15);

    tree.print();
    std::cout << "-----------------\n";
    tree.del(10);
//    tree.add(17);
//    tree.add(15);
    tree.print();
    std::cout << "-----------------\n";

    return 0;
}
