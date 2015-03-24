#include "characterwindow.h"
#include "ui_characterwindow.h"
#include "player.h"
#include "characters.h"
#include "games.h"
#include "wow.h"
#include "d3.h"
#include "sc2.h"
#include "hs.h"
#include "wdchar.h"
#include "shochar.h"
#include "hschar.h"
#include <iostream>
#include <QString>
#include <string>
#include <QMessageBox>

#include <vector>

using std::vector;
using std::string;
using std::cout;

characterwindow::characterwindow(vector<player>* p,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::characterwindow)
{
    players=p;
    ui->setupUi(this);
    if(players->at(0).getMyWoW().getIfbought()){
        ui->wow_chars->setEnabled(true);
        ui->wow_faction->setEnabled(true);
        ui->wow_selectbut->setEnabled(true);
        ui->wow_name->setEnabled(true);
        ui->wow_race->setEnabled(true);
        ui->wow_type->setEnabled(true);
        ui->wow_level->setEnabled(true);
        ui->wow_gender->setEnabled(true);
        ui->wow_name_2->setEnabled(true);
        ui->wow_cblevel->setEnabled(true);
        ui->wow_cbrace->setEnabled(true);
        ui->wow_cbtype->setEnabled(true);
        ui->wow_createcharbut->setEnabled(true);
        ui->wowrb_f->setEnabled(true);
        ui->wowrb_m->setEnabled(true);
        ui->pushButton->setEnabled(true);
        if(players->at(0).getMyWoW().getWod()){
            ui->wow_cblevel->setMaximum(100);
        }else if(players->at(0).getMyWoW().getMop()){
            ui->wow_cblevel->setMaximum(90);
        }else if(players->at(0).getMyWoW().getCata()){
            ui->wow_cblevel->setMaximum(85);
        }else if(players->at(0).getMyWoW().getWotlk()){
            ui->wow_cblevel->setMaximum(80);
        }else if(players->at(0).getMyWoW().getTbc()){
            ui->wow_cblevel->setMaximum(70);
        }else{
            ui->wow_cblevel->setMaximum(60);
        }
    }
    if(players->at(0).getMyd3().getIfbought()){
        ui->pushButton_2->setEnabled(true);
        ui->d3_chars->setEnabled(true);
        ui->d3_name->setEnabled(true);
        ui->d3_type->setEnabled(true);
        ui->d3_level->setEnabled(true);
        ui->d3_name_2->setEnabled(true);
        ui->d3rb_f->setEnabled(true);
        ui->d3rb_m->setEnabled(true);
        ui->d3_cblevel->setEnabled(true);
        ui->d3_cbtype->setEnabled(true);
        ui->d3_createcharbut->setEnabled(true);
        ui->d3_selectbut->setEnabled(true);
        ui->d3_gender->setEnabled(true);
        if(players->at(0).getMyd3().getRos()){
            ui->d3_cblevel->setMaximum(70);
        }else{
            ui->d3_cblevel->setMaximum(60);
        }
    }
    if(players->at(0).getMyHs().getIfbought()){
        ui->pushButton_3->setEnabled(true);
        ui->hs_cbinfo->setEnabled(true);
        ui->hs_cbmanacost->setEnabled(true);
        ui->hs_cbtype->setEnabled(true);
        ui->hs_chars->setEnabled(true);
        ui->hs_createcardbut->setEnabled(true);
        ui->hs_info->setEnabled(true);
        ui->hs_manacost->setEnabled(true);
        ui->hs_name->setEnabled(true);
        ui->hs_name_2->setEnabled(true);
        ui->hs_selectbut->setEnabled(true);
        ui->hs_type->setEnabled(true);
    }
}

characterwindow::~characterwindow()
{
    delete ui;
}

void characterwindow::on_wow_createcharbut_clicked()
{

    QString name = ui->wow_name_2->text();
    QString race = ui->wow_cbrace->currentText();
    QString type = ui->wow_cbtype->currentText();
    string gender;
    if(ui->wowrb_f->isChecked()){
        gender = "Female";
    }else{
        gender = "Male";
    }
    int level = ui->wow_cblevel->value();
    wdchar a(name.toStdString(),"World of Warcraft",level,type.toStdString(),race.toStdString(),gender);
    players->at(0).setwowchar(a);
    QMessageBox::information(this,"Create","Succesfully Created Character!");

    ui->wow_name_2->setText("");
    ui->wow_cblevel->setValue(1);
}

void characterwindow::on_pushButton_clicked()
{
    ui->wow_chars->clear();
    for(unsigned i;i<players->at(0).getMywowchars().size();i++){
        ui->wow_chars->addItem(QString(players->at(0).getMywowchars().at(i).getName().c_str()));
    }

}

