#include "auxiliar.h"

void zip(QString nameIn, QString nameOut)
{
    qDebug() << "INICIANDO COMPACTAÇÃO\n\n";

    int i = nameIn.size()-1;
    int j = i;
    for(; nameIn[i] != '.' && nameIn[i] != '/' && i > 0 ;--i);
    for(; nameIn[j] != '/' && j > 0 ;--j);
    if (nameIn[i] == '/') {
        nameOut= nameIn;
    } else {
        for(++j; j < i; ++j) {
            nameOut += nameIn[j];
        }
    }
    nameOut += ".huff";

    DEBUGOUT("Entrada:" << nameIn)
    DEBUGOUT("Saída:" << nameOut)

    // Manipula o Arquivo
    HandleFile file;
    // Lista que Contém os Nós que fomaram a Árvore de Huffman
    List list;
    // Árvore de Hufman
    Tree tree;
    // Binários do Arquivo de Saída
    QByteArray codeFile;

    int sizeTrash;
    int sizeTree;

    // Lê o arquivo de entrada e Faz a contagem da ocorrência dos bytes
    file.openFile(nameIn, list);
    // Gera a árvore da codificação de Huffman
    tree.buildTree(list);
    // Gera a codificação e Gera a representação da árvore
    tree.encoding(tree.getRoot());
    file.codeBody(tree.listNodes());

    // Calcula o Tamanho do Lixo e da Árvore
    sizeTrash = 8-((file.sizeCode())%8);
    if(sizeTrash == 8) sizeTrash = 0;
    else if(sizeTrash > 8) cout << "DEU ERRO\n";
    sizeTree = tree.getcodeTree().size();


    // Retirando o local no nameIn
    QString temp = nameIn;
    nameIn.clear();
    for(i = temp.size()-1; i>=0 && temp[i] != '/'; --i);
    for(++i; i < temp.size(); ++i){
        nameIn.append(temp[i]);
    }
    DEBUGOUT("Entrada:" << nameIn)

    // Adiciona os dados codificados
    codeFile += decToByte(sizeTrash,sizeTree);
    codeFile += nameIn.size();
    codeFile += nameIn;
    codeFile += tree.getcodeTree();
    codeFile += file.getCodeBody();
    file.buildFileOut(codeFile, nameOut);
    qDebug() << "TERMINANDO COMPACTAÇÃO\n";
}


void unzip(QString nameIn, QString out)
{
    qDebug() << "INICIANDO DESCOMPACTAÇÃO\n\n";
    DEBUGOUT("Entrada:" << nameIn)
    DEBUGOUT("Saída:" << out)
    // Manipula o Arquivo
    HandleFile file;

    // Bytes do Arquivo de entrada
    QByteArray codeFileIn;
    // Bytes do Arquivo de Saída
    QByteArray codeFileOut;


    //Nome do Arquivo original
    QByteArray nameFile;

    // Árvore de Huffman
    Tree tree;

    // Representação da Árvore
    QByteArray codeTree;

    int sizeTrash = 0;
    int sizeTree = 0;
    int sizeName = 0;

    // Abre o arquivo de Entrada
    file.openFile(nameIn);

    // Recebe o buffer da entrada
    codeFileIn = file.getBuffer();

    // Decodifica o tamanho do Lixo e da Árvore
    QPair<int,int> pair = byteToDecPair(codeFileIn);
    sizeTrash = pair.first;
    sizeTree = pair.second;
    // Remove os Dois primeiros Bytes do tamanho do Lixo e da Árvore
    codeFileIn.remove(0,1);
    codeFileIn.remove(0,1);

    // Decodifica o Tamanho do nome e o Nome
    sizeName = byteToDec(codeFileIn);
    codeFileIn.remove(0,1);

    for(int i = 0; i < sizeName; ++i) {
        nameFile.append(codeFileIn.at(0));
        codeFileIn.remove(0,1);
    }
    // Decodifica a representação da Árvore de Huffman
    for(int i = 0; i < sizeTree; ++i) {
        codeTree.append((char)codeFileIn.at(0));
        codeFileIn.remove(0,1);
    }

    // Descarta o Lixo
    ByteArray codeFileByteArray;
    codeFileByteArray.toByteArray(codeFileIn);

    // Reconstroi a Árvore de Huffman
    Node *root = new Node(false);
    root->setChilds(new Node(), new Node());
    tree.setCodeTree(codeTree);
    root->getLeftChild()->setCode("0");
    root->getRightChild()->setCode("1");
    tree.rebuildTree(root->getLeftChild());
    tree.rebuildTree(root->getRightChild());
    tree.setRoot(root);

    // Decodifica o Arquivo Original passando pela árvore
    ByteArray code;
    code.toByteArray(codeFileIn);
    QByteArray temp;
    QPair<unsigned char, bool> aux;

    for(int i = 0; i < codeFileIn.size()*8 - sizeTrash; ++i) {
        if(code.getBit(i)) {
            temp += '1';
        } else {
            temp += '0';
        }
        aux = tree.searchLeaf(temp, root);
        if(aux.second) {
            codeFileOut.append(aux.first);
            temp = "";
        }
    }

    //Gera o arquvo de saída
    file.buildFileOut(codeFileOut, nameFile);
    qDebug() << "TERMINANDO DESCOMPACTAÇÃO\n";
}


