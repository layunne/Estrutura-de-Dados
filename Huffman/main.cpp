#include <iostream>
#include <QDebug>
#include "Node.h"
#include <fstream>
#include "HandleFile.h"
#include "ListArray.h"
#include "Node.h"
#include <stdlib.h>
#include <QList>


using namespace std;

int comparar(const void *a, const void *b){
  return(*(int*)a - *(int*)b);
}
bool caseInsensitiveLessThan(Node* &n1, Node* &n2)
 {
    if(n1->getWeight() == n2->getWeight()){
        return n1->getContent() < n2->getContent();
    }
     return n1->getWeight() < n2->getWeight();
 }

int main()
{
    qDebug()<<"COMEÇO";
    HandleFile file;
   ListArray* list;
    list = file.openFile();
//    list->sort();
    list->show();

    QList<Node*> lista;
    lista = file.openFile2();
//    for(int i = 0; i < 5; ++i);
//    int valores[] = {0, 4 , 2, 3 , 1};
//    qsort(valores, 5, sizeof(int), comparar);

//    for(int i = 0; i < 5; ++i){
//        qDebug() << valores[i];
//    }
    qSort(lista.begin(), lista.end(), caseInsensitiveLessThan);
    for(int i = 0; i < lista.length(); ++i){
        qDebug() << lista.at(i)->getWeight() << hex << lista.at(i)->getContent();
    }

    qDebug()<<"FIM";

    return 0;
}
