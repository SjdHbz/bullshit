#include "land.h"
#include "ui_land.h"
#include "Score.h"
#include "first.h"
#include "QMessageBox"
land::land(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::land)
{
    ui->setupUi(this);
}

land::~land()
{
    delete ui;
}



void land::on_spinBox_land_valueChanged(int arg1)
{
    first men;
    int num;
    num = arg1 * 3;
    if(men.coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_land->setText(QString::number(num));
}


void land::on_spinBox_worker_valueChanged(int arg1)
{
    first men;
    int num;
    num = arg1 * 5;
    if(men.coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");

        num = 0;
    }
    ui->lineEdit_worker->setText(QString::number(num));
}


void land::on_pushButton_land_clicked()
{
    first men;
    MyGame::Score push;
    if(men.coin>=3){
    int k = ui->lineEdit_land->text().toInt();
    push.number_of_land=push.number_of_land+k/3;
    int set=men.coin-k;
    men.set_coin(set);
    ui->spinBox_land->clear();
    ui->lineEdit_land->clear();
    }
    else {
        ui->spinBox_land->clear();
        ui->lineEdit_land->clear();
        QMessageBox::warning(this,"EROR","You don't have enough coins");
    }
}


void land::on_pushButton_worker_clicked()
{

    first men;
    MyGame::Score push;
    if(men.coin>=5){
    int k = ui->lineEdit_worker->text().toInt();
    push.number_of_worker = push.number_of_worker+k/5;
    int set=men.coin-k;
    men.set_coin(set);
    ui->spinBox_worker->clear();
    ui->lineEdit_worker->clear();
    }
    else {
        ui->spinBox_worker->clear();
        ui->lineEdit_worker->clear();
        QMessageBox::warning(this,"EROR","You don't have enough coins");
    }

}


void land::on_pushButton_clicked()
{
    first men;
    ui->lineEdit->setText(QString::number(men.coin));
}

