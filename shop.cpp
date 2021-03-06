#include "shop.h"
#include "ui_shop.h"
#include "player.h"
#include "games.h"
#include "wow.h"
#include "hs.h"
#include "d3.h"
#include "sc2.h"
#include <vector>
#include <QMessageBox>
#include <iostream>
#include <QString>
#include <QTableWidget>

using std::vector;
using std::cout;
using std::endl;

shop::shop(vector<player>* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shop)
{
    players = p;
    ui->setupUi(this);
    int numbers = players->at(0).getVisaCard();
    QString ss = QString::number(numbers);
    ui->card_label->setText(ss);

}

shop::~shop()
{
    delete ui;
}

void shop::on_buy_button_clicked()
{
    if(players->at(0).getMyWoW().getIfbought()){
        int gtime = players->at(0).getMyWoW().getGametime();
        bool iftbc = players->at(0).getMyWoW().getTbc();
        bool ifwotlk = players->at(0).getMyWoW().getWotlk();
        bool ifcata = players->at(0).getMyWoW().getCata();
        bool ifmop = players->at(0).getMyWoW().getMop();
        bool ifwod = players->at(0).getMyWoW().getWod();
        if(ui->rb_30->isChecked()){
            if(players->at(0).getBalance()>=15){
                gtime+=30;
                players->at(0).setBalance(players->at(0).getBalance()-15);
                players->at(0).setgcheck(gamecheck("Gametime",players->at(0).getMychecks(),15));
                players->at(0).setMychecks(players->at(0).getMychecks()+1);
                players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                QMessageBox::information(this,"Balance","Succesfully bought gametime!");
            }else{
                 QMessageBox::information(this,"Warning","Not enough balance!  ");
            }
        }else if(ui->rb_90->isChecked()){
            if(players->at(0).getBalance()>=30){
                gtime+=90;
                players->at(0).setBalance(players->at(0).getBalance()-30);
                players->at(0).setgcheck(gamecheck("Gametime",players->at(0).getMychecks(),30));
                players->at(0).setMychecks(players->at(0).getMychecks()+1);
                players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
            }else{
                 QMessageBox::information(this,"Warning","Not enough balance!  ");
            }
        }else{
            if(players->at(0).getBalance()>=60){
                gtime+=120;
                players->at(0).setBalance(players->at(0).getBalance()-60);
                players->at(0).setgcheck(gamecheck("Gametime",players->at(0).getMychecks(),60));
                players->at(0).setMychecks(players->at(0).getMychecks()+1);
                players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
            }else{
                 QMessageBox::information(this,"Warning","Not enough balance!  ");
            }
        }
        players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,iftbc,ifwotlk,ifcata,ifmop,ifwod));
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }

}

void shop::on_tbc_button_clicked()
{
    if(players->at(0).getMyWoW().getIfbought()){
        if(players->at(0).getMyWoW().getTbc()){
            QMessageBox::information(this,"Warning","You bought this expansion already!  ");
        }else{
            if(players->at(0).getBalance()>=20){
                players->at(0).setBalance(players->at(0).getBalance()-20);
                players->at(0).setgcheck(gamecheck("TBC",players->at(0).getMychecks(),20));
                players->at(0).setMychecks(players->at(0).getMychecks()+1);
                players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                int gtime = players->at(0).getMyWoW().getGametime();
                players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,false,false,false,false));

                QMessageBox::information(this,"The Burning Crusade","Succesfully bought!");
            }else{
                QMessageBox::information(this,"Warning","Not enough balance!  ");
            }
        }

    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }


}

void shop::on_wow_base_clicked()
{
    if(players->at(0).getMyWoW().getIfbought()){
        QMessageBox::information(this,"Warning","The game is already bought");
    }else{
        if(players->at(0).getBalance()>=40){
            players->at(0).setBalance(players->at(0).getBalance()-40);
            players->at(0).setgcheck(gamecheck("WoW",players->at(0).getMychecks(),40));
            players->at(0).setMychecks(players->at(0).getMychecks()+1);
            players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
            players->at(0).setMyWoW(wow(true,"World of Warcraft",0,true,false,false,false,false,false));

            QMessageBox::information(this,"World of Warcraft","Succesfully bought!");
        }else{
            QMessageBox::information(this,"Warning","Not enough balance!  ");
        }
    }
}

