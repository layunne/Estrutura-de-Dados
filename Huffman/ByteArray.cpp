#include "ByteArray.h"
#include <QByteArray>
#include <math.h>


ByteArray::ByteArray()
{
}

char ByteArray::getByteArray(int i) const
{
    return byteArray.at(i);
}

void ByteArray::setBit(int iByte, int iBit, bool bit)
{

    char byte = byteArray.at(iByte);
    byteArray.remove(iByte, 1);

    if(bit){
        char temp = (int)(pow(2, iBit));
        byte = byte | temp;
    } else {
        char temp = 255 - (int)(pow(2,iBit));
        byte = byte & temp;
    }
    byteArray.insert(iByte, byte);
}

void ByteArray::setByte(int i, char byte)
{
    byteArray.insert(i, byte);
}

