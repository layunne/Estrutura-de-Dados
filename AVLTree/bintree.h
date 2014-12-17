#ifndef BINTREE_H
#define BINTREE_H

#include "treeADT.h"
#include "node.h"
#include <QString>
#include <QDebug>
#include <QObject>


template <typename E>
class Tree : public BinTree<E> {

    Node<E> *_root;
    Node<E> *_curr;


    void reset() {
        _root = NULL;
        _curr = NULL;
    }
    void show(Node<E> *base, QString &tree) {
        if(base == 0) return;
        tree += "(";
        tree += QString::number(base->content);
        show(base->left, tree);
        show(base->right, tree);
        tree += ")";
    }
    void add(Node<E> *&base, const E& item) {
        if(base == 0) {
            base = new Node<E>(item);
        }
        else if(base->content > item) {
            add(base->left, item);
        }
        else {
            add(base->right, item);
        }
    }
    void clear(Node<E> *& base){
        if(base == 0) return;
        clear(base->left);
        clear(base->right);
        delete base;
    }
    Node<E> *remove2(const E item) {
        Node<E> *base = _root;
        Node<E> *pai;
        if(base->content == item) {

        }

        while(base && base->content != item) {
            pai = base;
            if(item < base->content) {
                base = base->left;
            }
            else {
                base = base->right;
            }
        }
        if(base == 0) {
            qDebug() << "O item não está presente na Árvore";
            return 0;
        }
        else {
            // Remoção de Folha
            if(base->left == 0 && base->right == 0) {
                if(base == pai->left) {
                    pai->left = NULL;
                }
                else {
                    pai->right = NULL;
                }
            }
            // Remoção de Nó com dois filhos
            else if(base->left && base->right) {
                Node<E> *temp1 = maisEsquerda(base->right);
                Node<E> *temp2 = maisDireita(base->left);
                Node<E> *aux;
                if(countLevel(_root, temp2) > countLevel(_root, temp1)){
                    temp1 = temp2;
                }
                aux = temp1;
                remove2(temp1->content);

                if(base == pai->left){
                    pai->left = aux;
                }
                else {
                    pai->right = aux;
                }
                aux->left = base->left;
                aux->right = base->right;
            }
            // Remoção de Nó com 1 filhos
            else {
                if(base == pai->left) {
                    if(base->left) {
                        pai->left = base->left;
                    }
                    else {
                        pai->left = base->right;
                    }
                }
                else {
                    if(base->left) {
                        pai->right = base->left;
                    }
                    else {
                        pai->right = base->right;
                    }
                }
            }
        }
        return base;
    }
    bool isRight(Node<E> *base, Node<E> *node) {
        if(base == 0) return false;
        if(base == node) return true;
        return isRight(base->right, node);
    }
    Node<E> *maisEsquerda(Node<E> *base){
        while(base->left) {
            base = base->left;
        }
        return base;
    }
    Node<E> *maisDireita(Node<E> *base){
        while(base->right) {
            base = base->right;
        }
        return base;
    }
    int countNode(Node<E> *base) const {
        if(base == 0) return 1;
        return countNode(base->left) + countNode(base->right);
    }
    int height(Node<E> *base) const {
        if(base == 0) return 0;
        return 1 + qMax<E>(height(base->left), height(base->right));
    }
    int countLeaf(Node<E> *base) const {
        if(base == 0) return 0;

        if(base->left == 0 && base->right == 0) {
            return 1;
        }
        return countLeaf(base->left) + countLeaf(base->right);
    }
    const Node<E> *getTree() {
        return _root;
    }
    int countLevel(Node<E> *base, Node<E> *curr) const {
        if(base == curr) return 0;
        if(curr->content < base->content ) {
            return 1 + countLevel(base->left, curr);
        }
        else return 1 + countLevel(base->right, curr);
        return 1 + countLevel(base, curr);
    }
public:

    Tree() {
        reset();
    }

    ~Tree() {
        reset();
    }

    void clear() {
        clear(_root);
        reset();
    }

    void remove(const E item){
        delete(remove2(item));
    }
    void add(const E& item) {
        if(_root == 0) {
            _root = new Node<E>(item);
            _curr = _root;
        }

        else add(_root, item);

    }
    const E lower() {
        Q_ASSERT_X(_root != 0, "Tree::greater", "Empty Tree");
        Node<E> *base = _root;
        while(base->left) {
            base = base->left;
        }
        return base->content;
    }
    const E greater() {
        Q_ASSERT_X(_root != 0, "Tree::greater", "Empty Tree");
        Node<E> *base = _root;
        while(base->right) {
            base = base->right;
        }
        return base->content;
    }
    int countNode() const {
        return countNode(_root) - 1;
    }
    int countLevel() const {
        return countLevel(_root, _curr);
    }

    int height() const {
        return height(_root);
    }
    int countLeaf() const {
        return countLeaf(_root);
    }

    void toLeft() {
        if(_curr->left) {
            _curr = _curr->left;
        }
    }
    void toRight() {
        if(_curr->right) {
            _curr = _curr->right;
        }
    }
    const E getHere() const {
        return _curr->content;
    }
    bool inTree(const E item) {
        return searchNode(_root, item);
    }
    Node<E> *searchNode(Node<E> *base, const E item) {
        if(base == 0) return 0;
        if(base->content == item) return base;
        if(item < base->content) {
            return searchNode(base->left, item);
        }
        else {
            return searchNode(base->right, item);
        }
        return 0;
    }
    QString toString() {
        int height = 0;
        QString str;
        str +="\n";
        int numberSpace = this->height()+1;

        while(height < this->height()){
            str += QString(" ").repeated((1 << (numberSpace-1))-2);
            toString(_root, str, height, numberSpace--);
            str +="\n";
            ++height;
        }
        return str;
    }
    void toString(Node<E> *base, QString &str, int height, int numberSpace) {
        if(base == 0) {
            str += "xx";
        }
        if(!height) {
            if(base) str += QString::number(base->content);
            if(!isRight(_root, base)) str += QString(" ").repeated((1 << numberSpace)-2);
            return;
        }
        if(base) toString(base->left, str, height-1, numberSpace);
        if(base) toString(base->right, str, height-1, numberSpace);
        if(base == 0) toString(base, str, height-1, numberSpace);
        return;
    }

    void addSubTree(Node<E> *&node){
        if(_root == 0) {
            _root = node;
        }
    }

    void show() {
        qDebug() << "-----SHOW-----";
        QString tree;
        show(_root, tree);
        qDebug() << tree;
        qDebug() << "-----SHOW-----";
    }
};
#endif // BINTREE_H
