#include "auxiliar.h"
#include <QDebug>
#include <QList>
#include <QString>

int main(int argc, char* argv[])
{
    qDebug() << "------------COMEÇO------------";
    QList<QString> arg;
    for(int i = 0; argv[i]; ++i) {
        arg += argv[i];
    }
    if(argc == 2 || argc == 4) {
        QString temp;
        for(int i = arg[1].size()-5; i < arg[1].size() && i > 0; ++i) {
            temp += arg[1][i];
        }
        if(temp == ".huff") {
            if(argc == 4 && arg[2] == "-d")  {
                unzip(arg[1], arg[3]);
            }
            else if(argc == 2) {
                unzip(arg[1]);
            }
        } else {
            qDebug() << "-----------ATENÇÃO!!----------\n\n"
                     <<"ERRO: O ARQUIVO NÃO É VÁLIDO!\n"
                     << "   O arquivo não é um .huff\n"
                     << "   Por favor, insira um arquivo do tipo .huff";
            exit(1);
        }
    }
    else if(argc == 3 && arg[1] == "-c") {
        QString nameOut;
        int i = arg[2].size()-1;
        for(; arg[2][i] != '.' && i > 0 ;--i);
        if (!i) {
            nameOut+= arg[2];
        } else {
            for(int j = 0; j < i; ++j) {
                nameOut += arg[2][j];
            }
        }
        nameOut += ".huff";
        zip(arg[2], nameOut);
    }
    else if(argc == 5 && arg[1] == "-c" && arg[3] == "-o") {
        QString temp;
        for(int i = arg[4].size()-5; i < arg[4].size() && i > 0; ++i) {
            temp += arg[4][i];
        }
        if(temp == ".huff") {
            zip(arg[2], arg[4]);
        } else {
            qDebug() << "-----------ATENÇÃO!!----------\n"
                     <<"ERRO: O NOME DO ARQUIVO DE SAÍDA NÃO É VÁLIDO!\n"
                     << "   O nome não é um .huff\n"
                     << "   Por favor, insira um nome do tipo \"arquivo_de_saida.huff\""
                     << "\n------------------------------\n\n";
            help();
        }
    }
    else help(1);
    qDebug() << "-------------FIM--------------";
    return 0;
}
