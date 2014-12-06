#ifndef TREE_HPP
#define TREE_HPP

#include "Node.h"
#include "list.h"
#include "HandleFile.h"

#include <QByteArray>
#include <QString>

class Tree
{
private:
    HandleFile file;
    List *list;
    Node *root;
    QByteArray _codeTree;
    QString _codeNode;
    QString *_listNodes;
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

    // Imprime os Códigos das Folhas
    void showCodeLeaf(Node *base);

    // Imprime a lista de Nodes
    void showListNodes();

    // Imprime do tipo Arvore de Huffman
    void showTree(Node *base);

    // Codificação
    void encoding(Node *base);

    void readTree();

};

#endif // TREE_HPP
