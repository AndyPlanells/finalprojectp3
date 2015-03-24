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
                ui->transactions_edit->append("Bought Item: 30 days Gametime'\nGame: World of Warcraft\nBalance spent: 15\n- - - - -\n");
                QString tochange = ui->total_edit->text();
                int count = tochange.toInt();
                count+=15;
                tochange = QString::number(count);
                ui->total_edit->setText(tochange);
            }else{
                 QMessageBox::information(this,"Warning","Not enough balance!  ");
            }
        }else if(ui->rb_90->isChecked()){
            if(players->at(0).getBalance()>=30){
                gtime+=90;
                players->at(0).setBalance(players->at(0).getBalance()-30);
                ui->transactions_edit->append("Bought Item: 90 days Gametime\nGame: World of Warcraft\nBalance spent: 30\n- - - - -\n");
                QString tochange = ui->total_edit->text();
                int count = tochange.toInt();
                count+=30;
                tochange = QString::number(count);
                ui->total_edit->setText(tochange);
            }else{
                 QMessageBox::information(this,"Warning","Not enough balance!  ");
            }
        }else{
            if(players->at(0).getBalance()>=60){
                gtime+=120;
                players->at(0).setBalance(players->at(0).getBalance()-60);
                ui->transactions_edit->append("Bought Item: 120 days Gametime\nGame: World of Warcraft\nBalance spent: 60\n- - - - -\n");
                QString tochange = ui->total_edit->text();
                int count = tochange.toInt();
                count+=60;
                tochange = QString::number(count);
                ui->total_edit->setText(tochange);
            }else{
                 QMessageBox::information(this,"Warning","Not enough balance!  ");
            }
        }
        players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,iftbc,ifwotlk,ifcata,ifmop,ifwod));
        QMessageBox::information(this,"Balance","Succesfully bought gametime!");
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
                int gtime = players->at(0).getMyWoW().getGametime();
                players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,false,false,false,false));
                ui->transactions_edit->append("Bought Item: Expansion 'The Burning Crusade'\nGame: World of Warcraft\nBalance spent: 20\n- - - - -\n");
                QString tochange = ui->total_edit->text();
                int count = tochange.toInt();
                count+=20;
                tochange = QString::number(count);
                ui->total_edit->setText(tochange);
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
            players->at(0).setMyWoW(wow(true,"World of Warcraft",0,true,false,false,false,false,false));
            ui->transactions_edit->append("Bought Item: Base Game\nGame: World of Warcraft\nBalance spent: 40\n- - - - -\n");
            QString tochange = ui->total_edit->text();
            int count = tochange.toInt();
            count+=40;
            tochange = QString::number(count);
            ui->total_edit->setText(tochange);
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
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,false,false,false));
                    ui->transactions_edit->append("Bought Item: Expansion 'Wrath of the Lich King'\nGame: World of Warcraft\nBalance spent: 20\n- - - - -\n");
                    QString tochange = ui->total_edit->text();
                    int count = tochange.toInt();
                    count+=20;
                    tochange = QString::number(count);
                    ui->total_edit->setText(tochange);
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
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,true,false,false));
                    ui->transactions_edit->append("Bought Item: Expansion 'Cataclysm'\nGame: World of Warcraft\nBalance spent: 20\n- - - - -\n");
                    QString tochange = ui->total_edit->text();
                    int count = tochange.toInt();
                    count+=20;
                    tochange = QString::number(count);
                    ui->total_edit->setText(tochange);
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
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,true,true,false));
                    ui->transactions_edit->append("Bought Item: Expansion 'Mists of Pandaria'\nGame: World of Warcraft\nBalance spent: 20\n- - - - -\n");
                    QString tochange = ui->total_edit->text();
                    int count = tochange.toInt();
                    count+=20;
                    tochange = QString::number(count);
                    ui->total_edit->setText(tochange);
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
                    int gtime = players->at(0).getMyWoW().getGametime();
                    players->at(0).setMyWoW(wow(true,"World of Warcraft",gtime,true,true,true,true,true,true));
                    ui->transactions_edit->append("Bought Item: Expansion 'Warlords of Draenor'\nGame: World of Warcraft\nBalance spent: 20\n- - - - -\n");
                    QString tochange = ui->total_edit->text();
                    int count = tochange.toInt();
                    count+=20;
                    tochange = QString::number(count);
                    ui->total_edit->setText(tochange);
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
            players->at(0).setMyd3(d3(true,"Diablo III",false));
            ui->transactions_edit->append("Bought Item: Base Game\nGame: Diablo III\nBalance spent: 40\n- - - - -\n");
            QString tochange = ui->total_edit->text();
            int count = tochange.toInt();
            count+=40;
            tochange = QString::number(count);
            ui->total_edit->setText(tochange);
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
                players->at(0).setMyd3(d3(true,"Diablo III",true));
                ui->transactions_edit->append("Bought Item: Expansion 'Reaper of Souls'\nGame: Diablo III\nBalance spent: 40\n- - - - -\n");
                QString tochange = ui->total_edit->text();
                int count = tochange.toInt();
                count+=40;
                tochange = QString::number(count);
                ui->total_edit->setText(tochange);
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
            players->at(0).setMySc2(sc2(true,"Starcraft II",false,false));
            ui->transactions_edit->append("Bought Item: Base Game\nGame: Starcraft II\nBalance spent: 40\n- - - - -\n");
            QString tochange = ui->total_edit->text();
            int count = tochange.toInt();
            count+=40;
            tochange = QString::number(count);
            ui->total_edit->setText(tochange);
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
                players->at(0).setMySc2(sc2(true,"Starcraft II",true,false));
                ui->transactions_edit->append("Bought Item: Expansion 'Wings of Liberty'\nGame: Starcraft II\nBalance spent: 40\n- - - - -\n");
                QString tochange = ui->total_edit->text();
                int count = tochange.toInt();
                count+=40;
                tochange = QString::number(count);
                ui->total_edit->setText(tochange);
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
                    players->at(0).setMySc2(sc2(true,"Starcraft",true,true));
                    ui->transactions_edit->append("Bought Item: Expansion 'Heart of the Swarm'\nGame: Starcraft II\nBalance spent: 40\n- - - - -\n");
                    QString tochange = ui->total_edit->text();
                    int count = tochange.toInt();
                    count+=40;
                    tochange = QString::number(count);
                    ui->total_edit->setText(tochange);
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
    }else{
        players->at(0).setMyHs(Hs(true,"Hearthstone",false));
        ui->transactions_edit->append("Bought Item: Base Game\nGame: Hearthstone\nBalance spent: 0\n- - - - -\n");
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
                players->at(0).setMyHs(Hs(true,"Hearthstone",true));
                ui->transactions_edit->append("Bought Item: Expansion 'The Curse of Naxxramas'\nGame: Hearthstone\nBalance spent: 10\n- - - - -\n");
                QString tochange = ui->total_edit->text();
                int count = tochange.toInt();
                count+=10;
                tochange = QString::number(count);
                ui->total_edit->setText(tochange);
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
        int newbalance = ui->spin_balance->value();
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

