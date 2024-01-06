#include "chicken.h"
#include "ui_chicken.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

chicken::chicken(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chicken)
{
    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/chicknvoic.mp3"));
    player->setVolume(100);
    player->play();
    ui->lineEdit_chicken->setReadOnly(true);
    int number_of_chicken;
    QFile chicken("D:/faz2/faz2/number_of_chicken.txt");
    QTextStream in(&chicken);
    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->lineEdit_chicken->setText(QString::number(number_of_chicken));
}

chicken::~chicken()
{
    delete ui;
}

void chicken::on_toolButton_clicked()
{
    player->stop();
}

