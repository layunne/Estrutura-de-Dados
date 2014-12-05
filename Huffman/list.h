#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <QList>

class List
{
private:
    QList<Node *> list;
    unsigned int curr;
public:
    List();
    // Insere o item na lista no final da lista
    void append(Node *node);

    // Limpa a Lista
    void clear();

    // Retorna a posição atual do Cursor
    int currPos();

    //Retorna o Primeiro vador da lista
    Node *getBegin();

    //Retorna o Ultimo vador da lista
    Node *getLast();

    // Retorna um Node da posição atual
    Node *getValue(int pos);

    // Insere o item na lista na posição atual
    void insert(Node *node);

    // Retorna o tamanho atual da lista
    int size();

    // Move o Cursor para a ultima posição
    void moveToEnd();

    // Move o Cursor para a posição dada
    void moveToPos(const int pos);

    // Move o Cursor para a primeira posição
    void moveToStart();

    // Move o Cursor uma posição pra frente
    void next();

    // Move o Cursor uma posição pra trás
    void prev();

    // Remove o item da posição atual
    Node *remove(int pos);

    // Imprime a lista
    void show();

    // Imprime do tipo Arvore Binaria
    void showTree(Node *base);

    // Ordena a lista pelo Peso/Frequencia
    void sort();

};


#endif // LIST_H
