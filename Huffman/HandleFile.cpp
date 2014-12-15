#include "HandleFile.h"

using std::cout;


using std::ifstream;
using namespace std;


HandleFile::HandleFile()
{
    _sizeCode = 0;
}

HandleFile::~HandleFile()
{
    clear();
}

void HandleFile::clear()
{
    _buffer.clear();
    _bodyFile.clear();
    _sizeCode =  0;
}

long long int HandleFile::sizeCode() const
{
    return _sizeCode;
}
bool HandleFile::buildFileOut(QByteArray code, QString nameOut)
{
    QFile file(nameOut);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "O DIRETÓRIO NÃO EXITE";
        help(2);
        return false;
    }
    file.write(code);
    file.close();
    qDebug() << "\nARQUIVO SALVO COM SUCESSO!\n";
    return true;
}

bool HandleFile::openFile(QString in, List &list)
{
    // Abre o Arquivo de entrada
    QFile file(in);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "O ARQUIVO NÃO EXITE";
        help(2);
        return false;
    }

    // Lê o arquivo de entrada e conta as Ocorrências
    int count[256] = {0};
    while(!file.atEnd()) {
        QByteArray line = file.readLine(1024);
        _buffer.append(line);
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
    return true;
}

bool HandleFile::openFile(QString in)
{
    // Abre o Arquivo de entrada
    QFile file(in);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "O ARQUIVO NÃO EXITE";
        help(2);
        return false;
    }
    // Lê arquivo de entrada compactado passando para o buffer
    while(!file.atEnd()) {
        QByteArray line = file.readLine(1024);
        _buffer.append(line);
    }
    file.close();
    return true;
}
QByteArray HandleFile::getBuffer() const
{
    return _buffer;
}

void HandleFile::show() const
{
    for(int i = 0; i < _buffer.size(); ++i) {
        DEBUGOUT(i
                 << (char)_buffer[i]
                 << hex << (unsigned char)_buffer[i])
    }
}

void HandleFile::codeBody(QList<QString> list)
{
    for(int i = 0; i < _buffer.size(); ++i) {
        for(int j = 0; j < list[(unsigned char)_buffer[i]].size(); ++j) {
            bool bit = true;
            if(list[(unsigned char)_buffer[i]][j] == '0') {
                bit = false;
            }
            _bodyFile.setBit(_sizeCode, bit);
            ++_sizeCode;
        }
    }
}
QByteArray HandleFile::getCodeBody()
{
    return _bodyFile.getByteArray();
}

QByteArray HandleFile::rebuildFile(QByteArray codeFile, int sizeTrash, Node *root)
{
    Node *curr = root;
    ByteArray code;
    code.toByteArray(codeFile);
    QByteArray codeFileOut;
    long long int sizeCode = codeFile.size();

    for(long long int i = 0; i < sizeCode*8 - sizeTrash; ++i) {
        if(code.getBit(i)) {
            curr = curr->getRightChild();
        } else {
            curr = curr->getLeftChild();
        }
        if(curr->isLeaf())
        {
            codeFileOut += curr->getContent();
            curr = root;
        }
    }
    return codeFileOut;
}



