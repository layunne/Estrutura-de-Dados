#include "ListArray.h"
#include <Node.h>
#include <QDebug>

#define MAXSIZE 256

ListArray::ListArray()
{
    lengthList = 0;
    curr = 0;
    listArray = new Node*[MAXSIZE];

}
ListArray::~ListArray(){
    clear();
}

void ListArray::clear(){
    delete [] listArray;
    curr = 0;
    lengthList = 0;
    listArray = new Node*[MAXSIZE];
}

void ListArray::insert(int  weight, unsigned char content){


    listArray[curr] = new Node(weight, content);
    ++lengthList;
}

void ListArray::append(int  weight, unsigned char content){
    Node* node = new Node(weight, content);
    listArray[lengthList++] = node;
}

Node* ListArray::remove(){
    Node* item = listArray[curr];
    for(int i = curr; i < lengthList-1; ++i){
        listArray[i] = listArray[i+1];
    }
    --lengthList;
    return item;
}

void ListArray::next(){
    if(curr < lengthList-1){
        ++curr;
    }
}

void ListArray::prev(){
    if(curr > 0){
        --curr;
    }
}

void ListArray::moveToStart(){
    curr = 0;
}

void ListArray::moveToEnd(){
    curr = lengthList-1;
}

void ListArray::moveToPos(const int pos){
    curr = pos;
}

int ListArray::length(){
    return lengthList;
}

Node* ListArray::getValue(){
    return listArray[curr];
}

void ListArray::show(){
    for(int i = 0; i < length(); ++i){
        qDebug() << "POSIÇÃO" << i << "FREQUENCIA" << listArray[i]->getWeight() << "VALOR" << hex << listArray[i]->getContent();
    }

}

void ListArray::sort(){
    qDebug()<<"NADA" << "sort()";
}