void shop::on_wotlk_button_clicked()
{
    if(players->at(0).getMyWoW().getIfbought()){
        if(players->at(0).getMyWoW().getTbc()){
            if(players->at(0).getMyWoW().getWotlk()){
                QMessageBox::information(this,"Warning","You bought this expansion already!");
            }else{
                if(players->at(0).getBalance()>=20){
                    players->at(0).setBalance(players->at(0).getBalance()-20);
                    players->at(0).setgcheck(gamecheck("Wotlk",players->at(0).getMychecks(),20));
                    players->at(0).setMychecks(players->at(0).getMychecks()+1);
                    players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,false,false,false));

                    QMessageBox::information(this,"Wrath of the Lich King","Succesfully bought!");
                }else{
                    QMessageBox::information(this,"Warning","Not enough balance!  ");
                }
            }
        }else{
            QMessageBox::information(this,"Warning","You need to buy the previous expanion before attempting to play a new one");
        }
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }

}

void shop::on_cata_button_clicked()
{
    if(players->at(0).getMyWoW().getIfbought()){
        if(players->at(0).getMyWoW().getWotlk()){
            if(players->at(0).getMyWoW().getCata()){
                 QMessageBox::information(this,"Warning","You already bought this expansion! ");
            }else{
                if(players->at(0).getBalance()>=20){
                    players->at(0).setBalance(players->at(0).getBalance()-20);
                    players->at(0).setgcheck(gamecheck("Cata",players->at(0).getMychecks(),20));
                    players->at(0).setMychecks(players->at(0).getMychecks()+1);
                    players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,true,false,false));

                    QMessageBox::information(this,"Cataclysm","Succesfully bought!");
                }else{
                    QMessageBox::information(this,"Warning","Not enough balance!  ");
                }
            }
        }else{
            QMessageBox::information(this,"Warning","You need to buy the previous expanion before attempting to play a new one");
        }
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }

}

void shop::on_mop_button_clicked()
{
    if(players->at(0).getMyWoW().getIfbought()){
        if(players->at(0).getMyWoW().getCata()){
            if(players->at(0).getMyWoW().getMop()){
                QMessageBox::information(this,"Warning","You already bought this expansion! ");
            }else{
                if(players->at(0).getBalance()>=20){
                    players->at(0).setBalance(players->at(0).getBalance()-20);
                    players->at(0).setgcheck(gamecheck("MoP",players->at(0).getMychecks(),20));
                    players->at(0).setMychecks(players->at(0).getMychecks()+1);
                    players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,true,true,false));

                    QMessageBox::information(this,"Mist of Pandaria","Succesfully bought!");
                }else{
                    QMessageBox::information(this,"Warning","Not enough balance!  ");
                }
            }
        }else{
            QMessageBox::information(this,"Warning","You need to buy the previous expanion before attempting to play a new one");
        }
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }

}

void shop::on_wod_button_clicked()
{
    if(players->at(0).getMyWoW().getIfbought()){
        if(players->at(0).getMyWoW().getMop()){
            if(players->at(0).getMyWoW().getWod()){
                QMessageBox::information(this,"Warning","You already bought this expansion!  ");
            }else{
                if(players->at(0).getBalance()>=20){
                    players->at(0).setBalance(players->at(0).getBalance()-20);
                    players->at(0).setgcheck(gamecheck("WoD",players->at(0).getMychecks(),20));
                    players->at(0).setMychecks(players->at(0).getMychecks()+1);
                    players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,true,true,true));

                    QMessageBox::information(this,"Warlords of Draenor","Succesfully bought!");
                }else{
                    QMessageBox::information(this,"Warning","Not enough balance!  ");
                }
            }
        }else{
            QMessageBox::information(this,"Warning","You need to buy the previous expanion before attempting to play a new one");
        }
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }

}

void shop::on_d3_base_clicked()
{
    if(players->at(0).getMyd3().getIfbought()){
        QMessageBox::information(this,"Warning","The game is already bought");
    }else{
        if(players->at(0).getBalance()>=40){
            players->at(0).setBalance(players->at(0).getBalance()-40);
            players->at(0).setgcheck(gamecheck("D3",players->at(0).getMychecks(),40));
            players->at(0).setMychecks(players->at(0).getMychecks()+1);
            players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
            players->at(0).setMyd3(d3(true,"Diablo III",false));

            QMessageBox::information(this,"Diablo III","Succesfully bought!");
        }else{
            QMessageBox::information(this,"Warning","Not enough balance!  ");
        }
    }
}

