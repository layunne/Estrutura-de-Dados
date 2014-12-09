#include "ByteArray.h"

ByteArray::ByteArray()
{
    _byteArray = NULL;
}
void ByteArray::toByteArray(QByteArray byteArray)
{
    _byteArray = byteArray;
}

void ByteArray::appendByte(char byte)
{
    _byteArray.append(byte);
}

char ByteArray::getByte(int i)
{
    return _byteArray.at(i);
}

void ByteArray::remove(int iByte)
{
    _byteArray.remove(iByte,1);
}

bool ByteArray::getBit(long long int iBit)
{
    long long int iByte = iBit/8;
    if(iByte > _byteArray.size() || iBit < 0) {
       qDebug() << "índice Errado\n";
        exit(1);
    }

    char byte = _byteArray.at(iByte);
    char mask = 0x1;
    mask = mask << (7 - iBit%8);
    byte = byte & mask;

    if(byte) return true;
    else return false;
}

QByteArray ByteArray::getByteArray()
{
    return _byteArray;
}

void ByteArray::setBit(long long int iBit, bool bit)
{
    long long int iByte = iBit/8;
    if(iByte > _byteArray.size()-1) {
        _byteArray.append((char)0);
    }
    char byte = _byteArray.at(iByte);

    _byteArray.remove(iByte, 1);

    char mask = 0x1;
    mask = mask << (7 - iBit%8);

    if(bit) {
        byte = byte | mask;
    } else {
        mask = 0xFF ^ mask;
        byte = byte & mask;
    }
    _byteArray.insert(iByte, (char)byte);
}

void ByteArray::setByte(long long int i, char byte)
{
    _byteArray.remove(i, 1);
    _byteArray.insert(i, (char)byte);
}
void ByteArray::setByte(long long int i, QByteArray byte)
{
    _byteArray.remove(i, 1);
    _byteArray.insert(i, byte);
}


int ByteArray::size()
{
    return _byteArray.length();
}
