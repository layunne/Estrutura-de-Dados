#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <Node.h>

class ListArray
{
private:
    unsigned short int lengthList;
    unsigned short int curr;
    Node** listArray;




public:
    ListArray();
    ~ListArray();

    // Limpa a Lista
    void clear();
    // Insere o item na lista na posição atual
    void insert(int  weight, unsigned char content = 0);
    // Insere o item na lista no final da lista
    void append(int  weight, unsigned char content = 0);
    // Remove o item da posição atual
    Node* remove();
    // Move o Cursor uma posição pra frente
    void next();
    // Move o Cursor uma posição pra trás
    void prev();
    // Move o Cursor para a primeira posição
    void moveToStart();
    // Move o Cursor para a ultima posição
    void moveToEnd();
    // Move o Cursor para a posição dada
    void moveToPos(const int pos);
    // Retorna a posição atual do Cursor
    int currPos();
    // Retorna o tamanho atual da lista
    int length();
    // Retorna um Node da posição atual
    Node* getValue();
    // Imprime a lista
    void show();
    // Ordena a lista pelo Peso/Frequencia
    void sort();


};

#endif // LISTARRAY_H
