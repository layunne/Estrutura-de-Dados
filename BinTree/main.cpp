#include <QDebug>
#include "tree.h"
#include "Node.h"

int main()
{
    qDebug() << "-----COMEÇO-----";
    Tree<int> t;
    t.add(50);
    t.add(30);
    t.add(70);
    t.add(20);
    t.add(40);
    t.add(60);
    t.add(80);
    t.add(15);
    t.add(25);
    t.add(35);
    t.add(45);
    t.add(55);
    t.add(65);
    t.add(75);
    t.add(85);
    t.add(99);
//    t.add(45);
//    t.add(37);
    qDebug() <<t.toString();
//    t.add(8);
//    t.add(0);
//    t.add(1115);
//    t.add(1120);
//    t.add(1112);

////    t.clear();
//    t.show();
//    qDebug() << t.greater() << "greater";
//    qDebug() << t.lower() << "lower";
//    qDebug() << t.countNode() << "countNode";
//    qDebug() << t.height() << "height";
//    qDebug() << t.countLeaf() << "countLeaf";
//    qDebug() << t.getTree()->content << "getTree";
//    t.toRight();
//    t.toRight();
//    t.toRight();
//    t.toLeft();
//    qDebug() << t.countLevel() << t.getHere() << "countLevel";



//    t.remove(90);
//    t.show();
//    t.remove(30);
//    t.show();


    qDebug() << "-----FIM-----";
    return 0;
}
