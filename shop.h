#ifndef SHOP_H
#define SHOP_H
#include "player.h"
#include <vector>


#include <QDialog>

using std::vector;

namespace Ui {
class shop;
}

class shop : public QDialog
{
    Q_OBJECT

public:
    explicit shop(vector<player>*,QWidget *parent = 0);
    ~shop();

private slots:
    void on_buy_button_clicked();

    void on_tbc_button_clicked();

    void on_wow_base_clicked();

    void on_wotlk_button_clicked();

    void on_cata_button_clicked();

    void on_mop_button_clicked();

    void on_wod_button_clicked();

    void on_d3_base_clicked();

    void on_buy_ros_clicked();

    void on_sc3_base_clicked();

    void on_buy_wol_clicked();

    void on_buy_hts_clicked();

    void on_hs_base_clicked();

    void on_buy_nax_clicked();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::shop *ui;
    vector<player>* players;
};

#endif // SHOP_H
