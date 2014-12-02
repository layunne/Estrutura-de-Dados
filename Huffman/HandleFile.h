#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include <Node.h>
#include <fstream>
#include "ListArray.h"
#include <QList>

using std::fstream;

class HandleFile
{
private:
    ListArray* list;
    QList<Node*> qList;

public:
    HandleFile();
    ~HandleFile();
    QList<Node*>& openFile2();
    ListArray* openFile();





};

#endif // HANDLEFILE_H