void shop::on_buy_ros_clicked()
{
    if(players->at(0).getMyd3().getIfbought()){
        if(players->at(0).getMyd3().getRos()){
            QMessageBox::information(this,"Warning","This expansion is already bought!");
        }else{
            if(players->at(0).getBalance()>=40){
                players->at(0).setBalance(players->at(0).getBalance()-40);
                players->at(0).setgcheck(gamecheck("RoS",players->at(0).getMychecks(),40));
                players->at(0).setMychecks(players->at(0).getMychecks()+1);
                players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                players->at(0).setMyd3(d3(true,"Diablo III",true));

                QMessageBox::information(this,"The Reaper of Souls","Succesfully bought!");
            }else{
                QMessageBox::information(this,"Warning","Not enough balance!");
            }
        }
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }

}

void shop::on_sc3_base_clicked()
{
    if(players->at(0).getMySc2().getIfbought()){
        QMessageBox::information(this,"Warning","The game is already bought");
    }else{
        if(players->at(0).getBalance()>=40){
            players->at(0).setBalance(players->at(0).getBalance()-40);
            players->at(0).setgcheck(gamecheck("Sc3",players->at(0).getMychecks(),40));
            players->at(0).setMychecks(players->at(0).getMychecks()+1);
            players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
            players->at(0).setMySc2(sc2(true,"Starcraft II",false,false));

            QMessageBox::information(this,"Diablo III","Succesfully bought!");
        }else{
            QMessageBox::information(this,"Warning","Not enough balance!  ");
        }
    }
}

void shop::on_buy_wol_clicked()
{
    if(players->at(0).getMySc2().getIfbought()){
        if(players->at(0).getMySc2().getWol()){
            QMessageBox::information(this,"Warning","You already bought this expansion!");
        }else{
            if(players->at(0).getBalance()>=40){
                players->at(0).setBalance(players->at(0).getBalance()-40);
                players->at(0).setgcheck(gamecheck("WoL",players->at(0).getMychecks(),40));
                players->at(0).setMychecks(players->at(0).getMychecks()+1);
                players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                players->at(0).setMySc2(sc2(true,"Starcraft II",true,false));

                QMessageBox::information(this,"Wings of Liberty","Succesfully bought!");
            }else{
                QMessageBox::information(this,"Warning","Not enough balance!");
            }
        }
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }
}

void shop::on_buy_hts_clicked()
{
    if(players->at(0).getMySc2().getIfbought()){
        if(players->at(0).getMySc2().getWol()){
            if(players->at(0).getMySc2().getHts()){
                QMessageBox::information(this,"Warning","You already bought this expansion!  ");
            }else{
                if(players->at(0).getBalance()>=40){
                    players->at(0).setBalance(players->at(0).getBalance()-40);
                    players->at(0).setgcheck(gamecheck("Sc2",players->at(0).getMychecks(),40));
                    players->at(0).setMychecks(players->at(0).getMychecks()+1);
                    players->at(0).setTimesgames(players->at(0).getTimesgames()+1);
                    players->at(0).setMySc2(sc2(true,"Starcraft",true,true));

                    QMessageBox::information(this,"Heart of the Swarm","Succesfully bought!");
                }else{
                    QMessageBox::information(this,"Warning","Not enough balance!  ");
                }
            }
        }else{
            QMessageBox::information(this,"Warning","You need to buy the previous expanion before attempting to play a new one");
        }
    }else{
        QMessageBox::information(this,"Warning","You have not bought this game yet.");
    }
}

void shop::on_hs_base_clicked()
{
    if(players->at(0).getMyHs().getIfbought()){
        QMessageBox::information(this,"Warning","You already have this game.");
        players->at(0).setgcheck(gamecheck("HS",players->at(0).getMychecks(),0));
        players->at(0).setMychecks(players->at(0).getMychecks()+1);
        players->at(0).setTimesgames(players->at(0).getTimesgames()+0);
    }else{
        players->at(0).setMyHs(Hs(true,"Hearthstone",false));
        QMessageBox::information(this,"Hearthstone","Succesfully Acquired!");
    }
}

void shop::on_buy_nax_clicked()
{
    if(players->at(0).getMyHs().getIfbought()){
        if(players->at(0).getMyHs().getFounderpack()){
            QMessageBox::information(this,"Warning","Expansion is already bought!");
        }else{
            if(players->at(0).getBalance()>=10){
                players->at(0).setBalance(players->at(0).getBalance()-10);
                players->at(0).setgcheck(gamecheck("HSFP",players->at(0).getMychecks(),10));
                players->at(0).setMychecks(players->at(0).getMychecks()+1);
                players->at(0).setTimesgames(players->at(0).getTimesgames()+0);
                players->at(0).setMyHs(Hs(true,"Hearthstone",true));

                QMessageBox::information(this,"Curse of Naxxramas","Succesfully bought!");
            }else{
                QMessageBox::information(this,"Warning","Not enough balance!");
            }
        }
    }else{
        QMessageBox::information(this,"Warning","You don't have this game yet.");
    }
}

