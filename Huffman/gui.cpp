#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gui)
{
    ui->setupUi(this);
}

Gui::~Gui()
{
    delete ui;
}

void Gui::on_zipButton_clicked()
{
    QString nameIn = ui->localInput->text();
    QString nameOut = editNameOut(nameIn);
    QString out = ui->localOutput->text();
    QString msgWindowTitle;
    QString msgText;
    QMessageBox msgBox;
    if(nameIn.size() && out.size()) {
        if(out.at(out.size()-1) != '/') out += '/';
        if(zip(nameIn, nameOut, out)){
            msgWindowTitle = "Sucesso!";
            msgText = "Arquivo Compactado com Sucesso.";
        }
        else {
            msgWindowTitle = "Erro!";
            msgText = "O Arquivo não foi compactado.";
        }

        ui->localInput->setText("");
    }





    msgBox.setText(msgText);
    msgBox.setWindowTitle(msgWindowTitle);
    msgBox.exec();
}

void Gui::on_unzipButton_clicked()
{
    QString nameIn = ui->localInput->text();
    QString out = ui->localOutput->text();
    QMessageBox msgBox;
    QString msgWindowTitle;
    QString msgText;

    if(nameIn.size() && out.size()) {
        if(out.at(out.size()-1) != '/') out += '/';
        if(unzip(nameIn, out)) {
            msgWindowTitle = "Sucesso!";
            msgText = "Arquivo Descompactado com Sucesso.";

        } else {
            msgWindowTitle = "Erro!";
            msgText = "O Arquivo não foi Descompactado.\nVerifique se a entrada é um .huff\nOu se o arquivo está corrompido.";
        }
        ui->localInput->setText("");
    }
    msgBox.setText(msgText);
    msgBox.setWindowTitle(msgWindowTitle);
    msgBox.exec();
}
void Gui::on_loadInput_clicked()
{
    QString temp;
    temp = QFileDialog::getOpenFileName(this,tr("Abrir Arquivo"), "/home");
    ui->localInput->setText(temp);
}

void Gui::on_loadOutput_clicked()
{
    QString local;
    local = QFileDialog::getExistingDirectory(this,tr("Destino"), "/home");
    ui->localOutput->setText(local);
}

