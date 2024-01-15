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
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/chicknvoic.mp3"));
    player->setVolume(100);
    player->play();
    int number_of_chicken=0;
    QFile chicken("D:/faz2/faz2/fils/chickenland.txt");
    QTextStream in(&chicken);
    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->lineEdit_chicken_2->setText(QString::number(number_of_chicken));
}

chicken::~chicken()
{
    delete ui;
}

void chicken::on_toolButton_clicked()
{
    player->stop();
}