void characterwindow::on_wow_selectbut_clicked()
{
    ui->wow_name->setText(QString(players->at(0).getMywowchars().at(ui->wow_chars->currentIndex()).getName().c_str()));
    ui->wow_type->setText(QString(players->at(0).getMywowchars().at(ui->wow_chars->currentIndex()).getType().c_str()));
    ui->wow_race->setText(QString(players->at(0).getMywowchars().at(ui->wow_chars->currentIndex()).getRace().c_str()));
    ui->wow_gender->setText(QString(players->at(0).getMywowchars().at(ui->wow_chars->currentIndex()).getGender().c_str()));
    int level = players->at(0).getMywowchars().at(ui->wow_chars->currentIndex()).getLevel();
    QString tochange = QString::number(level);
    ui->wow_level->setText(tochange);
    QImage image;
    if(ui->wow_race->text()=="Human"){
       ui->wow_faction->setText("Alliance");
       image.load(":/human.jpg");
    }else if(ui->wow_race->text()=="Dwarf"){
        ui->wow_faction->setText("Alliance");
        image.load(":/dwarf.jpg");
    }else if(ui->wow_race->text()=="Gnome"){
        ui->wow_faction->setText("Alliance");
        image.load(":/gnome.jpg");
    }else if(ui->wow_race->text()=="Night Elf"){
        ui->wow_faction->setText("Alliance");
        image.load(":/nelf.jpg");
    }else if(ui->wow_race->text()=="Draenei"){
        ui->wow_faction->setText("Alliance");
        image.load(":/draenei.jpg");
    }else if(ui->wow_race->text()=="Worgen"){
        ui->wow_faction->setText("Alliance");
        image.load(":/worgen.jpg");
    }else if(ui->wow_race->text()=="Orc"){
        ui->wow_faction->setText("Horde");
        image.load(":/orc.jpg");
    }else if(ui->wow_race->text()=="Troll"){
        ui->wow_faction->setText("Horde");
        image.load(":/troll.jpg");
    }else if(ui->wow_race->text()=="Undead"){
        ui->wow_faction->setText("Horde");
        image.load(":/undead.jpg");
    }else if(ui->wow_race->text()=="Tauren"){
        ui->wow_faction->setText("Horde");
        image.load(":/tauren.jpg");
    }else if(ui->wow_race->text()=="Blood Elf"){
        ui->wow_faction->setText("Horde");
        image.load(":/belf.jpg");
    }else if(ui->wow_race->text()=="Goblin"){
        ui->wow_faction->setText("Horde");
        image.load(":/goblin.jpg");{
            ui->hs_name->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getName().c_str()));
            ui->hs_type->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getType().c_str()));
            int manacost = players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getManacost();
            QString tochange = QString::number(manacost);
            ui->hs_manacost->setText(tochange);
            QImage image;
            if(ui->hs_type->text()=="Priest"){
               image.load(":/priest.png");
            }else if(ui->hs_type->text()=="Warrior"){
               image.load(":/warrior.png");
            }else if(ui->hs_type->text()=="Mage"){
               image.load(":/mage.png");
            }else if(ui->hs_type->text()=="Druid"){
               image.load(":/druid.png");
            }else if(ui->hs_type->text()=="Hunter"){
               image.load(":/hunter.png");
            }else if(ui->hs_type->text()=="Shaman"){
               image.load(":/shaman.png");
            }else if(ui->hs_type->text()=="Paladin"){
               image.load(":/paladin.png");
            }else if(ui->hs_type->text()=="Warlock"){
               image.load(":/warlock.png");
            }else{
               image.load(":/rogue.png");
            }

            ui->hs_label->setPixmap(QPixmap::fromImage(image));
        }
    }
    {
        ui->hs_name->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getName().c_str()));
        ui->hs_type->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getType().c_str()));
        int manacost = players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getManacost();
        QString tochange = QString::number(manacost);
        ui->hs_manacost->setText(tochange);
        QImage image;
        if(ui->hs_type->text()=="Priest"){
           image.load(":/priest.png");
        }else if(ui->hs_type->text()=="Warrior"){
           image.load(":/warrior.png");
        }else if(ui->hs_type->text()=="Mage"){
           image.load(":/mage.png");
        }else if(ui->hs_type->text()=="Druid"){
           image.load(":/druid.png");
        }else if(ui->hs_type->text()=="Hunter"){
           image.load(":/hunter.png");
        }else if(ui->hs_type->text()=="Shaman"){
           image.load(":/shaman.png");
        }else if(ui->hs_type->text()=="Paladin"){
           image.load(":/paladin.png");
        }else if(ui->hs_type->text()=="Warlock"){
           image.load(":/warlock.png");
        }else{
           image.load(":/rogue.png");
        }

        ui->hs_label->setPixmap(QPixmap::fromImage(image));
    }
    ui->race_label->setPixmap(QPixmap::fromImage(image));{
        ui->hs_name->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getName().c_str()));
        ui->hs_type->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getType().c_str()));
        int manacost = players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getManacost();
        QString tochange = QString::number(manacost);
        ui->hs_manacost->setText(tochange);
        QImage image;
        if(ui->hs_type->text()=="Priest"){
           image.load(":/priest.png");
        }else if(ui->hs_type->text()=="Warrior"){
           image.load(":/warrior.png");
        }else if(ui->hs_type->text()=="Mage"){
           image.load(":/mage.png");
        }else if(ui->hs_type->text()=="Druid"){
           image.load(":/druid.png");
        }else if(ui->hs_type->text()=="Hunter"){
           image.load(":/hunter.png");
        }else if(ui->hs_type->text()=="Shaman"){
           image.load(":/shaman.png");
        }else if(ui->hs_type->text()=="Paladin"){
           image.load(":/paladin.png");
        }else if(ui->hs_type->text()=="Warlock"){
           image.load(":/warlock.png");
        }else{
           image.load(":/rogue.png");
        }

        ui->hs_label->setPixmap(QPixmap::fromImage(image));
    }


}

