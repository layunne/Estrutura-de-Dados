#ifndef TREE_HPP
#define TREE_HPP

#include "ListArray.h"
#include "Node.h"

#include <QString>

class Tree
{
private:
    Node* root;
    ListArray list;
    QString* codeNode;
    QString codeTree;


public:
    Tree();
};

#endif // TREE_HPP
