#include "HandleFile.h"
#include "Node.h"
#include "ListArray.h"
#include <fstream>
#include <QDebug>
#include <QList>



HandleFile::HandleFile()
{
    list = new ListArray;

}

HandleFile::~HandleFile()
{

}

QList<Node*>& HandleFile::openFile2()
{
    std::ifstream is ("test", std::ifstream::binary);
    if(is){
        // Pega o tamanho do Arquivo
        is.seekg(0, is.end);
        int length = is.tellg();
        length = is.tellg();
        is.seekg(0,is.beg);

        // Aloca a memória
       char* buffer = new char [length];

        //Ler dados
        is.read (buffer,length);

        // fecha arquivo
        is.close();

        // Contar Peso
        unsigned char array[256][2] = {0};
        int lengthArray = 0;
        for(int i = 0; i < length; ++i){
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
//        for(int i = 0; i < length; ++i){
//            qDebug() << buffer[i] << i;
//        }

        delete[] buffer;

        // para ListArray
        for(int i = 0; i < lengthArray; ++i){
            qDebug() << i;
            Node* node = new Node(array[i][1], array[i][0]);
            qList.append(node);
        }
    }
    return qList;

}
ListArray* HandleFile::openFile(){
    std::ifstream is ("test", std::ifstream::binary);
    if(is){
        // Pega o tamanho do Arquivo
        is.seekg(0, is.end);
        int length = is.tellg();
        length = is.tellg();
        is.seekg(0,is.beg);

        // Aloca a memória
       char* buffer = new char [length];

        //Ler dados
        is.read (buffer,length);

        // fecha arquivo
        is.close();

        // Contar Peso
        unsigned char array[256][2] = {0};
        int lengthArray = 0;
        for(int i = 0; i < length; ++i){
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

        delete[] buffer;

        // para ListArray
        for(int i = 0; i < lengthArray; ++i){
            list->append((int)array[i][1], array[i][0]);

        }
    }
    return list;

}


