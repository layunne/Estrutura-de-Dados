#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include <QByteArray>

class ByteArray
{
private:
    QByteArray _byteArray;
public:
    ByteArray();

    // Para ByteArray
    void toByteArray(QByteArray byteArray);
    // Adiciona um Byte na ultima Posição
    void appendByte(char byte);

    // Retorna o char na posição dada
    char getByte(int i);

    //Remover um item
    void remove(int iByte);

    // Retorna o bit na posição dada
    bool getBit(long long int iBit);

    // Restorna todo o byteArray
    QByteArray getByteArray();

    // Insere um Bit na posição dada no Byte na posição dada
    void setBit(long long int iBit, bool bit = true);

    // Insere um Byte na posição dada
    void setByte(long long int i, char byte);
    void setByte(long long int i, QByteArray byte);


    // Retorna o Tamanho
    int size();

    int show(int i);

};

#endif // BYTEARRAY_H
