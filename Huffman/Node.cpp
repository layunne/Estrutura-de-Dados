#include "Node.h"
#include <QDebug>
#include <QString>

Node::Node()
{
    _left = NULL;
    _right = NULL;
    _dad = NULL;
    _isLeaf = true;
}
Node::Node(bool isLeaf,int  weight, unsigned char content)
{
    _left = NULL;
    _right = NULL;
    _dad = NULL;
    _weight = weight;
    _content = content;
    _isLeaf = isLeaf;
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

Node *Node::getDad()
{
    return _dad;
}
int Node::getWeight()
{
    return _weight;
}

void Node::setDad(Node *dad)
{
    _dad = dad;
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
