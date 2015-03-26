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

    QFile file(":/classic.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->wow_text->setText(in.readAll());
    }

}

void explore::on_pushButton_2_clicked()
{
    QFile file(":/tbc.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->wow_text->setText(in.readAll());
    }
    
}

void explore::on_pushButton_3_clicked()
{
    QFile file(":/wotlk.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->wow_text->setText(in.readAll());
    }
    
}

void explore::on_pushButton_4_clicked()
{
    QFile file(":/cata.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->wow_text->setText(in.readAll());
    }
    
}

void explore::on_pushButton_5_clicked()
{
    QFile file(":/mop.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->wow_text->setText(in.readAll());
    }
    
}

void explore::on_pushButton_6_clicked()
{
    QFile file(":/wod.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->wow_text->setText(in.readAll());
    }
    
}

void explore::on_pushButton_7_clicked()
{
    QFile file(":/d3.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->d3_text->setText(in.readAll());
    }
}

void explore::on_pushButton_8_clicked()
{
    QFile file(":/ros.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->d3_text->setText(in.readAll());
    }
}

void explore::on_pushButton_9_clicked()
{
    QFile file(":/sc2.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->sc2_text->setText(in.readAll());
    }
}

void explore::on_pushButton_10_clicked()
{
    QFile file(":/wol.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->sc2_text->setText(in.readAll());
    }
}

void explore::on_pushButton_11_clicked()
{
    QFile file(":/hts.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->sc2_text->setText(in.readAll());
    }
}


void explore::on_pushButton_12_clicked()
{
    QFile file(":/hs.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this,"Warning",file.errorString());
    }else{
        QTextStream in(&file);
        ui->hs_text->setText(in.readAll());
    }
}
