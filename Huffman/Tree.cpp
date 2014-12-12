#include "Tree.h"




QList<QString> &Tree::getListLeaf()
{
    return _listLeaf;
}

void Tree::setListLeaf(QList<QString> &listLeaf)
{
    _listLeaf = listLeaf;
}
Tree::Tree()
{
    _root = NULL;
    listLeafAlloc();
}

Tree::~Tree()
{
    clear();
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

void Tree::clear()
{
    _codeTree.clear();
    _listLeaf.clear();
}

void Tree::clearTree(Node *base)
{
    if(base == NULL) return;

    clearTree(base->getLeftChild());
    clearTree(base->getRightChild());
    if(base->isLeaf()) {
        delete(base);
    }

}

void Tree::rebuildTree(Node *base)
{
    bool verificador = true;
    if(!_codeTree.size()) return;

    if(_codeTree.at(0) == 0x23) {
        _codeTree.remove(0,1);
        verificador = false;

    }

    if(_codeTree.at(0) == 0x28  && verificador) {
        _codeTree.remove(0,1);
        base->setIsLeaf(false);
        base->setChilds(new Node(), new Node());
        base->getLeftChild()->setCode(base->getCode() + '0');
        base->getRightChild()->setCode(base->getCode() + '1');
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

QByteArray *Tree::searchLeaf(QByteArray *code, int iBit, int sizeTrash, Node *base, Node *root, QByteArray *codeFile)
{
    if(base->isLeaf()) {
//        qDebug() << (char)base->getContent();
        codeFile->append((unsigned char)base->getContent());
        return searchLeaf(code, iBit, sizeTrash, root, root, codeFile);
    }
    else {
        ByteArray byte;
        if(iBit == 8) {
            code->remove(0, 1);
            iBit = 0;
        }
        if(!code->size() || (code->size() == 1 && sizeTrash && 8 - sizeTrash <= iBit)) return codeFile;
        byte.appendByte(code->at(0));
        if(byte.getBit(iBit)) {
            return searchLeaf(code, ++iBit, sizeTrash, base->getRightChild(), root, codeFile);
        }
        else {
            return searchLeaf(code, ++iBit, sizeTrash, base->getLeftChild(), root, codeFile);
        }
    }
    return codeFile;
}



void Tree::showCodeTree()
{
    qDebug() <<_codeTree;
}

void Tree::listLeafAlloc()
{
    _listLeaf.clear();
    for(int i = 0; i < 256; ++i){
        _listLeaf.append(0);
    }
}
QByteArray Tree::getcodeTree()
{
    return _codeTree;
}

QList<QString> &Tree::listNodes()
{
    return _listLeaf;
}

void Tree::encoding(Node *base)
{
    if(base == NULL) return;

    QString codeBase = base->getCode();
    Node *n1 = base->getLeftChild();
    Node *n2 = base->getRightChild();

    // Codificando os Nós - Esqueda 0, direita 1
    if(n1) n1->setCode(codeBase + '0');
    if(n2) n2->setCode(codeBase + '1');

    // Construindo Código da Árvore
    if(!base->isLeaf() && base != _root) {
        _codeTree += "(";
    }
    else if(base->isLeaf()) {
        if(base->getContent() == 0x28 || base->getContent() == 0x23) _codeTree += 0x23;
        _codeTree += base->getContent();
    }

    // Gerando a lista das Folhas
    if(base->isLeaf()) {
        _listLeaf[base->getContent()] = base->getCode();
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
        DEBUGOUT (base->getCode() << "="
                 << (char) base->getContent())
    }
    showCodeLeaf(base->getLeftChild());
    showCodeLeaf(base->getRightChild());
}

void Tree::showListNodes()
{
   for(int i = 0; i < 256; ++i) {
       if(_listLeaf[i] != "")DEBUGOUT( _listLeaf[i]
                                       <<  (char)i)
   }
}

void Tree::showTree(Node *base)
{
    if(base == NULL) return;

    if(base->isLeaf()) {
        DEBUGOUT ("Leaf: " << base->getWeight() << "SEM PESO"
                 << (char)base->getContent()
                 << hex << base->getContent())
    } else {
        DEBUGOUT( "Node: " << base->getWeight() << "SEM PESO")
    }
    showTree(base->getLeftChild());
    showTree(base->getRightChild());
}



