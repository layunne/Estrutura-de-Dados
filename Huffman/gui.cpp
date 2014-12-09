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
    QString nameOut = ui->localOutput->text();
    if(nameIn.size() && nameOut.size()) zip(nameIn, nameOut);
}

void Gui::on_unzipButton_clicked()
{
    QString nameIn = ui->localInput->text();
    QString nameOut = ui->localOutput->text();
    if(nameIn.size() && nameOut.size()) unzip(nameIn, nameOut);
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
    local = QFileDialog::getExistingDirectory(this,tr("Destino"), "/home") + "/";
    ui->localOutput->setText(local);
}

