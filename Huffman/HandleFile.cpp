#include "HandleFile.h"
#include "Node.h"
#include "auxiliar.h"
#include <fstream>
#include <QDebug>
#include <QList>
#include <QFile>
#include <QByteArray>


using std::ifstream;
using namespace std;


HandleFile::HandleFile()
{
    _sizeCode = 0;
}

HandleFile::~HandleFile()
{

}

long long int HandleFile::sizeCode() const
{
    return _sizeCode;
}
void HandleFile::buildFileOut(QByteArray code, QString nameOut)
{
    QFile file(nameOut);
    if (!file.open(QIODevice::WriteOnly)){
        return;
    }
    file.write(code);
    file.close();
    qDebug() << "\nARQUIVO SALVO COM SUCESSO!\n\n";
}

void HandleFile::openFile(QString in, List &list)
{
    // Abre o Arquivo de entrada
    QFile file(in);
    if(!file.open(QIODevice::ReadOnly)){
        help(2);
    }

    // Lê o arquivo de entrada e conta as Ocorrências
    int count[256] = {0};
    while(!file.atEnd()){
        QByteArray line = file.readLine(1024);
        buffer.append(line);
        for(int i = 0; i < line.size(); ++i) {
            ++count[(unsigned char) line.at(i)];
        }
    }
    file.close();
    for(int i = 0; i < 256; ++i) {
        if(count[i]) {
            Node *node = new Node(true, count[i], i);
            list.append(node);
        }
    }
}

void HandleFile::openFile(QString in)
{
    // Abre o Arquivo de entrada
    QFile file(in);
    if(!file.open(QIODevice::ReadOnly)){
        help(2);
    }
    // Lê arquivo de entrada compactado passando para o buffer
    while(!file.atEnd()){
        QByteArray line = file.readLine(1024);
        buffer.append(line);
    }
    file.close();
}
QByteArray HandleFile::getBuffer() const
{
    return buffer;
}

void HandleFile::show() const
{
    for(int i = 0; i < buffer.size(); ++i){
        qDebug() << i
                 << (char)buffer[i]
                 << hex << (unsigned char)buffer[i];
    }
}

void HandleFile::codeBody(QString *list)
{
    for(int i = 0; i < buffer.size(); ++i){
        for(int j = 0; j < list[(unsigned char)buffer[i]].size(); ++j){
            bool bit = true;
            if(list[(unsigned char)buffer[i]][j] == '0') bit = false;
            _bodyFile.setBit(_sizeCode, bit);
            ++_sizeCode;
        }
    }
}
QByteArray HandleFile::getCodeBody()
{
    return _bodyFile.getByteArray();
}



