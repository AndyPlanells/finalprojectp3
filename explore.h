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

private:
    Ui::explore *ui;
};

#endif // EXPLORE_H
