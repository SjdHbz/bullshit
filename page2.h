#ifndef PAGE2_H
#define PAGE2_H
#include <QTime>
#include <QTimer>
#include <QMainWindow>
#include <QElapsedTimer>
#include "QMap"
#include "QPushButton"
#include "QLabel"
#include"QMediaPlayer"
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

    void refresh();

    void connct_timers();

    void outcoin(int coin);

    int incoin();

    int infile(QString fils);

    void outfil(QString fils , int coin);

    void basketss(int pric);

    void Wheat_push1();

    void Wheat_push2();

    void Wheat_push3();

    void Wheat_push4();

    void Wheat_push5();

    void Wheat_push6();

    void Wheat_push7();

    void Wheat_push8();

    void Wheat_push9();

    void Wheat_push10();

    void Wheat_push11();

    void Wheat_push12();

    void Wheat_push13();

    void Wheat_push14();

    void Corn_push1();

    void Corn_push2();

    void Corn_push3();

    void Corn_push4();

    void Corn_push5();

    void Corn_push6();

    void Corn_push7();

    void Corn_push8();

    void Corn_push9();

    void Corn_push10();

    void Corn_push11();

    void Corn_push12();

    void Corn_push13();

    void Corn_push14();

    void Cow_push1();

    void Cow_push2();

    void Cow_push3();

    void Cow_push4();

    void Cow_push5();

    void Cow_push6();

    void Cow_push7();

    void Cow_push8();

    void Cow_push9();

    void Cow_push10();

    void Cow_push11();

    void Cow_push12();

    void Cow_push13();

    void Cow_push14();

    void Chickeen_push1();

    void Chickeen_push2();

    void Chickeen_push3();

    void Chickeen_push4();

    void Chickeen_push5();

    void Chickeen_push6();

    void Chickeen_push7();

    void Chickeen_push8();

    void Chickeen_push9();

    void Chickeen_push10();

    void Chickeen_push11();

    void Chickeen_push12();

    void Chickeen_push13();

    void Chickeen_push14();

    void Sheep_push1();

    void Sheep_push2();

    void Sheep_push3();

    void Sheep_push4();

    void Sheep_push5();

    void Sheep_push6();

    void Sheep_push7();

    void Sheep_push8();

    void Sheep_push9();

    void Sheep_push10();

    void Sheep_push11();

    void Sheep_push12();

    void Sheep_push13();

    void Sheep_push14();

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

    void on_pushButton_basket_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_Butcher_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_look_2_clicked();

    void on_pushButton_look_3_clicked();

    void on_pushButton_look_4_clicked();

    void on_pushButton_look_5_clicked();

    void on_pushButton_look_6_clicked();

    void on_pushButton_look_7_clicked();

    void on_pushButton_look_8_clicked();

    void on_pushButton_look_9_clicked();

    void on_pushButton_look_10_clicked();

    void on_pushButton_look_11_clicked();

    void on_pushButton_look_12_clicked();

    void on_pushButton_look_13_clicked();

    void on_pushButton_look_14_clicked();

    void on_pushButton_wheat_clicked();

    void on_pushButton_corn_clicked();

    void on_pushButton_cow_clicked();

    void on_pushButton_chicken_clicked();

    void on_pushButton_sheep_clicked();

    void on_pushButton_basket_3_clicked();

    void on_pushButton_basket_4_clicked();

    void on_pushButton_basket_5_clicked();

    void on_pushButton_basket_6_clicked();

    void on_pushButton_basket_7_clicked();

    void on_pushButton_basket_8_clicked();

    void on_pushButton_basket_11_clicked();

    void on_pushButton_basket_10_clicked();

    void on_pushButton_basket_9_clicked();

    void on_pushButton_basket_12_clicked();

    void on_pushButton_basket_13_clicked();

    void on_pushButton_basket_14_clicked();

    void on_pushButton_11_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::page2 *ui;
    QMediaPlayer *music = new
    QMediaPlayer;
    QMediaPlayer *coin_voice = new
    QMediaPlayer;
    QTimer *timer;
    QElapsedTimer elapsedTimer;
//    QElapsedTimer elapsedwheat;
    int signl = 0;
    int play = 1;
    int pos=0;
    int late[15];
    QString Cultivations[15];
    int connct_wheat[15];
    int connct_corn[15];
    int connct_cow[15];
    int connct_chicken[15];
    int connct_Sheep[15];
    int kill_Sheep[15];
    int kill_chicken[15];
    int kill_cow[15];



};

#endif // PAGE2_H
