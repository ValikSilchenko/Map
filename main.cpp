#include <iostream>
#include "Tree.cpp"

int main() {
    Tree<int> tree;
    tree.add(12);
    tree.add(26);
    tree.add(5);
    tree.add(1);
    tree.add(7);
    tree.add(25);
    tree.print();
    return 0;
}
