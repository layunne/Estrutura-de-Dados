#ifndef TREE_HPP
#define TREE_HPP

#include "Node.h"
#include "list.h"
#include "HandleFile.h"

#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QPair>
#include <iostream>

using std::cout;
#define DEBUG 1
//#define DEBUGOUT(mensagem) if(DEBUG)std::cout << mensagem << "\n";
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;

class Tree
{
private:
    Node *_root;            // Raiz da Árvora de Huffman
    QByteArray _codeTree;   // Código da Árvore de Huffman para compactação
    QString *_listLeaf;     // Lista das Folhas com seus Respectivos Códigos _listLeaf[content] = code

public:
    Tree();
    ~Tree();
    // Constroi a Arvore de Huffmam
    void buildTree(List &list);

    // Retorna o Código da Árvore
    QByteArray getcodeTree();

    //Retorna o Código do Corpo
    QString *listNodes();

    // Retorna a Raiz da Árvore de Huffman
    Node *getRoot();

    // Seta o Código da Árvore de Huffman
    void setCodeTree(QByteArray codeTree);

    // Imprime o Código das Folhas
    void showCodeLeaf(Node *base);

    // Imprime a lista de Nodes
    void showListNodes();

    // Imprime do tipo Arvore de Huffman
    void showTree(Node *base);

    // Codificação das Folhas, da Representaão da Árvore de Huffman e uma lista das Folhas com seus respitivos Códigos
    void encoding(Node *base);

    // Seta a Raiz para Descompreção
    void setRoot(Node* root);

    // Remonta a árvore de huffman e gera a lista dos Códigos das Folhas
    void rebuildTree(Node *base);

    // Anda na arvore procurando o content correspondente a Sua Representação
    QPair<unsigned char, bool> searchLeaf(QString codeLeaf, Node *base);

    // Imprime Cófigo da árvore de huffmam
    void showCodeTree();


};

#endif // TREE_HPP
