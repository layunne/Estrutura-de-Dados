#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {

public:
    Node(E content) {
        this->left = 0;
        this->right = 0;
        this->content = content;
    }
    E content;
    Node<E> *left;
    Node<E> *right;

};
#endif // NODE_H
