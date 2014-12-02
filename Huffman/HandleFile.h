#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include <Node.h>
#include <fstream>
#include "ListArray.h"

using std::fstream;

class HandleFile
{
private:
public:
    HandleFile();
    ~HandleFile();
     ListArray openFile();




};

#endif // HANDLEFILE_H