void shop::on_pushButton_clicked()
{
    int codey = players->at(0).getVisaCode();
    QString codes = QString::number(codey);
    if(ui->code_label->text()==codes){
        double newbalance = ui->spin_balance->value();
        players->at(0).setbcheck(balancecheck("D3",players->at(0).getMychecks(),newbalance));
        players->at(0).setMychecks(players->at(0).getMychecks()+1);
        players->at(0).setTimesbalance(players->at(0).getTimesbalance()+0);
        newbalance+=players->at(0).getBalance();
        players->at(0).setBalance(newbalance);
        QMessageBox::information(this,"Balance","Succesfully added new Balance to your account.");
        ui->spin_balance->setValue(0);
        ui->code_label->setText("");
    }else{
         QMessageBox::information(this,"Warning","Invalid Code. Transaction Failed.");
         ui->spin_balance->setValue(0);
         ui->code_label->setText("");
    }
}


void shop::on_pushButton_2_clicked()
{
    ui->tst_t->model()->removeRows(0,100);
    ui->tst_b->model()->removeRows(0,100);
    int size1 = players->at(0).getMygcheck().size();
    int size2 = players->at(0).getMybcheck().size();
    ui->tst_t->setRowCount(size1);
    int timesg = players->at(0).getTimesgames();
    QString checkno, item, cost, tax, discount,total;
    for(int i=0;i<size1;i++){
        checkno =  QString::number(players->at(0).getMygcheck().at(i).getNocheck());
        item = QString::fromStdString(players->at(0).getMygcheck().at(i).getBoughtitem());
        cost = QString::number(players->at(0).getMygcheck().at(i).getBalance());
        tax = QString::number(players->at(0).getMygcheck().at(i).getTax());
        discount = QString::number(players->at(0).getMygcheck().at(i).getDiscount(timesg));
        double balancetotal = players->at(0).getMygcheck().at(i).getBalance();
        double taxtotal = players->at(0).getMygcheck().at(i).getTax();
        double discounttotal = players->at(0).getMygcheck().at(i).getDiscount(timesg);
        total = QString::number(balancetotal+(taxtotal*balancetotal)-(balancetotal*discounttotal));
        ui->tst_t->setItem(i,0,new QTableWidgetItem(checkno));
        ui->tst_t->setItem(i,1,new QTableWidgetItem(item));
        ui->tst_t->setItem(i,2,new QTableWidgetItem(cost));
        ui->tst_t->setItem(i,3,new QTableWidgetItem(tax));
        ui->tst_t->setItem(i,4,new QTableWidgetItem(discount));
        ui->tst_t->setItem(i,5,new QTableWidgetItem(total));
        timesg--;
    }
    players->at(0).setTimesgames(0);

    ui->tst_b->setRowCount(size2);
    int timesb = players->at(0).getTimesbalance();
    for(int i=0;i<size2;i++){
        checkno =  QString::number(players->at(0).getMybcheck().at(i).getNocheck());
        cost = QString::number(players->at(0).getMybcheck().at(i).getMoney());
        tax = QString::number(players->at(0).getMybcheck().at(i).getTax());
        discount = QString::number(players->at(0).getMybcheck().at(i).getDiscount(timesb));
        double balancetotal = players->at(0).getMybcheck().at(i).getMoney();
        double taxtotal = players->at(0).getMybcheck().at(i).getTax();
        double discounttotal = players->at(0).getMygcheck().at(i).getDiscount(timesg);
        total = QString::number(balancetotal+(taxtotal*balancetotal)-(balancetotal*discounttotal));
        ui->tst_b->setItem(i,0,new QTableWidgetItem(checkno));
        ui->tst_b->setItem(i,1,new QTableWidgetItem(cost));
        ui->tst_b->setItem(i,2,new QTableWidgetItem(tax));
        ui->tst_b->setItem(i,3,new QTableWidgetItem(discount));
        ui->tst_b->setItem(i,4,new QTableWidgetItem(total));
        timesg--;
    }
    players->at(0).setTimesbalance(0);
}

