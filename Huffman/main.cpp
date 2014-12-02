#include <iostream>
#include <QDebug>
#include "Node.h"
#include <fstream>
#include "Handlein.h"
#include "ListArray.h"
#include "Node.h"


using namespace std;
int main()
{
    qDebug()<<"COMEÇO";
    handleIn file;
    ListArray list = file.openFile();
//    list.sort();
    list.show();


    qDebug()<<"FIM";

    return 0;
}