void characterwindow::on_d3_createcharbut_clicked()
{
    QString name = ui->d3_name_2->text();
    QString type = ui->d3_cbtype->currentText();
    string gender;
    if(ui->d3rb_f->isChecked()){
        gender = "Female";
    }else{
        gender = "Male";
    }
    int level = ui->d3_cblevel->value();
    wdchar a(name.toStdString(),"Diablo III",level,type.toStdString(),"human",gender);
    players->at(0).setd3char(a);
    QMessageBox::information(this,"Create","Succesfully Created Character!");

    ui->d3_name_2->setText("");
    ui->d3_cblevel->setValue(1);
}

void characterwindow::on_pushButton_2_clicked()
{
    ui->d3_chars->clear();
    for(unsigned i;i<players->at(0).getMyd3chars().size();i++){
        ui->d3_chars->addItem(QString(players->at(0).getMyd3chars().at(i).getName().c_str()));
    }

}

void characterwindow::on_d3_selectbut_clicked()
{
    ui->d3_name->setText(QString(players->at(0).getMyd3chars().at(ui->d3_chars->currentIndex()).getName().c_str()));
    ui->d3_type->setText(QString(players->at(0).getMyd3chars().at(ui->d3_chars->currentIndex()).getType().c_str()));
    ui->d3_gender->setText(QString(players->at(0).getMyd3chars().at(ui->d3_chars->currentIndex()).getGender().c_str()));
    int level = players->at(0).getMyd3chars().at(ui->d3_chars->currentIndex()).getLevel();
    QString tochange = QString::number(level);
    ui->d3_level->setText(tochange);
    QImage image;
    if(ui->d3_type->text()=="Barbarian"){
       image.load(":/barbarian.png");
    }else if(ui->d3_type->text()=="Wizard"){
       image.load(":/wizard.png");
    }else if(ui->d3_type->text()=="DemonHunter"){
       image.load(":/demonhunter.png");
    }else if(ui->d3_type->text()=="Monk"){
       image.load(":/monk.png");
    }else{
       image.load(":/witchdoctor.png");
    }

    ui->type_label->setPixmap(QPixmap::fromImage(image));
}

void characterwindow::on_hs_createcardbut_clicked()
{
    QString name = ui->hs_name_2->text();
    QString type = ui->hs_cbtype->currentText();
    int manacost = ui->hs_cbmanacost->value();
    QString info = ui->hs_cbinfo->toPlainText();
    hschar a(name.toStdString(),"Hearthstone",type.toStdString(),info.toStdString(),manacost);
    players->at(0).sethschar(a);
    QMessageBox::information(this,"Create","Succesfully Added Card!");

    ui->hs_name_2->setText("");
    ui->hs_cbinfo->setText("");
    ui->hs_cbmanacost->setValue(1);
}

void characterwindow::on_hs_selectbut_clicked()
{
    ui->hs_name->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getName().c_str()));
    ui->hs_type->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getType().c_str()));
    ui->hs_info->setText(QString(players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getInfo().c_str()));
    int manacost = players->at(0).getMyhschars().at(ui->hs_chars->currentIndex()).getManacost();
    QString tochange = QString::number(manacost);
    ui->hs_manacost->setText(tochange);
    QImage image;
    if(ui->hs_type->text()=="Priest"){
       image.load(":/priest.png");
    }else if(ui->hs_type->text()=="Warrior"){
       image.load(":/warrior.png");
    }else if(ui->hs_type->text()=="Mage"){
       image.load(":/mage.png");
    }else if(ui->hs_type->text()=="Druid"){
       image.load(":/druid.png");
    }else if(ui->hs_type->text()=="Hunter"){
       image.load(":/hunter.png");
    }else if(ui->hs_type->text()=="Shaman"){
       image.load(":/shaman.png");
    }else if(ui->hs_type->text()=="Paladin"){
       image.load(":/paladin.png");
    }else if(ui->hs_type->text()=="Warlock"){
       image.load(":/warlock.png");
    }else{
       image.load(":/rogue.png");
    }

    ui->hs_label->setPixmap(QPixmap::fromImage(image));
}

void characterwindow::on_pushButton_3_clicked()
{
    ui->hs_chars->clear();
    for(unsigned i;i<players->at(0).getMyhschars().size();i++){
        ui->hs_chars->addItem(QString(players->at(0).getMyhschars().at(i).getName().c_str()));
    }
}
