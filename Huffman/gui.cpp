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
    if(nameIn.size() && out.size()) {
        if(out.at(out.size()-1) != '/') out += '/';
        if(zip(nameIn, nameOut, out)){
            QMessageBox msgBox;
            msgBox.setWindowTitle("Sucesso!");
            msgBox.setText("Seu Arquivo foi comprimido com Sucesso.");
            msgBox.exec();

        }
        else {
        }

        ui->localInput->setText("");
    }





}

void Gui::on_unzipButton_clicked()
{
    QString nameIn = ui->localInput->text();
    QString out = ui->localOutput->text();
    if(nameIn.size() && out.size()) {
        if(out.at(out.size()-1) != '/') out += '/';
        unzip(nameIn, out);
        ui->localInput->setText("");
    }
    QMessageBox msgBox;
    msgBox.setWindowTitle("Sucesso!");
    msgBox.setText("Seu Arquivo foi descomprimido com Sucesso.");
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

