#ifndef SHOP_H
#define SHOP_H

#include <QMainWindow>

namespace Ui {
class shop;
}

class shop : public QMainWindow
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr);
    ~shop();

private slots:

    void on_spinBox_chicken_valueChanged(int arg1);

    void on_spinBox_chicken_egg_valueChanged(int arg1);

    void on_spinBox_chickn_mat_valueChanged(int arg1);

    void on_spinBox_cow_valueChanged(int arg1);

    void on_spinBox_cow_milk_valueChanged(int arg1);

    void on_spinBox_cow_mat_valueChanged(int arg1);

    void on_spinBox_sheep_valueChanged(int arg1);

    void on_spinBox_sheep_milk_valueChanged(int arg1);

    void on_spinBox_sheep_mat_valueChanged(int arg1);

    void on_spinBox_wheat_valueChanged(int arg1);

    void on_spinBox_cron_valueChanged(int arg1);

    void on_pushButton_chicken_clicked();

    void on_pushButton_cow_clicked();

    void on_pushButton_sheep_clicked();

    void on_pushButton_wheat_buy_clicked();

    void on_pushButton_cron_buy_clicked();


private:
    Ui::shop *ui;
};

#endif // SHOP_H
