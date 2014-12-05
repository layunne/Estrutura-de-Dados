#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "Node.h"
#include "list.h"
#include "ByteArray.h"
#include <fstream>
#include <QList>
#include <QBitArray>

using std::ifstream;
using std::ofstream;
class HandleFile
{
private:
    QByteArray buffer;
    long long int _sizeCode;
    char *_pathIn;
    char *_pathOut;
    ByteArray _bodyFile;
    ifstream fileIn;
    ofstream fileOut;


public:
    //Construtor
    HandleFile();

    //Destrutor
    ~HandleFile();

    // Adiciona o Code no Arquivo de saída
    void appendFileOut(QByteArray code);

    // Constuir Caleçalho
    void buildHeader();

    // Retorna buffer
    QByteArray getBuffer() const;

    // Abre o arquivo e conta as Ocorrências
    void openFile(List &list);

    // Seta a Entrada e Saida
    void SetIO(char *pathIn, char *pathOut);

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
