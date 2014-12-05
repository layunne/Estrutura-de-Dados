#include "Node.h"
#include "HandleFile.h"
#include "list.h"
#include "Tree.h"
#include "ByteArray.h"
#include "auxiliar.h"
#include <iostream>
#include <QDebug>
#include <fstream>
#include <stdlib.h>
#include <QList>
#include <QByteArray>
#include <string>
#include <QFile>


using namespace std;

int main(int argc, char* argv[])
{
    qDebug()<<"------COMEÇO-----";

    // MAnipula o Arquivo
    HandleFile file;
    // Lista que Contém os Nós que fomaram a Árvore de Huffman
    List list;
    // Árvore de Hufman
    Tree tree;
    // Binários do Arquivo de Saída
    QByteArray codeFile;

    int sizeTrash;
    int sizeTree;
//    int sizeName;

    file.SetIO(argv[1], "EU AQUI.txt");
    file.openFile(list);
    tree.buildTree(list);
    tree.encoding(tree.getRoot());
    file.codeBody(tree.listNodes());

    sizeTrash = 8-((file.sizeCode())%8);
    if(sizeTrash == 8) sizeTrash = 0;
    else if(sizeTrash > 8) qDebug() << "DEU ERRO";
    sizeTree = tree.getcodeTree().size();


    codeFile += decToByte(sizeTrash,sizeTree);
    codeFile += file.getCodeBody();


    file.appendFileOut(codeFile);
//    file.appendFileOut(file.getCodeBody());

    qDebug() << tree.getcodeTree();
    qDebug() << sizeTrash
             << sizeTree;

    qDebug()<<"-------FIM-------";

    return 0;
}
