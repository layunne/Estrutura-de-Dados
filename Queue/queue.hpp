#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "queueADT.h"
#include "linkedlist.hpp"

#include <QDebug>


/*
 *  A Fila será uma lista ligada com inserção pela calda e
 * remoção pela frente.
 *  A Class File herdará os métodos da ADT dada e da LinkedList.
*/
template <typename E>

class Fila : public Queue<E>, LinkedList<E> {

public:
    Fila() {
    }
    ~Fila() {
        clear();
    }
    void clear() {
        LinkedList<E>::clear();
    }
    // Inserir no Final
    void enqueue(const E& item) {
        LinkedList<E>::append(item);
    }
    // Remover do começo. Posição do Cursor não altera, ou seja, igual a zero.
    E dequeue() {
        return LinkedList<E>::remove();
    }
    const E& frontValue() const {
        return LinkedList<E>::getValue();
    }
    int length() const {
        return LinkedList<E>::length();
    }
    void show() {
        LinkedList<E>::show();
    }
};

#endif // QUEUE_HPP
