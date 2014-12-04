#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include <QByteArray>

class ByteArray
{
private:
    QByteArray byteArray;
public:
    ByteArray();

    // Retorna o char na posição dada
    char getByteArray(int i) const;

    // Set um Bit na posição dada no Byte na posição dada dado
    void setBit(int iByte, int iBit, bool bit = true);

    // Set um Byte na posição dada
    void setByte(int i, char byte);

};

#endif // BYTEARRAY_H
