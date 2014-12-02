#include "Node.h"

Node::Node(){
    left = 0;
    right = 0;
    parent = 0;
}
Node::Node(int  w, unsigned char c){
    left = 0;
    right = 0;
    weight = w;
    content = c;
}
unsigned char Node::getContent(){
    return content;
}
int Node::getWeight(){
    return weight;
}
Node* Node::getLeftChild(){
    return left;
}
void Node::setLeftChild(Node* l){
    right = l;
}
void Node::setRightChild(Node* r){
    right = r;
}
