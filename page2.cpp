#include "page2.h"
#include "ui_page2.h"
#include "first.h"
#include <QTime>
#include <QTimer>
#include "time.h"
#include "QTimer"
#include "QTime"
#include "QLineEdit"
#include "shop.h"
#include "chicken.h"
#include "sheep.h"
#include "cow.h"
#include "land.h"
#include "mland.h"
#include "hous.h"
#include "worker.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

page2::page2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    QFile file("D:/faz2/faz2/coin.txt");
    QTextStream out(&file);
    int coin = 200;
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        out<<coin;
        file.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
        ui->pushButton->setEnabled(false);
    }
//    int number_of_chicken;
//    int number_of_cow;
//    int number_of_cow_meat;
//    int number_of_cow_milk;
//    int number_of_sheep;
//    int number_of_sheep_milk;
//    int number_of_sheep_meat;
//    int number_of_chicken_egg;
//    int number_of_chicken_meat;
//    int number_of_wheat;
//    int number_of_corn;
//    int number_of_land;
//    int number_of_worker;
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&page2::updateTime);
    timer->start(1000);
       ui->lineEdit_coin->setReadOnly(true);
       ui->lineEdit_worker->setReadOnly(true);
       ui->lineEdit_land->setReadOnly(true);
//       QFile chicken("D:/faz2/faz2/number_of_chicken.txt");
//       QFile cow("D:/faz2/faz2/number_of_cows.txt");
//       QFile sheep("D:/faz2/faz2/number_of_sheep.txt");
//       QTextStream stream(&file);
//       number_of_chicken = 1;
//       if(chicken.open(QIODevice::WriteOnly | QIODevice::Text)){
//           stream << number_of_chicken;
//           chicken.close();
//       }else{
//           QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//       }
//       number_of_cow = 1;
//       if(cow.open(QIODevice::WriteOnly | QIODevice::Text)){
//           stream << number_of_cow;
//           cow.close();
//       }else{
//           QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//       }
//       number_of_sheep = 1;
//       if(sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
//           stream << number_of_sheep;
//           sheep.close();
//       }else{
//           QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//       }

}


void page2::updateTime()
{
    static int seconds = 0;
    seconds++;

    if (seconds == 180) // check if 3 minutes have passed
    {


//         QApplication::quit(); // quit the application
    }

    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;

    ui->lcdNumber->display(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(remainingSeconds, 2, 10, QChar('0')));
}
page2::~page2()
{
    delete ui;
}




void page2::on_pushButton_3_clicked()
{
    shop* SHOP = new shop();
    SHOP->show();

}


void page2::on_pushButton__clicked()
{
    land* LAND = new land();
    LAND->show();

}


void page2::on_pushButton_2_clicked()
{
    land* LAND = new land();
    LAND->show();
}


void page2::on_pushButton_clicked()
{
    land* LAND = new land();
    LAND->show();

}


void page2::on_pushButton_5_clicked()
{
    QFile file("D:/faz2/faz2/coin.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int coin;
    in >> coin;
    ui->lineEdit_coin->setText(" = " + QString::number(coin));
    ui->lineEdit_worker->setText(" = " + QString::number(coin));
    ui->lineEdit_land->setText(" = " + QString::number(coin));
}


void page2::on_pushButton_6_clicked()
{
    sheep* SHEEP = new sheep();
    SHEEP ->show();
}


void page2::on_pushButton_1_clicked()
{
    cow* COW = new cow();
    COW ->show();
}


void page2::on_pushButton_7_clicked()
{
    mland* MLAND = new mland();
    MLAND ->show();
}


void page2::on_pushButton_4_clicked()
{
    hous* HOUS = new hous();
    HOUS ->show();
}



void page2::on_pushButton_8_clicked()
{
    chicken* CHICKEN = new chicken();
    CHICKEN ->show();
}


void page2::on_pushButton_10_clicked()
{
    worker* WORKER = new worker();
    WORKER ->show();
}

