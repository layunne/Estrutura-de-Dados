#include "list.h"

using std::cout;

List::List()
{

}

List::~List()
{
    clear();
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

Node *List::getValue(int pos)
{
    return list.value(pos);
}

int List::size()
{
    return list.size();
}

Node *List::remove(int pos)
{
    Node *temp = list.value(pos);
    list.removeAt(pos);
    return temp;
}

void List::show()
{
    DEBUGOUT("---------showList begin-------------")
    for(int i = 0; i < list.length(); ++i) {
        if(list.value(i)->isLeaf() == true) {
            DEBUGOUT ( i
                     << list.value(i)->getWeight()
                     << (char)list.value(i)->getContent()
                     << hex << list.value(i)->getContent())
        } else {
            DEBUGOUT(i
                     << list.value(i)->getWeight())
        }

    }
    DEBUGOUT("---------showList end---------------")
}

void List::showTree(Node *base)
{
    if(base == NULL) return;


    if(base->isLeaf()) {
        DEBUGOUT ("Leaf: " << base->getWeight()
                 << (char)base->getContent()
                 << hex << base->getContent())
    } else {
        DEBUGOUT( "Node: " << base->getWeight())
    }
    showTree(base->getLeftChild());
    showTree(base->getRightChild());
}

void List::reserve(int alloc)
{
    list.reserve(alloc);
}

bool caseInsensitiveLessThan(Node* &n1, Node* &n2)
{
    if(n1->getWeight() == n2->getWeight()) {
//        if(!(n1->isLeaf()) && !(n2->isLeaf())) {
//            Node *temp1 = n1->getLeftChild();
//            Node *temp2 = n2->getRightChild();
//            if(temp1->isLeaf() != temp2->isLeaf()) return true;
//            qDebug() << "EU";
//            return caseInsensitiveLessThan(temp1,temp2);
//        }
        return n1->getContent() < n2->getContent();
    }
    return n1->getWeight() < n2->getWeight();
}

void List::sort()
{
    qSort(list.begin(), list.end(), caseInsensitiveLessThan);
}