QByteArray decToByte(int sizeTrash, int sizeTree){
    ByteArray code;
    int temp;
    temp = sizeTree/(0x1 << 8);
    code.setByte(0,temp);
    temp = sizeTree%(0x1 << 8);
    code.setByte(1,temp);

    switch (sizeTrash) {
    case 1:
        code.setBit(2,1);
        break;
    case 2:
        code.setBit(1,1);
        break;
    case 3:
        code.setBit(1,1);
        code.setBit(2,1);
        break;
    case 4:
        code.setBit(0,1);
        break;
    case 5:
        code.setBit(0,1);
        code.setBit(2,1);
        break;
    case 6:
        code.setBit(0,1);
        code.setBit(1,1);
        break;
    case 7:
        code.setBit(0,1);
        code.setBit(1,1);
        code.setBit(2,1);
        break;
    }
    return code.getByteArray();
}


QPair<int, int> byteToDecPair(QByteArray code)
{
    ByteArray bytes;
    bytes.toByteArray(code);
    int n0=0, n1=0;
    for(int i = 2; i >= 0; --i) {
        if(bytes.getBit(i)) {
            int mask = 0x1;
            mask = mask << (2 - i);
            n0 += mask;
        }
    }
    for(int i = 15; i > 2; --i) {
        if(bytes.getBit(i)) {
            int mask = 0x1;
            mask = mask << (15 -i);
            n1 += mask;
        }
    }
    QPair<int, int> pair(n0, n1);
    return pair;
}
int byteToDec(QByteArray code)
{
    ByteArray bytes;
    bytes.toByteArray(code);
    int dec=0;
    for(int i = 7; i > 0; --i) {
        if(bytes.getBit(i)) {
            int mask = 0x1;
            mask = mask << (7 - i);
            dec += mask;
        }
    }
    return dec;
}

void help(int i)
{
    cout << "-------------HELP-------------\n\n";
    if(i == 0) {
        qDebug() << "LISTA DE COMANDOS:\n\n"
                 <<  "$> huffman -c arquivo_origem.x -o arquivo_de_saida.huff\n"
                 <<  "   Comprime o arquivo \"arquivo_origem.x\" e gera o arquivo de saída\n    \"arquivo_de_saida.huff\"\n\n"
                 <<  "$> huffman -c arquivo.x\n"
                 <<  "   Comprime o arquivo \"arquivo.x\" e gera o arquivo de saída “arquivo.huff”,\n    mantendo o nome do arquivo original\n\n"
                 <<  "$> huffman arquivo.huff\n"
                 <<  "   Descomprime o arquivo \"arquivo.huff\" na pasta local com o nome original\n\n"
                 <<  "$> huffman arquivo.huff -d /home/user/destino\n"
                 <<  "   Descomprime o arquivo \"arquivo.huff\" na pasta “/home/user/destino\"\n    com o nome original\n\n"
                 <<  "$> huffman --gui\n"
                 <<  "   Inicia a Interface gráfica"
                 <<  "$> huffman help\n"
                 <<  " ";
    }
    else if(i == 1) {
        qDebug() << "COMANDO NÃO EXISTE OU ESTÁ INCORRETO\n";
        help();
    }
    else if(i == 2) {
        qDebug() << "-----------ATENÇÃO!!----------\n\n"
                 << "ERRO: O ARQUIVO NÃO EXISTE OU NÃO FOI ENCONTRADO!!\n"
                 <<  "Verifique se o nome do Arquivo está correto\n ou se está na pasta certa e tente novamente.\n"
                 <<  "Use o comando help para uma breve ajuda.\n\n";
    }
    qDebug() << "------------------------------\n";
}
