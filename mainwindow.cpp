#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createplayer.h"
#include "account.h"
#include "player.h"
#include "shop.h"
#include "explore.h"
#include "characterwindow.h"
#include "login.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    players = new vector<player>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_button_clicked()
{
    login l(players,logplayers);
    l.setModal(true);
    l.exec();
}

void MainWindow::on_account_button_clicked()
{
    if(players->size()==0){
        QMessageBox::information(this,"Warning!","No player available, please create one!");
    }else{
        account ac(players);
        ac.setModal(true);
        ac.exec();
    }


}

void MainWindow::on_shop_button_clicked()
{

      if(players->size()==0){
          QMessageBox::information(this,"Warning!","No player available, please create one!");
      }else{
          shop s(players);
          s.setModal(true);
          s.exec();
      }
}

void MainWindow::on_explore_button_clicked()
{
    explore e;
    e.setModal(true);
    e.exec();
}


void MainWindow::on_pushButton_clicked()
{
    if(players->size()==0){
        QMessageBox::information(this,"Warning!","No player available, please create one!");
    }else{
        characterwindow cw(players);
        cw.setModal(true);
        cw.exec();
    }
}
