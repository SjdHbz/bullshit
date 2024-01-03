#include "sheep.h"
#include "ui_sheep.h"
#include "Score.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include <QMediaPlayer>

sheep::sheep(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sheep)
{

    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/sheepsound.mp3"));
    player->setVolume(100);
    player->play();
    ui->lineEdit_sheep->setReadOnly(true);
    int number_of_sheep;
    QFile sheep("D:/faz2/faz2/number_of_sheep.txt");
    QTextStream in(&sheep);
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->lineEdit_sheep->setText(QString::number(number_of_sheep));
}

sheep::~sheep()
{
    delete ui;
}




void sheep::on_toolButton_clicked()
{
    player->stop();
}

