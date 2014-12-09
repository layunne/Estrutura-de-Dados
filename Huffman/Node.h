#ifndef NODE_HPP
#define NODE_HPP

#include <QString>

class Node
{
private:
    Node *_left;               // Filho Esquerda
    Node *_right;              // Filho Direita
    QString _code;              // Código do Nó
    bool _isLeaf;              // Se é folha
    unsigned char _content;    // Conteúdo
    int _weight;               // Peso/Frequencia


public:
    Node();
    Node(bool isLeaf, int  weight = 0, unsigned char content = 0);
    ~Node();

    // se é folha
    bool isLeaf();

    // Retorna o code
    QString getCode();

    // Retorna o conteudo do nó
    unsigned char getContent();

    // Retorna o Filho da Esquerda
    Node *getLeftChild();

    // Retorna o Filho da direita
    Node *getRightChild();

    // Retorna o Peso/Frequencia
    int getWeight();

    //Seta o Código
    void setCode(QString code);

    // Seta o Conteúdo
    void setContent(unsigned char content);

    // Seta os dois filhos juntos
    void setChilds(Node *left, Node *right);

    //Seta o filho da esquerda
    void setLeftChild(Node *left);

    //Seta o filho da direita
    void setRightChild(Node *right);

    //Seta o Peso/Frequencia
    void setWeight(int weight);

    // Seta se é folha ou não
    void setIsLeaf(bool isLeaf = false);
};

#endif // NODE_HPP
