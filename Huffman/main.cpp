#include "auxiliar.h"
#include "gui.h"
#include <QApplication>
#include <QDebug>
#include <QList>
#include <QString>
#include <iostream>
#define DEBUG 1
//#define DEBUGOUT(mensagem) if(DEBUG)std::cout << mensagem << "\n";
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;

using std::cout;
int main(int argc, char* argv[])
{
    qDebug() << "------------COMEÇO------------";


    // Passa os Argumantos para uma QList
    QList<QString> arg;
    for(int i = 0; argv[i]; ++i) {
        arg += argv[i];
    }


    if(argc == 2 || argc == 4) {
        // huffman help
        if(arg[1] == "help") {
            help();
        }
        // huffman --gui
        else if(arg[1] == "--gui") {
            QApplication a(argc, argv);
            Gui w;
            w.show();
            return a.exec();
        }

        else {

            QString temp;

            for(int i = arg[1].size()-5; i < arg[1].size() && i > 0; ++i) {
                temp += arg[1][i];
            }

            if(temp == ".huff") {
                // huffman arquivo.huff -d /home/user/destino
                // Descompacta
                if(argc == 4 && arg[2] == "-d")  {
                    QString out = arg[3] ;
                    if(out.size() && out[out.size()-1] != '/') out += '/';
                    if(!unzip(arg[1], out)) {
                        help(3);
                        return 0;
                    }
                    return 0;
                }
                // huffman arquivo.huff
                // Descompacta
                else if(argc == 2) {
                    if(!unzip(arg[1])) {
                        help(3);
                        return 0;
                    }
                }
            }

            else {

                qDebug() << "-----------ATENÇÃO!!----------\n\n"
                         <<" ERRO: O ARQUIVO NÃO É VÁLIDO!\n"
                         << "    O arquivo não é um .huff\n"
                         << "    Por favor, insira um arquivo do tipo .huff\n";
                exit(1);
            }
        }
    }

    // huffman -c arquivo.x
    // Compacta
    else if(argc == 3 && arg[1] == "-c") {
        QString nameOut;
        QString nameIn = arg[2];
        nameOut = editNameOut(nameIn);
        if(!zip(nameIn, nameOut)) {
            help(4);
            return 0;
        }
    }

    // huffman -c arquivo_origem.x -o arquivo_de_saida.huff
    // Compacta
    else if(argc == 5 && arg[1] == "-c" && arg[3] == "-o") {

        QString nameIn, nameOut, temp;
        nameIn = arg[2];
        nameOut = arg[4];
        int i = nameOut.size() - 1;
        for( ; i > 0  && nameOut[i] != '.'; --i){
            temp.append(nameOut[i]);
        }


        if(temp == "ffuh")
        {
            if(!zip(nameIn, nameOut)) {
                help(4);
                return 0;
            }
            return 0;
        }
        else {
            qDebug() << "-----------ATENÇÃO!!----------\n"
                     <<" ERRO: O NOME DO ARQUIVO DE SAÍDA NÃO É VÁLIDO!\n"
                     << "    O nome não é um .huff\n"
                     << "    Por favor, insira um nome do tipo \"arquivo_de_saida.huff\""
                     << "\n------------------------------\n\n";
            help();
            return 0;
        }
    }

    // comando errado
    else {
        help(1);
        return 0;
    }
    qDebug() << "-------------FIM--------------\n";
    return 0;
}
