#include "HandleFile.h"
#include "Node.h"
#include <fstream>
#include <QDebug>
#include <QList>


using std::ifstream;
using namespace std;
HandleFile::HandleFile()
{
    buffer = NULL;
    lengthB = 0;
}

HandleFile::~HandleFile()
{

}

void HandleFile::buildFileOut(char code[])
{
    fileOut.open(_pathOut, ios::out | ios::binary | ios::app);
    fileOut.write(code,sizeof(code));
}

void HandleFile::openFile()
{
    // Abre o Arquivo de entrada
    fileIn.open(_pathIn, ios::in | ios::binary);

    if(fileIn){
        // Pega o tamanho do Arquivo
        fileIn.seekg(0, fileIn.end);
        lengthB = fileIn.tellg();
        fileIn.seekg(0,fileIn.beg);

        // Aloca a memória
       buffer = new char [lengthB];

        //Ler dados
        fileIn.read (buffer,lengthB);

        // fecha arquivo
        fileIn.close();
    } else {
        qDebug() << "ARQUIVO NÃO ENCONTRADO";
    }
}

void HandleFile::SetIO(char *pathIn, char *pathOut)
{
    _pathIn = pathIn;
    _pathOut = pathOut;
}
char *HandleFile::getBuffer() const
{
    return buffer;
}

int HandleFile::getLengthB() const
{
    return lengthB;
}

void HandleFile::count(List *list)
{

    unsigned char array[256][2] = {0};

    int lengthArray = 0;

    for(int i = 0; i < lengthB; ++i){
        bool stop = true;
        for(int j = 0; stop; ++j){
            if(buffer[i] == array[j][0]){
                ++array[j][1];
                stop = false;
            }
            else if(!array[j][0]){
                array[j][0] = buffer[i];
                ++array[j][1];
                ++lengthArray;
                stop = false;
            }
        }
    }
    for(int i = 0; i < lengthArray; ++i){
        Node *node = new Node(true, array[i][1], array[i][0]);
        list->append(node);
    }
}

void HandleFile::show() const
{
    for(int i = 0; i < lengthB; ++i){
        qDebug() << i << hex << (unsigned char)buffer[i];
    }
}

void HandleFile::codeBory(QString *list)
{
    for(int i = 0; i < lengthB; ++i){
        _bodyFile += list[(int)buffer[i]];
    }
    for(int i = 0; i < _bodyFile.length(); ++i){
        qDebug() << _bodyFile.at(i);
    }
}



