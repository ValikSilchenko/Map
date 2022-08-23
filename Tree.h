#ifndef MAP_TREE_H
#define MAP_TREE_H

#include <iostream>

template<class T>
class Tree {
private:
    enum Color {
        RED,
        BLACK
    };

    struct Node {
        T data;
        Node *left;
        Node *right;
        Node *parent;
        Color color;

        explicit Node(T _data, Node *_parent = nullptr, Node *_right = nullptr, Node *_left = nullptr,
                      Color _color = RED)
                : data(_data),
                  parent(_parent),
                  right(_right),
                  left(_left),
                  color(_color) {}
    };

    Node *root;

    void turnRight(Node *node);

    void turnLeft(Node *node);

    void balance(Node *node);

    void pprint(Node *node, const int &level) {  // debug
        if (node != nullptr) {
            if (node->right != nullptr) {
                pprint(node->right, level + 2);
            }
            for (int i = 0; i < level; i++)
                std::cout << " ";
            std::cout << node->data << "\n";
            if (node->left != nullptr) {
                pprint(node->left, level + 2);
            }
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        Node* temp = root;
        Node* toDel;
        while (temp != nullptr) {
            if (temp->left != nullptr)
                temp = temp->left;
            else if (temp->right != nullptr)
                temp = temp->right;
            else {
                toDel = temp;
                if (temp != root) {
                    temp = temp->parent;
                    if (toDel->data < temp->data)
                        temp->left = nullptr;
                    else
                        temp->right = nullptr;
                } else
                    temp = nullptr;
                delete toDel;
            }
        }
    }

    // Tree(Tree const &other)
    void add(T elem);

    void del(T elem);

    void print() {  // debug
        if (root != nullptr) {
            if (root->right != nullptr) {
                pprint(root->right, 2);
            }
            std::cout << root->data << "\n";
            if (root->left != nullptr) {
                pprint(root->left, 2);
            }
        }
    }
};


#endif //MAP_TREE_H
