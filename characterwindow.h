#ifndef CHARACTERWINDOW_H
#define CHARACTERWINDOW_H
#include "player.h"
#include "games.h"
#include "characters.h"
#include <vector>

#include <QDialog>

using std::vector;

namespace Ui {
class characterwindow;
}

class characterwindow : public QDialog
{
    Q_OBJECT

public:
    explicit characterwindow(vector<player>*,QWidget *parent = 0);
    ~characterwindow();

private slots:
    void on_wow_createcharbut_clicked();

    void on_pushButton_clicked();

    void on_wow_selectbut_clicked();

    void on_d3_createcharbut_clicked();

    void on_pushButton_2_clicked();

    void on_d3_selectbut_clicked();

    void on_hs_createcardbut_clicked();

    void on_hs_selectbut_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::characterwindow *ui;
    vector<player>* players;
};

#endif // CHARACTERWINDOW_H
