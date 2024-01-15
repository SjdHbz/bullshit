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
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/sheepsound.mp3"));
    player->setVolume(100);
    player->play();
    int number_of_sheep=0;
    QFile sheep("D:/faz2/faz2/fils/sheeplan.txt");
    QTextStream in(&sheep);
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
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

