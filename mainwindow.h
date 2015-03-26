#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player.h"
#include <vector>

using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_new_button_clicked();

    void on_account_button_clicked();

    void on_shop_button_clicked();

    void on_explore_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<player>* players;
    vector<player>* logplayers;
};

#endif // MAINWINDOW_H
