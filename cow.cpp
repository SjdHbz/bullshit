#include "cow.h"
#include "ui_cow.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

cow::cow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cow)
{
    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/cow_voic.mp3"));
    player->setVolume(100);
    player->play();
    int number_of_cow;
    QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");
    QTextStream in(&cow);
    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->lineEdit_cow_2->setText(QString::number(number_of_cow));
}

cow::~cow()
{
    delete ui;
}

void cow::on_toolButton_clicked()
{
    player->stop();
}

