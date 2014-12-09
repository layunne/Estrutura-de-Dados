/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gui
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *localInput;
    QLineEdit *localOutput;
    QPushButton *loadInput;
    QPushButton *loadOutput;
    QPushButton *unzipButton;
    QPushButton *zipButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuHuffman;

    void setupUi(QMainWindow *Gui)
    {
        if (Gui->objectName().isEmpty())
            Gui->setObjectName(QStringLiteral("Gui"));
        Gui->resize(400, 236);
        centralwidget = new QWidget(Gui);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 50, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 67, 17));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        localInput = new QLineEdit(centralwidget);
        localInput->setObjectName(QStringLiteral("localInput"));
        localInput->setGeometry(QRect(109, 45, 221, 27));
        localOutput = new QLineEdit(centralwidget);
        localOutput->setObjectName(QStringLiteral("localOutput"));
        localOutput->setGeometry(QRect(109, 95, 221, 27));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(localOutput->sizePolicy().hasHeightForWidth());
        localOutput->setSizePolicy(sizePolicy);
        localOutput->setLayoutDirection(Qt::LeftToRight);
        localOutput->setEchoMode(QLineEdit::Normal);
        localOutput->setAlignment(Qt::AlignCenter);
        loadInput = new QPushButton(centralwidget);
        loadInput->setObjectName(QStringLiteral("loadInput"));
        loadInput->setGeometry(QRect(340, 45, 31, 27));
        loadOutput = new QPushButton(centralwidget);
        loadOutput->setObjectName(QStringLiteral("loadOutput"));
        loadOutput->setGeometry(QRect(340, 95, 31, 27));
        unzipButton = new QPushButton(centralwidget);
        unzipButton->setObjectName(QStringLiteral("unzipButton"));
        unzipButton->setGeometry(QRect(220, 150, 111, 27));
        zipButton = new QPushButton(centralwidget);
        zipButton->setObjectName(QStringLiteral("zipButton"));
        zipButton->setGeometry(QRect(110, 150, 111, 27));
        Gui->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Gui);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Gui->setStatusBar(statusbar);
        menubar = new QMenuBar(Gui);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 25));
        menuHuffman = new QMenu(menubar);
        menuHuffman->setObjectName(QStringLiteral("menuHuffman"));
        Gui->setMenuBar(menubar);

        menubar->addAction(menuHuffman->menuAction());

        retranslateUi(Gui);

        QMetaObject::connectSlotsByName(Gui);
    } // setupUi

    void retranslateUi(QMainWindow *Gui)
    {
        Gui->setWindowTitle(QApplication::translate("Gui", "Huffman", 0));
        label->setText(QApplication::translate("Gui", "Abrir", 0));
        label_2->setText(QApplication::translate("Gui", "Destino", 0));
        loadInput->setText(QApplication::translate("Gui", "...", 0));
        loadOutput->setText(QApplication::translate("Gui", "...", 0));
        unzipButton->setText(QApplication::translate("Gui", "Descompactar", 0));
        zipButton->setText(QApplication::translate("Gui", "Compactar", 0));
        menuHuffman->setTitle(QApplication::translate("Gui", "Huffman", 0));
    } // retranslateUi

};

namespace Ui {
    class Gui: public Ui_Gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
