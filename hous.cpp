#include "hous.h"
#include "ui_hous.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
hous::hous(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hous)
{
    ui->setupUi(this);
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/musicfil/homvoic.mp3"));
    player->setVolume(100);
    player->play();
    int number_of_chicken;
    int number_of_cow;
    int number_of_cow_mat;
    int number_of_cow_milk;
    int number_of_sheep;
    int number_of_sheep_milk;
    int number_of_sheep_mat;
    int number_of_chicken_egg;
    int number_of_chicken_mat;
    int number_of_wheat;
    int number_of_corn;

    QFile chicken("D:/faz2/faz2/fils/number_of_chicken.txt");
    QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");
    QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");
    QFile cow_mat("D:/faz2/faz2/fils/number_of_cow_mat.txt");
    QFile cow_milk("D:/faz2/faz2/fils/number_of_cow_milk.txt");
    QFile sheep_milk("D:/faz2/faz2/fils/number_of_sheep_milk.txt");
    QFile sheep_mat("D:/faz2/faz2/fils/number_of_sheep_mat.txt");
    QFile chicken_egg("D:/faz2/faz2/fils/number_of_chicken_egg.txt");
    QFile chicken_mat("D:/faz2/faz2/fils/number_of_chicken_mat.txt");
    QFile wheat("D:/faz2/faz2/fils/number_of_wheat.txt");
    QFile corn("D:/faz2/faz2/fils/number_of_cron.txt");

    QTextStream stream(&chicken);
    QTextStream in2(&cow);
    QTextStream in3(&sheep);
    QTextStream stream1(&cow_mat);
    QTextStream stream2(&cow_milk);
    QTextStream stream3(&sheep_milk);
    QTextStream stream4(&sheep_mat);
    QTextStream stream5(&chicken_egg);
    QTextStream stream6(&chicken_mat);
    QTextStream stream7(&wheat);
    QTextStream stream8(&corn);


    number_of_chicken = 0;
    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_cow = 0;
    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in2 >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_sheep = 0;
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in3 >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_cow_mat = 0;
    if(cow_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream1 >> number_of_cow_mat;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_cow_milk = 0;
    if(cow_milk.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream2 >> number_of_cow_milk;
        cow_milk.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_sheep_milk = 0;
    if(sheep_milk.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream3 >> number_of_sheep_milk;
        sheep_milk.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_sheep_mat = 0;
    if(sheep_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream4 >> number_of_sheep_mat;
        sheep_mat.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_chicken_egg = 0;
    if(chicken_egg.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream5 >> number_of_chicken_egg;
        chicken_egg.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_chicken_mat = 0;
    if(chicken_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream6 >> number_of_chicken_mat;
        chicken_mat.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_wheat = 0;
    if(wheat.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream7 >> number_of_wheat;
        wheat.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_corn = 0;
    if(corn.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream8 >> number_of_corn;
        corn.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    ui->lineEdit_chicken->setText(QString::number(number_of_chicken));
    ui->lineEdit_cow->setText(QString::number(number_of_cow));
    ui->lineEdit_sheep->setText(QString::number(number_of_sheep));
    ui->lineEdit_chicken_egg->setText(QString::number(number_of_chicken_egg));
    ui->lineEdit_chickn_mat->setText(QString::number(number_of_chicken_mat));
    ui->lineEdit_sheep_mat->setText(QString::number(number_of_sheep_mat));
    ui->lineEdit_sheep_milk->setText(QString::number(number_of_sheep_milk));
    ui->lineEdit_cow_mat->setText(QString::number(number_of_cow_mat));
    ui->lineEdit_cow_milk->setText(QString::number(number_of_cow_milk));
    ui->lineEdit_cron_sale->setText(QString::number(number_of_corn));
    ui->lineEdit_wheat_sale->setText(QString::number(number_of_wheat));
}


void hous::outcoin(int coin)
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


int hous::incoin()
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

hous::~hous()
{
    delete ui;
}

void hous::on_pushButton_chicken_clicked()
{
    int number_of_chicken=0;
    int coin;
    QFile file("D:/faz2/faz2/fils/coin.txt");
    QFile chicken("D:/faz2/faz2/fils/number_of_chicken.txt");

    QTextStream out(&file);
    QTextStream in(&file);
    QTextStream stream(&chicken);

    coin = incoin();

    int selectedQuantity = ui->spinBox_chicken->value();                    // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 3;                                       // محاسبه مجموعه آن جنس
    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }


    if (number_of_chicken > 0) {
        coin += totalPrice; // زیاد کردن سکه‌ها
        number_of_chicken -= selectedQuantity;
        if(chicken.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream << number_of_chicken;
            chicken.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
        outcoin(coin);
    }
    ui->spinBox_chicken->setValue(0);
    ui->lineEdit_chicken->setText(QString::number(number_of_chicken));

}


void hous::on_spinBox_chicken_valueChanged(int arg1)
{
        int number_of_chicken=0;
        QFile chicken("D:/faz2/faz2/fils/number_of_chicken.txt");
        if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&chicken);
            in >> number_of_chicken;
            chicken.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }

        if(number_of_chicken < arg1){
            QMessageBox::warning(this,"EROR","You don't have enough coins");
            ui->spinBox_chicken->setValue(0);
        }
}


void hous::on_pushButton_cow_clicked()
{
    int number_of_cow=0;
    int coin;
    QFile file("D:/faz2/faz2/fils/coin.txt");
    QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");

    QTextStream out(&file);
    QTextStream in(&file);
    QTextStream stream(&cow);

    coin = incoin();

    int selectedQuantity = ui->spinBox_cow->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 7; // محاسبه مجموعه آن جنس
    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }


    if (number_of_cow > 0) {
        coin += totalPrice; // زیاد کردن سکه‌ها
        number_of_cow -= selectedQuantity;
        if(cow.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream << number_of_cow;
            cow.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
        outcoin(coin);
    }
    ui->spinBox_cow->setValue(0);
    ui->lineEdit_cow->setText(QString::number(number_of_cow));

}


void hous::on_spinBox_cow_valueChanged(int arg1)
{
    int number_of_cow=0;
    QFile cow("D:/faz2/faz2/fils/number_of_cow.txt");
    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&cow);
        in >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    if(number_of_cow < arg1){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        ui->spinBox_cow->setValue(0);
    }
}


void hous::on_pushButton_sheep_clicked()
{

    int number_of_sheep=0;
    int coin;
    QFile file("D:/faz2/faz2/fils/coin.txt");
    QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");

    QTextStream out(&file);
    QTextStream in(&file);
    QTextStream stream(&sheep);

    coin = incoin();

    int selectedQuantity = ui->spinBox_sheep->value();                                   // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 5;                                               // محاسبه مجموعه آن جنس
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        stream >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }


    if (number_of_sheep > 0) {
        coin += totalPrice; // زیاد کردن سکه‌ها
        number_of_sheep -= selectedQuantity;
        if(sheep.open(QIODevice::WriteOnly | QIODevice::Text)){
            stream << number_of_sheep;
            sheep.close();
        }else{
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        }
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
        outcoin(coin);
    }
    ui->spinBox_sheep->setValue(0);
    ui->lineEdit_sheep->setText(QString::number(number_of_sheep));

}


void hous::on_spinBox_sheep_valueChanged(int arg1)
{
    int number_of_sheep=0;
    QFile sheep("D:/faz2/faz2/fils/number_of_sheep.txt");
    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&sheep);
        in >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }

    if(number_of_sheep < arg1){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        ui->spinBox_sheep->setValue(0);
    }
}


void hous::on_toolButton_clicked()
{
    player->stop();
}

