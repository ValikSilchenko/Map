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
void Tree<T>::del(const T &elem) {
    Node *temp = root;
    while (temp != nullptr) {
        if (temp->data == elem)
            break;
        else
            temp = elem < temp->data ? temp->left : temp->right;
    }

    if (temp != nullptr) {
        Tree::Color colorOfDeletable;
        Node* toDel;
        if (temp->right == nullptr || temp->left == nullptr) {
            toDel = temp;
            temp = temp->right != nullptr ? temp->right : temp->left;
            if (toDel == root)
                root = temp;
            else if (toDel->parent->right == toDel)
                toDel->parent->right = temp;
            else
                toDel->parent->left = temp;

            if (temp != nullptr)
                temp->parent = toDel->parent;
        } else {
            toDel = temp->right;
            while (toDel->left != nullptr)
                toDel = toDel->left;
            temp->data = toDel->data;

            if (toDel->parent == temp)
                temp->right = toDel->right;
            else
                toDel->parent->left = toDel->right;
            temp = toDel->right;

            if (toDel->right != nullptr)
                toDel->right->parent = toDel->parent;
        }

        colorOfDeletable = toDel->color;
        delete toDel;

        if (colorOfDeletable == Tree::BLACK) {
            balanceAfterDel(temp);
        }
    }
}

template<class T>
void Tree<T>::balanceAfterDel(Tree::Node *node) {
    if (node != nullptr) {
        if (node == root || node->color == Tree::RED)
            node->color = Tree::BLACK;
        else {
            Node* brother;
            bool isLeft;
            if (node->parent->right == node) {
                brother = node->parent->left;
                isLeft = false;
            } else {
                brother = node->parent->right;
                isLeft = true;
            }

            if (brother->color == Tree::BLACK) {
                Tree::Color leftChildColor, rightChildColor;

                leftChildColor = brother->left != nullptr ? brother->left->color : Tree::BLACK;
                rightChildColor = brother->right != nullptr ? brother->right->color : Tree::BLACK;

                if (rightChildColor == Tree::RED && isLeft || leftChildColor == Tree::RED && !isLeft) {
                    brother->color = node->parent->color;
                    node->parent->color = Tree::BLACK;
                    if (isLeft) {
                        brother->right->color = Tree::BLACK;
                        turnLeft(node->parent);
                    } else {
                        brother->left->color = Tree::BLACK;
                        turnRight(node->parent);
                    }
                } else if (leftChildColor == Tree::RED && isLeft || rightChildColor == Tree::RED && !isLeft) {
                    if (isLeft) {
                        brother->left->color = Tree::BLACK;
                        turnRight(brother);
                    } else {
                        brother->right->color = Tree::BLACK;
                        turnLeft(brother);
                    }
                    brother->color = Tree::RED;
                    balanceAfterDel(node);
                } else {
                    if (node->parent->color == Tree::RED) {
                        node->color = Tree::BLACK;
                        brother->color = Tree::RED;
                    } else {
                        brother->color = Tree::RED;
                        balanceAfterDel(node->parent);
                    }
                }
            } else {
                brother->color = Tree::BLACK;
                node->parent->color = Tree::RED;
                if (isLeft)
                    turnLeft(node->parent);
                else
                    turnRight(node->parent);
                balanceAfterDel(node);
            }
        }
    }
}

template<class T>
void Tree<T>::add(const T &elem) {
    if (root == nullptr)
        root = new Node(elem, BLACK);
    else {
        Node *temp = root;
        while (true) {
            if (elem < temp->data) {  // left branch
                if (temp->left != nullptr)
                    temp = temp->left;
                else {
                    temp->left = new Node(elem, temp);
                    temp = temp->left;
                    break;
                }
            } else if (temp->data < elem) {  // right branch
                if (temp->right != nullptr)
                    temp = temp->right;
                else {
                    temp->right = new Node(elem, temp);
                    temp = temp->right;
                    break;
                }
            } else
                break;
        }
        balanceAfterAdd(temp);
    }
}

template<class T>
void Tree<T>::balanceAfterAdd(Tree::Node *node) {
    if (node->parent->color == Tree::RED) {
        Node *uncle;
        Tree::Color uncleColor;
        bool leftLine;

        if (node->parent == node->parent->parent->right) {
            uncle = node->parent->parent->left;
            leftLine = false;
        } else {
            uncle = node->parent->parent->right;
            leftLine = true;
        }

        if (uncle != nullptr)
            uncleColor = uncle->color;
        else
            uncleColor = Tree::BLACK;

        if (uncleColor == Tree::RED) {
            uncle->color = Tree::BLACK;
            node->parent->color = Tree::BLACK;
            node->parent->parent->color = Tree::RED;
            if (node->parent->parent == root)
                root->color = Tree::BLACK;
            else
                balanceAfterAdd(node->parent->parent);
        } else {
            if (node == node->parent->right && leftLine || node == node->parent->left && !leftLine) {
                node = node->parent;
                if (leftLine)
                    turnLeft(node);
                else
                    turnRight(node);
            }
            node->parent->color = Tree::BLACK;
            node->parent->parent->color = Tree::RED;
            if (leftLine)
                turnRight(node->parent->parent);
            else
                turnLeft(node->parent->parent);
        }
    }
}
