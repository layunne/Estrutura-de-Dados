#include <iostream>
#include <QDebug>
#include "Node.h"
#include <fstream>
#include "HandleFile.h"
#include "ListArray.h"
#include "Node.h"


using namespace std;
int main()
{
    qDebug()<<"COMEÇO";
    HandleFile file;
    ListArray list = file.openFile();
//    list.sort();
    list.show();


    qDebug()<<"FIM";

    return 0;
}
