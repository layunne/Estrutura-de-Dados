#include "HandleFile.h"
#include "Node.h"
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
void HandleFile::appendFileOut(QByteArray code)
{
    QFile file(_pathOut);
    if (!file.open(QIODevice::WriteOnly)) return;
    file.write(code);
    file.close();
}

void HandleFile::openFile(List &list)
{
    // Abre o Arquivo de entrada
    QFile file(_pathIn);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "The file could not be read";
    }

    // Ler a Entrada e contar as Ocorrências
    int count[256] = {0};
    while(!file.atEnd()){
        QByteArray line = file.readLine(1024);
        buffer.append(line);
        for(int i = 0; i < line.size(); ++i) {
            ++count[(unsigned char) line.at(i)];
        }
    }
    for(int i = 0; i < 256; ++i) {
        if(count[i]) {
            Node *node = new Node(true, count[i], i);
            list.append(node);
        }
    }
    file.close();
}

void HandleFile::SetIO(char *pathIn, char *pathOut)
{
    _pathIn = pathIn;
    _pathOut = pathOut;
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
//        qDebug() << "EU" << i << (char)buffer[i];
        for(int j = 0; j < list[buffer[i]].size(); ++j){
            bool bit = true;
            if(list[buffer[i]][j] == '0') bit = false;
            _bodyFile.setBit(_sizeCode, bit);
            ++_sizeCode;
        }

    }
}

QByteArray HandleFile::getCodeBody()
{
    return _bodyFile.getByteArray();
}


