#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include "player.h"
#include <vector>

using std::vector;

namespace Ui {
class account;
}

class account : public QDialog
{
    Q_OBJECT

public:
    explicit account(vector<player>*,QWidget *parent = 0);
    ~account();

private:
    Ui::account *ui;
    vector<player>* players;

};

#endif // ACCOUNT_H
