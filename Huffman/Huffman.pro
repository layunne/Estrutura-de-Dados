#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T14:28:06
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT += widgets

TARGET = Huffman
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Node.cpp \
    Tree.cpp \
    HandleFile.cpp \
    list.cpp \
    ByteArray.cpp \
    auxiliar.cpp \
    gui.cpp

HEADERS += \
    Node.h \
    Tree.h \
    HandleFile.h \
    list.h \
    ByteArray.h \
    auxiliar.h \
    gui.h

FORMS += \
    gui.ui
