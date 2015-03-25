#include "explore.h"
#include "ui_explore.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

explore::explore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::explore)
{
    ui->setupUi(this);
}

explore::~explore()
{
    delete ui;
}

void explore::on_pushButton_clicked()
{
    QFile file("./about.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"warning",file.errorString());
    }

    QTextStream in(&file);

    //podes agregar el .txt al los resources y en vez the "./about.txt" en el url le pones ":/about.txt"

    ui->wow_text->setText(in.readAll());


}
