#ifndef CREATEPLAYER_H
#define CREATEPLAYER_H

#include <QDialog>
#include "player.h"
#include <vector>

using std::vector;

namespace Ui {
class createplayer;
}

class createplayer : public QDialog
{
    Q_OBJECT

public:
    explicit createplayer(vector<player>*,QWidget *parent = 0);
    ~createplayer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createplayer *ui;
    vector<player>* players;
};

#endif // CREATEPLAYER_H
