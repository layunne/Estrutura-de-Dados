#ifndef NODE_HPP
#define NODE_HPP

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
#endif // NODE_HPP
