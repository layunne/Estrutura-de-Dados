#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "Node.h"
#include "list.h"
#include <fstream>
#include <QList>

using std::ifstream;
using std::ofstream;
class HandleFile
{
private:
    char *buffer;
    int lengthB;
    char *_pathIn;
    char *_pathOut;
    QString _bodyFile;
    ifstream fileIn;
    ofstream fileOut;


public:
    //Construtor
    HandleFile();

    //Destrutor
    ~HandleFile();

    // Construir Arquivo de Saída
    void buildFileOut(char code[]);

    // Constuir Caleçalho
    void buildHeader();

    // Conta as Ocorrências
    void count(List *list);

    // Retorna buffer
    char *getBuffer() const;

    // tamanho do buffer
    int getLengthB() const;

    // Abre o arquivo e returna os Bytes
    void openFile();

    // Seta a Entrada e Saida
    void SetIO(char *pathIn, char *pathOut);
    // Imprime buffer
    void show() const;

    // Geta o arquivo pré-codificado
    void codeBody(QString *list);

};

#endif // HANDLEFILE_H
