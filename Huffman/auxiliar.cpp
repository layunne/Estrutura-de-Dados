#include "auxiliar.h"
#include "ByteArray.h"
#include <QByteArray>
#include <QDebug>
QByteArray decToByte(int sizeTrash, int sizeTree){
    ByteArray code;
    int temp;
    temp = sizeTree/(0x1 << 8);
    code.setByte(0,temp);
    temp = sizeTree%(0x1 << 8);
    code.setByte(1,temp);
    qDebug() << hex << temp << "TEMP";


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
