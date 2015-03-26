#include "login.h"
#include "ui_login.h"
#include "player.h"
#include <QString>
#include <QMessageBox>

login::login(vector<player>* one, vector<player>* two,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    p = one;
    p2 = two;
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username = ui->username_text->text();
    QString password = ui->password_text->text();
}
