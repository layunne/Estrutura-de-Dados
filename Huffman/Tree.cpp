#include "Tree.h"
#include "HandleFile.h"
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QPair>


Tree::Tree()
{
    _root = NULL;
    _listLeaf = new QString[256];
    size = 0;
}
void Tree::buildTree(List &list)
{
    while(list.size() > 1) {
        list.sort();
        Node *node = new Node(false, 0, 0);
        node->setWeight(list.getValue(0)->getWeight() + list.getValue(1)->getWeight());
        node->setChilds(list.remove(0),list.remove(1));
        list.append(node);
    }
    _root = list.getBegin();
}

void Tree::rebuildTree(Node *base)
{
    bool verificador = true;
    if(!_codeTree.size()) return;

    if(_codeTree.at(0) == '#') {
        _codeTree.remove(0,1);
        verificador = false;

    }

    if(_codeTree.at(0) == '('  && verificador) {
        _codeTree.remove(0,1);
        base->setIsLeaf(false);
        base->setChilds(new Node(), new Node());
        base->getLeftChild()->setCode(base->getCode() + "0");
        base->getRightChild()->setCode(base->getCode() + "1");
        rebuildTree(base->getLeftChild());
        rebuildTree(base->getRightChild());
    } else {
        base->setIsLeaf(true);
        base->setContent(_codeTree.at(0));
        _listLeaf[base->getContent()] = base->getCode();
        _codeTree.remove(0,1);
        return;
    }
}
QPair<unsigned char, bool> Tree::searchLeaf(QString codeLeaf, Node *base)
{
    if(!base->isLeaf()) {
        if(codeLeaf.at(0) == '0') {
            if(codeLeaf.size()>1) codeLeaf.remove(0,1);
            else codeLeaf[0] = '2';
            return searchLeaf(codeLeaf, base->getLeftChild());
        }
        else if(codeLeaf.at(0) == '1') {
            if(codeLeaf.size()>1) codeLeaf.remove(0,1);
            else codeLeaf[0] = '2';
            return searchLeaf(codeLeaf, base->getRightChild());
        } else {

            return QPair<unsigned char, bool> (base->getContent(),false);
        }
    }
    return QPair<unsigned char, bool> (base->getContent(),base->isLeaf());
}

void Tree::showCodeTree()
{
   qDebug() << _codeTree;
}
QByteArray Tree::getcodeTree()
{
    return _codeTree;
}

QString *Tree::listNodes()
{
    return _listLeaf;
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
    if(!base->isLeaf() && base != _root) {
        _codeTree += "(";

    }
    else if(base->isLeaf()) {
        if(base->getContent() == '(' || base->getContent() == '#') _codeTree += '#';
        _codeTree += base->getContent();
    }

    // Gerando uma lista das Folhas
    if(base->isLeaf()) {
        _listLeaf[base->getContent()] = base->getCode();
        ++size;
    }
    encoding(n1);
    encoding(n2);
}

void Tree::setRoot(Node *root)
{
    _root = root;
}


Node *Tree::getRoot()
{
    return _root;
}

void Tree::setCodeTree(QByteArray codeTree)
{
    _codeTree = codeTree;
}

void Tree::showCodeLeaf(Node *base)
{
    if(base == NULL) return;

    if(base->isLeaf()) {
        qDebug() << base->getCode() << "="
                 << (char) base->getContent();
    }
    showCodeLeaf(base->getLeftChild());
    showCodeLeaf(base->getRightChild());
}

void Tree::showListNodes()
{
   for(int i = 0; i < 256; ++i) {
       if(_listLeaf[i] != "")qDebug() << _listLeaf[i]
                                       <<  (char)i;
   }
}

void Tree::showTree(Node *base)
{
    if(base == NULL) return;

    if(base->isLeaf()) {
        qDebug() << "Leaf:" << base->getWeight() << "SEM PESO"
                 << (char)base->getContent()
                 << hex << base->getContent();
    } else {
        qDebug() << "Node:" << base->getWeight() << "SEM PESO";
    }
    showTree(base->getLeftChild());
    showTree(base->getRightChild());
}


