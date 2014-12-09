#include "Node.h"

#include <QString>

Node::Node()
{
    _left = NULL;
    _right = NULL;
    _isLeaf = true;
}
Node::Node(bool isLeaf,int  weight, unsigned char content)
{
    _left = NULL;
    _right = NULL;
    _weight = weight;
    _content = content;
    _isLeaf = isLeaf;
}

Node::~Node()
{

}

bool Node::isLeaf()
{
    return _isLeaf;
}

QString Node::getCode()
{
    return _code;
}
unsigned char Node::getContent()
{
    return _content;
}

int Node::getWeight()
{
    return _weight;
}

Node *Node::getLeftChild()
{
    return _left;
}
Node *Node::getRightChild()
{
    return _right;
}

void Node::setCode(QString code)
{
    _code += code;
}

void Node::setContent(unsigned char content)
{
    _content = content;
}

void Node::setChilds(Node *left, Node *right)
{
    _left = left;
    _right = right;
}
void Node::setLeftChild(Node *left)
{
    _left = left;
}
void Node::setRightChild(Node *right)
{
    _right = right;
}
void Node::setWeight(int weight)
{
    _weight = weight;
}

void Node::setIsLeaf(bool isLeaf)
{
    _isLeaf = isLeaf;
}
