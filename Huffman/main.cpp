#include "auxiliar.h"
#include "gui.h"
#include <QDebug>
#include <QList>
#include <QString>
#include <QApplication>
#include <iostream>
#define DEBUG 1
//#define DEBUGOUT(mensagem) if(DEBUG)std::cout << mensagem << "\n";
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;

using std::cout;
int main(int argc, char* argv[])
{
    qDebug() << "------------COMEÇO------------";
    QList<QString> arg;
    for(int i = 0; argv[i]; ++i) {
        arg += argv[i];
    }
    if(argc == 2 || argc == 4) {
        if(arg[1] == "help") {
            help();
        }
        else if(arg[1] == "--gui") {
            QApplication a(argc, argv);
            Gui w;
            w.show();
            return a.exec();
        } else {
            QString temp;
            for(int i = arg[1].size()-5; i < arg[1].size() && i > 0; ++i) {
                temp += arg[1][i];
            }
            if(temp == ".huff") {
                if(argc == 4 && arg[2] == "-d")  {
                    QString out = arg[3] ;
                    if(out.size() && out[out.size()-1] != '/') out += '/';
                    unzip(arg[1], out);
                }
                else if(argc == 2) {
                    unzip(arg[1]);
                }
            } else {

                qDebug() << "-----------ATENÇÃO!!----------\n\n"
                         <<" ERRO: O ARQUIVO NÃO É VÁLIDO!\n"
                         << "    O arquivo não é um .huff\n"
                         << "    Por favor, insira um arquivo do tipo .huff\n";
                exit(1);
            }
        }
    }
    else if(argc == 3 && arg[1] == "-c") {
        QString nameOut;
        QString nameIn = arg[2];

        nameOut = editNameOut(nameIn);
        zip(nameIn, nameOut);
    }
    else if(argc == 5 && arg[1] == "-c" && arg[3] == "-o") {
        QString nameIn, nameOut, temp;
        nameIn = arg[2];
        nameOut = arg[4];
        int i = nameOut.size() - 1;
        for( ; i > 0  && nameOut[i] != '.'; --i){
            temp.append(nameOut[i]);
        }

        DEBUGOUT("Entrada:" << nameIn)
        DEBUGOUT("Saída:" << nameOut)
        if(temp == "ffuh") {DEBUGOUT("DEU")} //zip(nameIn, nameOut);
        else {
            qDebug() << "-----------ATENÇÃO!!----------\n"
                     <<" ERRO: O NOME DO ARQUIVO DE SAÍDA NÃO É VÁLIDO!\n"
                     << "    O nome não é um .huff\n"
                     << "    Por favor, insira um nome do tipo \"arquivo_de_saida.huff\""
                     << "\n------------------------------\n\n";
            help();
        }
    }
    else help(1);
    qDebug() << "-------------FIM--------------\n";
    return 0;
}
