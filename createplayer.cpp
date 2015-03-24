#include "createplayer.h"
#include "ui_createplayer.h"
#include "games.h"
#include "wow.h"
#include "sc2.h"
#include "hs.h"
#include "d3.h"
#include <string>
#include <vector>
#include "characters.h"
#include "wdchar.h"
#include "shochar.h"
#include "hschar.h"

using std::string;
using std::vector;


createplayer::createplayer(vector<player>* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createplayer)
{
    players=p;
    ui->setupUi(this);
}

createplayer::~createplayer()
{
    delete ui;
}

void createplayer::on_pushButton_clicked()
{
    string name = ui->name_label->text().toStdString();
    string lastname = ui->lastname_label->text().toStdString();
    string username = ui->username_label->text().toStdString();
    string password = ui->password_label->text().toStdString();
    string email = ui->email_label->text().toStdString();
    int VisaCard = ui->creditcard_label->text().toInt();
    int VisaCode = ui->cardno_label->text().toInt();
    int balance = ui->balance_label->text().toInt();
    wow mywow;
    d3 myd3;
    sc2 mysc2;
    Hs myhs;
    players->push_back(player(name,lastname,username,password,email,VisaCard,VisaCode,balance,mywow,myd3,mysc2,myhs));
    this->hide();
}

