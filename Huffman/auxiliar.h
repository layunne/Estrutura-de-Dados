#ifndef AUXILIAR_H
#define AUXILIAR_H

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

QByteArray decToByte(int sizeTrash, int sizeTree);

void zip(QString nameIn, QString nameOut);

void unzip(QString nameIn, QString nameOut);


#endif // AUXILIAR_H
