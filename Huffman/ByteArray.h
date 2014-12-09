#ifndef BYTEARRAY_H
#define BYTEARRAY_H

#include <QByteArray>
#include <QDebug>
#include <iostream>

#define DEBUG 1
//#define DEBUGOUT(mensagem) if(DEBUG)std::cout << mensagem << "\n";
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;
using std::cout;

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

};

#endif // BYTEARRAY_H
