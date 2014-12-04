#include "Node.h"
#include "HandleFile.h"
#include "list.h"
#include "Tree.h"
#include "ByteArray.h"
#include <iostream>
#include <QDebug>
#include <fstream>
#include <stdlib.h>
#include <QList>
#include <QBitArray>
#include <QByteArray>
#include <string>


using namespace std;

int main(int argc, char* argv[])
{
    qDebug()<<"COMEÇO";
    HandleFile file;
    file.SetIO(argv[1], argv[1]);
    List *list = new List();
    file.openFile();
    file.count(list);

    Tree tree;
    tree.buildTree(list);
//    tree.showTree(tree.getRoot());
    tree.encoding(tree.getRoot());
//    tree.codeTree(tree.getRoot());
    tree.showCodeLeaf(tree.getRoot());
//    tree.showListNodes();
    file.codeBody(tree.listNodes());
    qDebug()<<"FIM";

    return 0;
}
