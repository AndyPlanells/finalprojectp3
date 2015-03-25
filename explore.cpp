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



}
