#include "auxiliar.h"
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

QByteArray decToByte(int sizeTrash, int sizeTree){
    ByteArray code;
    int temp;
    temp = sizeTree/(0x1 << 8);
    code.setByte(0,temp);
    temp = sizeTree%(0x1 << 8);
    code.setByte(1,temp);

    switch (sizeTrash) {
    case 1:
        code.setBit(2,1);
        break;
    case 2:
        code.setBit(1,1);
    case 3:
        code.setBit(1,1);
        code.setBit(2,1);
        break;
    case 4:
        code.setBit(0,1);
    case 5:
        code.setBit(0,1);
        code.setBit(2,1);
        break;
    case 6:
        code.setBit(0,1);
        code.setBit(1,1);
    case 7:
        code.setBit(0,1);
        code.setBit(1,1);
        code.setBit(2,1);
        break;
    }
    return code.getByteArray();
}


void zip(QString nameIn, QString nameOut)
{
    qDebug() << "INICIANDO COMPACTAÇÃO";
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

    file.openFile(list, nameIn);
    tree.buildTree(list);
    tree.encoding(tree.getRoot());
    file.codeBody(tree.listNodes());

    sizeTrash = 8-((file.sizeCode())%8);
    if(sizeTrash == 8) sizeTrash = 0;
    else if(sizeTrash > 8) qDebug() << "DEU ERRO";

    sizeTree = tree.getcodeTree().size();
    codeFile += decToByte(sizeTrash,sizeTree);
    codeFile += nameIn.size();
    codeFile += nameIn;
    codeFile += tree.getcodeTree();
    codeFile += file.getCodeBody();
    file.buildFileOut(codeFile, nameOut);
    qDebug() << "TERMINANDO COMPACTAÇÃO";
}


void unzip(QString nameIn, QString nameOut)
{
    qDebug() << "NÃO IMPLEMENTOU UNZIP";
}
