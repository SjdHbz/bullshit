#include "worker.h"
#include "ui_worker.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
worker::worker(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::worker)
{
    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/workrvoic.mp3"));
    player->setVolume(100);
    player->play();
    int number_of_worker;
    QFile worker("D:/faz2/faz2/fils/number_of_worker.txt");
    QTextStream in(&worker);
    if(worker.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_worker;
        worker.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->lineEdit_worker->setText(QString::number(number_of_worker));
}

worker::~worker()
{
    delete ui;
}

void worker::on_toolButton_clicked()
{
     player->stop();
}

