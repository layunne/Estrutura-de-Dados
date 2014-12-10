#ifndef LIST_H
#define LIST_H

#include "Node.h"

#include <QList>
#include <QDebug>
#include <stdlib.h>
#include <iostream>

#define DEBUG 1
//#define DEBUGOUT(mensagem) if(DEBUG)std::cout << mensagem << "\n";
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;

class List
{
private:
    QList<Node *> list; // Uma Lista de Nodes
public:
    List();
    ~List();

    // Insere o item na lista no final da lista
    void append(Node *node);

    // limpa todos os Atributos
    void clear();

    //Retorna o Primeiro vador da lista
    Node *getBegin();

    //Retorna o Ultimo vador da lista
    Node *getLast();

    // Retorna um Node da posição atual
    Node *getValue(int pos);

    // Retorna o tamanho atual da lista
    int size();

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
