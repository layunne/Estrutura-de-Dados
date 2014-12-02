#ifndef NODE_HPP
#define NODE_HPP

class Node
{
private:
    Node* left;             // Filho Esquerda
    Node* right;          // Filho Direita
    Node* parent;          // Pai
    unsigned char content;  // Conteúdo
    int weight;             // Peso/Frequencia


public:
    Node();
    Node(int  weight, unsigned char content = 0);
    ~Node();

    // Retorna o conteudo do nó
    unsigned char getContent();
    // Retorna o Peso/Frequencia
    int getWeight();
    // Retorna o Filho da Esquerda
    Node* getLeftChild();
    // Retorna o Filho da direita
    Node* getRightChild();

    //Seta o filho da esquerda
    void setLeftChild(Node* left);
    //Seta o filho da direita
    void setRightChild(Node* right);
};

#endif // NODE_HPP
