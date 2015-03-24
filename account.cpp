#include "account.h"
#include "ui_account.h"
#include "player.h"
#include "games.h"
#include "wow.h"
#include "d3.h"
#include "sc2.h"
#include "hs.h"
#include <QString>
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;
using std::string;

account::account(vector<player>* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::account)
{
    players = p;
    ui->setupUi(this);

    QString name = QString::fromStdString(players->at(0).getName()) + " " + QString::fromStdString(players->at(0).getLastname());
    QString username = QString::fromStdString(players->at(0).getUsername());
    QString email = QString::fromStdString(players->at(0).getEmail());
    int balancestuff = players->at(0).getBalance();
    ui->name_label->setText(name);
    ui->username_label->setText(username);
    ui->email_label->setText(email);
    ui->spin_balance->setValue(balancestuff);

    string sone = players->at(0).getMyWoW().toString();
    string stwo = players->at(0).getMyd3().toString();
    string sthree = players->at(0).getMySc2().toString();
    string sfour = players->at(0).getMyHs().toString();
    QString qone = QString::fromStdString(sone);
    QString qtwo = QString::fromStdString(stwo);
    QString qthree = QString::fromStdString(sthree);
    QString qfour = QString::fromStdString(sfour);

    ui->games_text->appendPlainText(qone);
    ui->games_text_2->appendPlainText(qtwo);
    ui->games_text_3->appendPlainText(qthree);
    ui->games_text_4->appendPlainText(qfour);
}

account::~account()
{

    delete ui;
}
