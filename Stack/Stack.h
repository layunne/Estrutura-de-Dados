#ifndef STACK_H
#define STACK_H

#include "StackADT.h"
#include <QString>
#include <QDebug>

template<class E>
class Stack : public StackADT<E> {

private:
    E *_array;
    int _size;
    int _sizeAlloc;


public:
    Stack () {
        _sizeAlloc = 256;
        _array = new E[_sizeAlloc];
        _size = 0;
    }

    Stack (int length) {
        _array = new E[length];
        _sizeAlloc = length;
        _size = 0;
    }

    void clear() {
        delete[] _array;
        _array = new E[_sizeAlloc];
        _size = 0;
    }
    void push(const E &it) {
        _array[_size] = it;
        ++_size;

        // igual ao total alocado
        if(_size == _sizeAlloc) {
            _sizeAlloc += _sizeAlloc*0.20;
            if(_sizeAlloc < 10) _sizeAlloc += 2;
            E *arrayTemp = new E[_sizeAlloc];
            for(int i = 0; i < _size; ++i) {
                arrayTemp[i] = _array[i];
            }
            delete[] _array;
            _array = arrayTemp;
        }
    }
    E pop() {
        Q_ASSERT_X(_size != 0, "Stack::pop", "Empty Stack");
        return _array[--_size];
        // menor que 50% do total alocado
        if(_sizeAlloc > 256 && _size < _sizeAlloc*0.50) {
            _sizeAlloc -= _sizeAlloc*0.30;
            E *arrayTemp = new E[_sizeAlloc];
            for(int i = 0; i < _size; ++i) {
                arrayTemp[i] = _array[i];
            }
            delete[] _array;
            _array = arrayTemp;
        }
    }
    const E& topValue() const {
        Q_ASSERT_X(_size != 0, "Stack::topValue", "Empty Stack");
        return _array[_size - 1];
    }
    int length() const {
        return _size;
    }
    bool isEmpty() {
        return _size == 0;
    }
    virtual QString toString() {
        QString stack;
        for(int i = _size  - 1; i >= 0; --i) {
            stack += QString::number(_array[i]) + "\n";
        }
        return stack;
    }
    void show(){
        qDebug() << "-----show-----";
        for(int i = 0; i < _size; ++i) {
            qDebug() << _array[i];
        }
        qDebug() << "-----show-----";
    }
};







#endif // STACK_H
