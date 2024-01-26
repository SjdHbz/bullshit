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

    int number_of_chicken=0;
    QFile chicken("D:/faz2/faz2/fils/chickenland.txt");
    QTextStream in(&chicken);
    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->label_Chicken_Meat->setText(QString::number(number_of_chicken));

    int number_of_cow=0;
    QFile cow("D:/faz2/faz2/fils/cowland.txt");
    QTextStream in1(&cow);
    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in1 >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->label_cow_Meat->setText(QString::number(number_of_cow));

    int number_of_sheep=0;
    QFile sheep("D:/faz2/faz2/fils/sheeplan.txt");
    QTextStream in2(&sheep);
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in2 >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->label_Sheep_Meat->setText(QString::number(number_of_sheep));

}


void Butcher::outcoin(int coin)
{

        QFile file("D:/faz2/faz2/fils/coin.txt");
        QTextStream out(&file);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            out<<coin;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
}


int Butcher::incoin()
{

        int coin=0;
        QFile file("D:/faz2/faz2/fils/coin.txt");
        QTextStream in(&file);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
            in >> coin;
            file.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        return coin;
}


void Butcher::coin_voices(){
    coin_voice->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/coin.mp3"));
    coin_voice->setVolume(100);
    coin_voice->play();
}

Butcher::~Butcher()
{
    delete ui;
}

void Butcher::on_pushButton_kill_Chicken_clicked()
{
    int number_of_chicken=0;
    int coin = incoin();
    int kill=0;
    int numof_chicken=0;

    QFile chicken("D:/faz2/faz2/fils/chickenland.txt");
    QFile numchicken("D:/faz2/faz2/fils/number_of_chicken.txt");
    QFile kill_sheep("D:/faz2/faz2/fils/kill_chicken.txt");

    QTextStream in(&chicken);
    QTextStream out(&chicken);
    QTextStream stream(&kill_sheep);
    QTextStream stream1(&numchicken);

    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(numchicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> number_of_chicken;
        numchicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_chicken>0){
        number_of_chicken--;
        kill=1;
        coin += 2;
        numof_chicken--;
        outcoin(coin);
        coin_voices();
    }
    if(numchicken.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << number_of_chicken;
        numchicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(kill_sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << kill;
        kill_sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(chicken.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->label_Chicken_Meat->setText(QString::number(number_of_chicken));
    ui->lineEdit_coins->setText(QString::number(coin));
}


void Butcher::on_pushButton_kill_cow_clicked()
{
    int number_of_cow=0;
    int coin = incoin();
    int kill=0;
    int numof_chicken=0;
    QFile cow("D:/faz2/faz2/fils/cowland.txt");
    QFile kill_sheep("D:/faz2/faz2/fils/kill_cow.txt");
    QFile numchicken("D:/faz2/faz2/fils/number_of_cow.txt");

    QTextStream in(&cow);
    QTextStream out(&cow);
    QTextStream stream(&kill_sheep);
    QTextStream stream1(&numchicken);


    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(numchicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> numof_chicken;
        numchicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_cow > 0){
        number_of_cow--;
        numof_chicken--;
        kill=1;
        coin += 6;
        outcoin(coin);
        coin_voices();
    }
    if(numchicken.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream1 << numof_chicken;
        numchicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(kill_sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << kill;
        kill_sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(cow.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->label_cow_Meat->setText(QString::number(number_of_cow));
    ui->lineEdit_coins->setText(QString::number(coin));
}


void Butcher::on_pushButton_kill_Sheep_clicked()
{
    int number_of_sheep=0;
    int coin = incoin();
    int kill=0;
    int numof_sheep=0;
    QFile sheep("D:/faz2/faz2/fils/sheeplan.txt");
    QFile kill_sheep("D:/faz2/faz2/fils/kill_sheep.txt");
    QFile numsheep("D:/faz2/faz2/fils/number_of_sheep.txt");


    QTextStream in(&sheep);
    QTextStream out(&sheep);
    QTextStream stream(&kill_sheep);
    QTextStream stream2(&numsheep);


    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(numsheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> numof_sheep;
        numsheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(number_of_sheep>0){
        number_of_sheep--;
        kill=1;
        numof_sheep--;
        coin += 4;
        outcoin(coin);
        coin_voices();
    }
    if(kill_sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << kill;
        kill_sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(numsheep.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream2 << numof_sheep;
        numsheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    if(sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
        out << number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->label_Sheep_Meat->setText(QString::number(number_of_sheep));
    ui->lineEdit_coins->setText(QString::number(coin));
}

