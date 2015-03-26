#ifndef LOGIN_H
#define LOGIN_H
#include "player.h"

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(vector<player>*, vector<player>*,QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    vector<player>* p;
    vector<player>* p2;
};

#endif // LOGIN_H
