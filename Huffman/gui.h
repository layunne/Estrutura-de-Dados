#ifndef GUI_H
#define GUI_H

#include "auxiliar.h"

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <iostream>

using std::cout;
#define DEBUG 1
//#define DEBUGOUT(mensagem) if(DEBUG)std::cout << mensagem << "\n";
#define DEBUGOUT(mensagem) if(DEBUG)qDebug() << mensagem;

namespace Ui {
class Gui;
}

class Gui : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = 0);
    ~Gui();

private slots:
    void on_zipButton_clicked();

    void on_loadInput_clicked();

    void on_loadOutput_clicked();

    void on_unzipButton_clicked();

private:
    Ui::Gui *ui;
};

#endif // GUI_H
