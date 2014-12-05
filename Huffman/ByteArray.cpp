#include "ByteArray.h"
#include <QByteArray>
#include <QDebug>


ByteArray::ByteArray()
{

}

void ByteArray::appendByte(char byte)
{
    byteArray.append(byte);
}

char ByteArray::getByte(int i)
{
    return byteArray.at(i);
}

QByteArray ByteArray::getByteArray()
{
    return byteArray;
}

void ByteArray::setBit(long long int iBit, bool bit)
{
    long long int iByte = iBit/8;
    if(iByte > byteArray.size()-1) byteArray.append((char)0);

    char byte = byteArray.at(iByte);

    byteArray.remove(iByte, 1);

    char mask = 0x1;
    mask = mask << (7 - iBit%8);

    if(bit){
        byte = byte | mask;
    } else {
        mask = 0xFF ^ mask;
        byte = byte & mask;
    }
    byteArray.insert(iByte, (char)byte);
}

void ByteArray::setByte(long long int i, char byte)
{
    byteArray.remove(i, 1);
    byteArray.insert(i, (char)byte);
}
void ByteArray::setByte(long long int i, QByteArray byte)
{
    byteArray.remove(i, 1);
    byteArray.insert(i, byte);
}


int ByteArray::size()
{
    return byteArray.length();
}

