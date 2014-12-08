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

QByteArray decToByte(int sizeTrash, int sizeTree);

int byteToDec(QByteArray code);
QPair<int, int> byteToDecPair(QByteArray code);

void zip(QString nameIn, QString nameOut);

void unzip(QString nameIn, QString out = NULL);

void help(int i = 0);


#endif // AUXILIAR_H
