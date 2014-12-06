#include "Tree.h"
#include "HandleFile.h"
#include <QDebug>
#include <QString>
#include <QByteArray>


Tree::Tree()
{
    root = NULL;
    _listNodes = new QString[256];
    size = 0;
}
void Tree::buildTree(List &list)
{
    while(list.size() > 1){
        list.sort();
        Node *node = new Node(false, 0, 0);
        node->setWeight(list.getValue(0)->getWeight() + list.getValue(1)->getWeight());
        node->setChilds(list.remove(0),list.remove(1));
        list.append(node);
    }
    root = list.getBegin();
}

QByteArray Tree::getcodeTree()
{
    return _codeTree;
}

QString *Tree::listNodes()
{
    return _listNodes;
}

void Tree::encoding(Node *base)
{
    if(base == NULL) return;

    QString codeBase = base->getCode();
    Node *n1 = base->getLeftChild();
    Node *n2 = base->getRightChild();


    // Codificando os Nós
    if(n1) n1->setCode(codeBase + '0');
    if(n2) n2->setCode(codeBase + '1');

    // Construindo Código da Árvore
    if(base->isLeaf() == false){
        if(base != root) _codeTree += "(";

    } else {
        _codeTree += base->getContent();
    }

    // Gerando uma lista das Folhas
    if(base->isLeaf()){
        _listNodes[base->getContent()] = base->getCode();
        ++size;
//        if(size==256) {
//            qDebug() << "SIZE NODES =" << size;
//            qDebug() << base->getContent() << base->getCode();
//            for(int i = 0; i < 256; ++i){
//                qDebug() << _listNodes[i];
//            }
//        }
    }
    encoding(n1);
    encoding(n2);
}

Node *Tree::getRoot()
{
    return root;
}

void Tree::showCodeLeaf(Node *base)
{
    if(base == NULL) return;

    if(base->isLeaf()){
        qDebug() << base->getCode() << "="
                 << (char) base->getContent();
    }
    showCodeLeaf(base->getLeftChild());
    showCodeLeaf(base->getRightChild());
}

void Tree::showListNodes()
{
   for(int i = 0; i < 256; ++i){
       if(_listNodes[i] != "")qDebug() << _listNodes[i]
                                       <<  (char)i;
   }
}

void Tree::showTree(Node *base)
{
    if(base == NULL) return;

    if(base->isLeaf()){
        qDebug() << "Leaf:" << base->getWeight()
                 << (char)base->getContent()
                 << hex << base->getContent();
    } else {
        qDebug() << "Node:" << base->getWeight();
    }
    showTree(base->getLeftChild());
    showTree(base->getRightChild());
}

