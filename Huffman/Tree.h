#ifndef TREE_HPP
#define TREE_HPP

#include "Node.h"
#include "list.h"
#include "HandleFile.h"

#include <QByteArray>
#include <QString>
#include <QPair>

class Tree
{
private:
    HandleFile file;
    List *list;
    Node *_root;
    QByteArray _codeTree;
    QString _codeNode;
    QString *_listLeaf;
    long int size;



public:
    Tree();
    // Constroi a Arvore de Huffmam
    void buildTree(List &list);

    // Retorna o Código da Árvore
    QByteArray getcodeTree();

    //Retorna o Código do Corpo
    QString *listNodes();

    // Retorna a Raiz da Árvore de Huffman
    Node *getRoot();

    void setCodeTree(QByteArray codeTree);

    // Imprime os Códigos das Folhas
    void showCodeLeaf(Node *base);

    // Imprime a lista de Nodes
    void showListNodes();

    // Imprime do tipo Arvore de Huffman
    void showTree(Node *base);

    // Codificação
    void encoding(Node *base);

    //Seta a Raiz - Descompreção
    void setRoot(Node* root);

    // Remonta a árvore de huffman e gera a lista dos Códigos das Folhas
    void rebuildTree(Node *base);

    // Anda na arvore procurando o content correspondente a Sua Representação
    QPair<unsigned char, bool> searchLeaf(QString codeLeaf, Node *base);

    void showCodeTree();


};

#endif // TREE_HPP
