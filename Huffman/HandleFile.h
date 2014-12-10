#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "Node.h"
#include "list.h"
#include "auxiliar.h"
#include "ByteArray.h"

#include <QList>
#include <QString>
#include <fstream>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <iostream>

#define DEBUG 1
//#define DEBUGOUT(mensagem) if(DEBUG)std::cout << mensagem << "\n";
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;

class HandleFile
{
private:
    QByteArray _buffer;          // Arquivo de Entrada
    ByteArray _bodyFile;         // Corpo do Arquivo de saída - sem o cabeçalho
    long long int _sizeCode;     // Tamanho do código pré-codificado

public:
    //Construtor
    HandleFile();

    //Destrutor
    ~HandleFile();

    // limpa todos os Atributos
    void clear();

    // Adiciona o Code no Arquivo de saída
    bool buildFileOut(QByteArray code, QString nameOut);

    // Constuir Caleçalho
    void buildHeader();

    // Retorna buffer
    QByteArray getBuffer() const;

    // Abre o arquivo para compactação e conta as ocorrências
    bool openFile(QString in, List &list);

    // Abre o arquivo para descompactação
    bool openFile(QString in);

    // Imprime buffer
    void show() const;

    // Geta o arquivo pré-codificado
    void codeBody(QString *list);

    // Retorna o Corpo do Árquivo
    QByteArray getCodeBody();

    // Tamanho do Código
    long long sizeCode() const;
};

#endif // HANDLEFILE_H
