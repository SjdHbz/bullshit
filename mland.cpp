#include "mland.h"
#include "ui_mland.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
mland::mland(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mland)
{
    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/lansvoic.mp3"));
    player->setVolume(100);
    player->play();
    ui->lineEdit_land->setReadOnly(true);

    int number_of_land;
    QFile land("D:/faz2/faz2/number_of_land.txt");
    QTextStream in(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->lineEdit_land->setText(QString::number(number_of_land));
    int number_of_wheat = 0;
    QFile wheat("D:/faz2/faz2/number_of_wheat.txt");
    QTextStream stream(&wheat);
    if(wheat.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream >> number_of_wheat;
        wheat.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->lineEdit_wheat->setText(QString::number(number_of_wheat));

    int number_of_cron = 0;
    QFile cron("D:/faz2/faz2/number_of_cron.txt");
    QTextStream stream1(&cron);
    if(cron.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> number_of_cron;
        cron.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->lineEdit_cron->setText(QString::number(number_of_cron));


}

mland::~mland()
{
    delete ui;
}

void mland::on_toolButton_clicked()
{
    player->stop();
}

