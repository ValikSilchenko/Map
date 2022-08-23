#include "Tree.h"

template<class T>
void Tree<T>::turnRight(Tree::Node *node) {
    if (node->left != nullptr) {
        Node *temp = node->left->right;
        node->left->right = node;

        if (node == root)
            root = node->left;
        else {
            if (node->data < node->parent->data)
                node->parent->left = node->left;
            else
                node->parent->right = node->left;
        }
        node->left->parent = node->parent;
        node->parent = node->left;
        node->left->right->parent = node->left;
        if (temp != nullptr)
            temp->parent = node->left->right;
        node->left->right->left = temp;
    }
}

template<class T>
void Tree<T>::turnLeft(Tree::Node *node) {
    if (node->right != nullptr) {
        Node *temp = node->right->left;
        node->right->left = node;

        if (node == root)
            root = node->right;
        else {
            if (node->data < node->parent->data)
                node->parent->left = node->right;
            else
                node->parent->right = node->right;
        }
        node->right->parent = node->parent;
        node->parent = node->right;
        node->right->left->parent = node->right;
        if (temp != nullptr)
            temp->parent = node->right->left;
        node->right->left->right = temp;
    }
}

template<class T>
void Tree<T>::del(T elem) {

}

template<class T>
void Tree<T>::add(T elem) {
    if (root == nullptr)
        root = new Node(elem);
    else {
        Node *temp = root;
        while (true) {
            if (elem < temp->data) {  // left branch
                if (temp->left != nullptr)
                    temp = temp->left;
                else {
                    temp->left = new Node(elem, temp);
                    break;
                }
            } else if (temp->data < elem) {  // right branch
                if (temp->right != nullptr)
                    temp = temp->right;
                else {
                    temp->right = new Node(elem, temp);
                    break;
                }
            } else
                break;
        }
    }

//    balance();
}

template<class T>
void Tree<T>::balance(Tree::Node *node) {

}
