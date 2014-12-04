#include "list.h"
#include "Node.h"
#include <QList>
#include <QDebug>
#include <stdlib.h>

List::List()
{
    curr = 0;
}
void List::append(Node *node)
{
    list.append(node);
}

void List::clear()
{
    list.clear();
}

Node *List::getBegin()
{
    return list.first();
}

Node *List::getLast()
{
    return list.last();
}

void List::insert(Node *node)
{
    list.insert(curr, node);

}

Node *List::getValue(int pos)
{
    return list.value(pos);
}

int List::length()
{
    return list.length();
}

void List::moveToEnd()
{
    curr = list.length() -1;
}

void List::moveToPos(const int pos)
{
    curr = pos;
}

void List::moveToStart()
{
    curr = 0;
}

void List::next()
{
    if((int)curr < (list.length() -1)) ++curr;
}

void List::prev()
{
    if(curr > 0) --curr;
}

Node *List::remove(int pos)
{
    Node *temp = list.value(pos);
    list.removeAt(pos);
    return temp;
}

void List::show()
{
    qDebug() << "---------showList begin-------------";
    for(int i = 0; i < list.length(); ++i){
        if(list.value(i)->isLeaf() == true){
            qDebug() << i
                     << list.value(i)->getWeight()
                     << (char)list.value(i)->getContent()
                     << hex << list.value(i)->getContent();
        } else {
            qDebug() << i
                     << list.value(i)->getWeight();
        }

    }
    qDebug() << "---------showList end---------------";
}

void List::showTree(Node *base)
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

bool caseInsensitiveLessThan(Node* &n1, Node* &n2)
{
    if(n1->getWeight() == n2->getWeight()){
        if(!(n1->isLeaf()) && !(n2->isLeaf())){
            Node *temp1 = n1->getLeftChild();
            Node *temp2 = n2->getLeftChild();
            if(temp1->isLeaf() != temp2->isLeaf()) return true;
            return caseInsensitiveLessThan(temp1,temp2);
        }
        return n1->getContent() < n2->getContent();
    }
    return n1->getWeight() < n2->getWeight();
}

void List::sort()
{
    qSort(list.begin(), list.end(), caseInsensitiveLessThan);
}

