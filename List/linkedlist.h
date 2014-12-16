/*

    FELLYPE LAYUNNE

*/



#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list.h"
#include "Node.h"

#include <QDebug>

template<class E>
class LinkedList : public List<E> {

    Node<E> *m_cursor;
    Node<E> *m_head;
    Node<E> *m_tail;
public:
    LinkedList() {
        reset();
    }
    ~LinkedList() {
    clear();
    }

    void reset() {
        m_cursor = 0;
        m_head = 0;
        m_tail = 0;
    }
    void show() {
        Node<E> *temp;
        temp = m_head;
        qDebug() << "-----show-----";
        while(temp) {
            qDebug() << temp->content;
            temp = temp->next;
        }
        qDebug() << "-----show-----";
    }

    void clear() {
        moveToStart();
        Node<E> *temp;
        m_cursor = m_head;
        temp = m_cursor;
        while(m_cursor)
        {
            temp = m_cursor->next;
            delete(m_cursor);
            m_cursor = temp;
        }
        reset(); // Zerar
    }
    void insert(const E& item) {
        if(m_cursor != 0) {
            Node<E> *node = new Node<E>(item);
            Node<E> *temp;
            temp = m_cursor;
            if(m_cursor != m_head) {
                prev();
                m_cursor->next = node;
                node->next = temp;
                next();
            } else {
                node->next = m_head;
                m_head = node;
            }
        } else {
            append(item);
        }
    }

    void append(const E& item) {
        Node<E> *node = new Node<E>(item);
        if(m_head == 0) {
            m_head = node;
            m_tail = node;
            m_cursor = node;
        } else {
            m_tail->next = node;
            m_tail = node;
        }
    }
    E remove() {
        Q_ASSERT_X(m_cursor != 0, "LinkedList::remove", "Empty list");
        E item;
        Node<E> *temp;

        temp = m_cursor;
        item = m_cursor->content;
        if(m_cursor != m_head) {
            prev();
            m_cursor->next = temp->next;
            if(m_cursor->next != 0) {
                next();
            } else {
                m_tail = m_cursor;
            }
        } else {
            m_head = m_head->next;
            m_cursor = m_head;
        }
        delete(temp);
        return item;
    }

    void moveToStart() {
        m_cursor = m_head;
    }

    void moveToEnd() {
        m_cursor = m_tail;
    }

    void prev() {
        if(m_cursor != m_head) {
            Node<E> *temp;
            temp = m_cursor;
            moveToStart();
            while(m_cursor->next != temp) {
                m_cursor = m_cursor->next;
            }

        }
    }

    void next() {
        if(m_cursor != m_tail) {
            m_cursor = m_cursor->next;
        }
    }
    int length() const {
        int len = 0;
        Node<E> *temp;
        temp = m_head;
        while(temp != m_tail) {
            temp = temp->next;
            ++len;
        }
        if(m_head) ++len;
        return len;
    }
    int currPos() const {
        int pos = 0;
        if(m_cursor == 0) {
            qDebug() << "Lista Vazia";
        }
        else {
            Node<E> *temp;
            temp = m_head;
            while(temp != m_cursor) {
                temp = temp->next;
                ++pos;
            }
        }
        return pos;

    }
    void moveToPos(int pos) {
        Q_ASSERT_X(pos >= 0 && pos < length(), "LinkedList::moveToPos", "index does not belong to list");
        moveToStart();
        int aux = 0;
        while(aux != pos) {
            next();
            ++aux;
        }
    }

    const E& getValue() const {
        Q_ASSERT_X(m_cursor != 0, "LinkedList::getValue", "Empty list");
        return m_cursor->content;
    }

    void bubbleSort() {}

    void selectionSort() {}

    void insertionSort() {}

    void shellSort() {}
};

#endif // LINKEDLIST_H
