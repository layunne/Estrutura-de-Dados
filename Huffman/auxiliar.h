#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "Node.h"
#include "HandleFile.h"
#include "list.h"
#include "Tree.h"
#include "ByteArray.h"

#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QPair>
#include <iostream>

#define DEBUG 1
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;
using std::cout;

// Codifica os dois primeiros Bytes do arquivo .huff
QByteArray decToByte(int sizeTrash, int sizeTree);

// de Byte para Decimal
int byteToDec(QByteArray code);

// Decodifica os dois primeiros Bytes do arquivo .huff
QPair<int, int> byteToDecPair(QByteArray code);

// Compreção
void zip(QString nameIn, QString nameOut);

// Decompreção
void unzip(QString nameIn, QString out = NULL);

// Ajuda
void help(int i = 0);


#endif // AUXILIAR_H
