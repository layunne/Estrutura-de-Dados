#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "Node.h"
#include "list.h"
#include "ByteArray.h"
#include <QList>
#include <QBitArray>
#include <QString>

class HandleFile
{
private:
    QByteArray buffer;
    long long int _sizeCode;
    ByteArray _bodyFile;

public:
    //Construtor
    HandleFile();

    //Destrutor
    ~HandleFile();

    // Adiciona o Code no Arquivo de saída
    void buildFileOut(QByteArray code, QString nameOut);

    // Constuir Caleçalho
    void buildHeader();

    // Retorna buffer
    QByteArray getBuffer() const;

    // Abre o arquivo e conta as Ocorrências
    void openFile(List &list, QString in);

    // Imprime buffer
    void show() const;

    // Geta o arquivo pré-codificado
    void codeBody(QString *list);

    // Retorna o Corpo do Árquivo
    QByteArray getCodeBody();

    long long sizeCode() const;

    void setSizeCode(long long sizeCode);
};

#endif // HANDLEFILE_H
