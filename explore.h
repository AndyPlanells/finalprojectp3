#ifndef EXPLORE_H
#define EXPLORE_H

#include <QDialog>

namespace Ui {
class explore;
}

class explore : public QDialog
{
    Q_OBJECT

public:
    explicit explore(QWidget *parent = 0);
    ~explore();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();
    
    void on_pushButton_3_clicked();
    
    void on_pushButton_4_clicked();
    
    void on_pushButton_5_clicked();
    
    void on_pushButton_6_clicked();
    
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_hs_text_destroyed();

    void on_pushButton_12_clicked();

private:
    Ui::explore *ui;
};

#endif // EXPLORE_H
