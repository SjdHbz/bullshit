#include "butcher.h"
#include "ui_butcher.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

Butcher::Butcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Butcher)
{
    ui->setupUi(this);
    int coin = incoin();
    ui->lineEdit_coins->setText(QString::number(coin));

    int number_of_chicken;
    QFile chicken("D:/faz2/faz2/number_of_chicken.txt");
    QTextStream in(&chicken);
    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->label_Chicken_Meat->setText(QString::number(number_of_chicken));

    int number_of_cow;
    QFile cow("D:/faz2/faz2/number_of_cow.txt");
    QTextStream in1(&cow);
    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in1 >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->label_cow_Meat->setText(QString::number(number_of_cow));

    int number_of_sheep;
    QFile sheep("D:/faz2/faz2/number_of_sheep.txt");
    QTextStream in2(&sheep);
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in2 >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->label_Sheep_Meat->setText(QString::number(number_of_sheep));

}


void Butcher::outcoin(int coin)
{

        QFile file("D:/faz2/faz2/coin.txt");
        QTextStream out(&file);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            out<<coin;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
        }
}


int Butcher::incoin()
{
        int coin;
        QFile file("D:/faz2/faz2/coin.txt");
        QTextStream in(&file);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            in >> coin;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
        }
        return coin;
}


Butcher::~Butcher()
{
    delete ui;
}

void Butcher::on_pushButton_kill_Chicken_clicked()
{
    int number_of_chicken;
    int coin = incoin();
    QFile chicken("D:/faz2/faz2/number_of_chicken.txt");
    QTextStream in(&chicken);
    QTextStream out(&chicken);

    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    if(number_of_chicken>0){
        number_of_chicken--;
        coin += 2;
        outcoin(coin);
    }
    if(chicken.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->label_Chicken_Meat->setText(QString::number(number_of_chicken));
    ui->lineEdit_coins->setText(QString::number(coin));
}


void Butcher::on_pushButton_kill_cow_clicked()
{
    int number_of_cow;
    int coin = incoin();
    QFile cow("D:/faz2/faz2/number_of_cow.txt");
    QTextStream in(&cow);
    QTextStream out(&cow);

    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    if(number_of_cow > 0){
        number_of_cow--;
        coin += 6;
        outcoin(coin);
    }
    if(cow.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->label_cow_Meat->setText(QString::number(number_of_cow));
    ui->lineEdit_coins->setText(QString::number(coin));
}


void Butcher::on_pushButton_kill_Sheep_clicked()
{
    int number_of_sheep;
    int coin = incoin();
    QFile sheep("D:/faz2/faz2/number_of_sheep.txt");
    QTextStream in(&sheep);
    QTextStream out(&sheep);

    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    if(number_of_sheep>0){
        number_of_sheep--;
        coin += 4;
        outcoin(coin);
    }
    if(sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->label_Sheep_Meat->setText(QString::number(number_of_sheep));
    ui->lineEdit_coins->setText(QString::number(coin));
}

