#include "Node.h"
#include "HandleFile.h"
#include "list.h"
#include "Tree.h"
#include "ByteArray.h"
#include "auxiliar.h"
#include <iostream>
#include <QDebug>
#include <fstream>
#include <stdlib.h>
#include <QList>
#include <QByteArray>
#include <string>
#include <QFile>


using namespace std;

int main(int argc, char* argv[])
{

    qDebug()<<"------COMEÇO-----";
    QList<QString> arg;
    for(int i = 0; argv[i]; ++i){
        arg += argv[i];
    }
    if(argc == 2){
        unzip(arg[1], arg[1]);
    }
    else if(argc == 3){

    }
    else if(argc == 4){

    }
    else if(argc == 5){
        if(arg[1] == "-c"){
            zip(arg[2], arg[4]);
        }
    }

    qDebug()<<"-------FIM-------";

    return 0;
}
