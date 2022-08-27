#ifndef MAP_TREE_H
#define MAP_TREE_H

#include <iostream>

template<class K, class V>
class Tree {
private:
    enum Color : bool {
        RED,
        BLACK
    };

    struct Node {
        K key;
        V value;
        Node *left;
        Node *right;
        Node *parent;
        Color color;

        explicit Node(const K &_key, Node *_parent = nullptr, Node *_right = nullptr,
                      Node *_left = nullptr,
                      Color _color = RED)
                : key(_key),
                  value(),
                  parent(_parent),
                  right(_right),
                  left(_left),
                  color(_color) {}

        explicit Node(const K &_key, Color _color = RED, Node *_parent = nullptr)
                : key(_key),
                  value(),
                  parent(_parent),
                  right(nullptr),
                  left(nullptr),
                  color(_color) {}
    };

    Node *root;

    void turnRight(Node *node);

    void turnLeft(Node *node);

    void balanceAfterAdd(Node *node);

    void balanceAfterDel(Node *node);

    void pprint(Node *node, const int &level) {  // debug
        if (node != nullptr) {
            if (node->right != nullptr) {
                pprint(node->right, level + 2);
            }
            for (int i = 0; i < level; i++)
                std::cout << " ";
            std::cout << node->key << " " << (node->color == RED ? "RED" : "BLACK") << "\n";
            if (node->left != nullptr) {
                pprint(node->left, level + 2);
            }
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        Node *temp = root;
        Node *toDel;
        while (temp != nullptr) {
            if (temp->left != nullptr)
                temp = temp->left;
            else if (temp->right != nullptr)
                temp = temp->right;
            else {
                toDel = temp;
                if (temp != root) {
                    temp = temp->parent;
                    if (toDel->key < temp->key)
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
    void add(const K &key);

    void del(const K &key);

    void print() {  // debug
        if (root != nullptr) {
            if (root->right != nullptr) {
                pprint(root->right, 2);
            }
            std::cout << root->key << " " << (root->color == RED ? "RED" : "BLACK") << "\n";
            if (root->left != nullptr) {
                pprint(root->left, 2);
            }
        }
    }
};


#endif //MAP_TREE_H
