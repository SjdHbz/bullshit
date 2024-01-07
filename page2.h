#ifndef PAGE2_H
#define PAGE2_H
#include <QTime>
#include <QTimer>
#include <QMainWindow>
#include <QElapsedTimer>
#include "QMap"
#include "QPushButton"
#include "QLabel"
namespace Ui {
class page2;
}

class page2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = nullptr);

    ~page2();

private slots:
    void updateTime();

//    void updatewheat();

//    void updatecorn();

//    void updatecow();

//    void updatesheep();

//    void updatechicken();

    void refresh();

    void outcoin(int coin);

    void basketss(int pric);

    void on_pushButton_3_clicked();

    void on_pushButton__clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_basket_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::page2 *ui;
    QTimer *timer;
    QTimer *wheat;
    QElapsedTimer elapsedTimer;
    QElapsedTimer elapsedwheat;
    int sw;
    int play = 1;



};

#endif // PAGE2_H
