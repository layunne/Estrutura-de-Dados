#ifndef NODE_H
#define NODE_H

template <typename E>
class Node {

public:
    Node(E content) {
        this->content = content;
        this->next = 0;
    }
    E content;
    Node *next;
};

#endif // NODE_H
