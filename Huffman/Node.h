#ifndef NODE_HPP
#define NODE_HPP

#include <QString>

class Node
{
private:
    Node *_left;               // Filho Esquerda
    Node *_right;              // Filho Direita
    Node *_dad;
    QString _code;              // Código do Nó
    bool _isLeaf;              // Se é folha
    unsigned char _content;    // Conteúdo
    int _weight;               // Peso/Frequencia


public:
    Node();
    Node(bool l, int  w, unsigned char c = 0);
    ~Node();

    // se é folha
    bool isLeaf();

    // Retorna o code
    QString getCode();

    // Retorna o conteudo do nó
    unsigned char getContent();

    // Retorda pai
    Node *getDad();

    // Retorna o Filho da Esquerda
    Node *getLeftChild();

    // Retorna o Filho da direita
    Node *getRightChild();

    // Retorna o Peso/Frequencia
    int getWeight();

    // Seta Pai
    void setDad(Node *dad);

    //Seta o Código
    void setCode(QString code);

    // Seta os dois filhos juntos
    void setChilds(Node *left, Node *right);

    //Seta o filho da esquerda
    void setLeftChild(Node *left);

    //Seta o filho da direita
    void setRightChild(Node *right);

    //Seta o Peso/Frequencia
    void setWeight(int weight);
};

#endif // NODE_HPP
