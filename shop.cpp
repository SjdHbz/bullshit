#include "shop.h"
#include "ui_shop.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include <QMediaPlayer>
int coin;
int number_of_chicken;
int number_of_cow;
int number_of_cow_meat;
int number_of_cow_milk;
int number_of_sheep;
int number_of_sheep_milk;
int number_of_sheep_meat;
int number_of_chicken_egg;
int number_of_chicken_meat;
int number_of_wheat;
int number_of_cron;
int number_of_land;
int number_of_worker;
shop::shop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shop)
{
    player->setMedia(QUrl::fromLocalFile("D:/faz2/faz2/market-voices.mp3"));
    player->setVolume(100);
    player->play();
    ui->setupUi(this);
    ui->lineEdit_chicken->setReadOnly(true);
    ui->lineEdit_chicken_egg->setReadOnly(true);
    ui->lineEdit_chickn_mat->setReadOnly(true);
    ui->lineEdit_coins->setReadOnly(true);
    ui->lineEdit_cow->setReadOnly(true);
    ui->lineEdit_cow_mat->setReadOnly(true);
    ui->lineEdit_cow_milk->setReadOnly(true);
    ui->lineEdit_cron_buy->setReadOnly(true);
    ui->lineEdit_cron_sale->setReadOnly(true);
    ui->lineEdit_sheep->setReadOnly(true);
    ui->lineEdit_sheep_mat->setReadOnly(true);
    ui->lineEdit_sheep_milk->setReadOnly(true);
    ui->lineEdit_wheat_buy->setReadOnly(true);
    ui->lineEdit_wheat_sale->setReadOnly(true);

    QFile file("D:/faz2/faz2/coin.txt");
    QTextStream in(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> coin;
        file.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
}

shop::~shop()
{
    delete ui;
}



void shop::on_spinBox_chicken_valueChanged(int arg1)
{
//    file.open(QIODevice::WriteOnly | QIODevice::Text);
    int num;
    num = arg1 * 3;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_chicken->setText(QString::number(num));

}


void shop::on_spinBox_chicken_egg_valueChanged(int arg1)
{
    int num;
    num = arg1 * 3;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_chicken_egg->setText(QString::number(num));
}


void shop::on_spinBox_chickn_mat_valueChanged(int arg1)
{
    int num;
    num = arg1 * 2;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_chickn_mat->setText(QString::number(num));
}


void shop::on_spinBox_cow_valueChanged(int arg1)
{
    int num;
    num = arg1 * 7;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_cow->setText(QString::number(num));
}


void shop::on_spinBox_cow_milk_valueChanged(int arg1)
{
    int num;
    num = arg1 * 5;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_cow_milk->setText(QString::number(num));
}


void shop::on_spinBox_cow_mat_valueChanged(int arg1)
{
    int num;
    num = arg1 * 6;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_cow_mat->setText(QString::number(num));
}


void shop::on_spinBox_sheep_valueChanged(int arg1)
{
    int num;
    num = arg1 * 5;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_sheep->setText(QString::number(num));
}


void shop::on_spinBox_sheep_milk_valueChanged(int arg1)
{
    int num;
    num = arg1 * 3;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_sheep_milk->setText(QString::number(num));
}


void shop::on_spinBox_sheep_mat_valueChanged(int arg1)
{
    int num;
    num = arg1 * 4;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        num = 0;
    }
    ui->lineEdit_sheep_mat->setText(QString::number(num));
}


void shop::on_spinBox_wheat_valueChanged(int arg1)
{
    int num;
    num = arg1 * 2;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        arg1 = 0;
        num = 0;
    }
    int Num;
    Num = arg1 * 3;
    ui->lineEdit_wheat_buy->setText(QString::number(num));
    ui->lineEdit_wheat_sale->setText(QString::number(Num));
}


void shop::on_spinBox_cron_valueChanged(int arg1)
{
    int num;
    num = arg1 * 2;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");
        arg1 = 0;
        num = 0;
    }
    int Num;
    Num = arg1 * 2;
    ui->lineEdit_cron_buy->setText(QString::number(num));
    ui->lineEdit_cron_sale->setText(QString::number(Num));
}


void shop::on_pushButton_chicken_clicked()
{
    int selectedQuantity = ui->spinBox_chicken->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 3; // محاسبه مجموعه آن جنس
    QFile chicken("D:/faz2/faz2/number_of_chicken.txt");
    QFile file("D:/faz2/faz2/coin.txt");

    QTextStream in(&chicken);
    QTextStream out(&chicken);
    QTextStream out1(&file);

    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
        return;
    }
    number_of_chicken += selectedQuantity;
    if (chicken.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_chicken;
        chicken.close();
    }else {                                                                              // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1 << coin;
            file.close();
        }
     else {
        // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
      }
        // تاکید بر نکاتی برای UI
        ui->spinBox_chicken->setValue(0);                           // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->lineEdit_chicken->clear();
        }else {
                                                                                        // اعلام خطا از نظر تعداد سکه
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}


void shop::on_pushButton_cow_clicked(){
    int selectedQuantity = ui->spinBox_cow->value();                    // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 7; // محاسبه مجموعه آن جنس
    QFile cow("D:/faz2/faz2/number_of_cow.txt");
    QFile file("D:/faz2/faz2/coin.txt");
    QTextStream out1(&file);

    QTextStream in(&cow);
    QTextStream out(&cow);

    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
        return;
    }
    number_of_cow += selectedQuantity;
    if (cow.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_cow;
        cow.close();
    }else{                                                                              // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
                                                                            // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1 << coin;
            file.close();
        }
     else {
                                                                               // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
      }
                                                                                                     // تاکید بر نکاتی برای UI
        ui->spinBox_cow->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->lineEdit_cow->clear();
        }else{
                                                                                                // اعلام خطا از نظر تعداد سکه
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}

void shop::on_pushButton_sheep_clicked()
{

    int selectedQuantity = ui->spinBox_sheep->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 5; // محاسبه مجموعه آن جنس
    QFile sheep("D:/faz2/faz2/number_of_sheep.txt");
    QFile file("D:/faz2/faz2/coin.txt");

    QTextStream in(&sheep);
    QTextStream out(&sheep);
    QTextStream out1(&file);

    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
        return;
    }
    number_of_sheep += selectedQuantity;
    if (sheep.open(QIODevice::WriteOnly | QIODevice::Text)) {       
        out << number_of_sheep;
        sheep.close();
    }else {                                                                              // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice;                                                                 // کم کردن سکه‌ها
                                                                                         // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out << coin;
            file.close();
        }    
     else {
                                                                                        // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
      }
                                                                                     // تاکید بر نکاتی برای UI
        ui->spinBox_sheep->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->lineEdit_sheep->clear();
        }else {
                                                                                     // اعلام خطا از نظر تعداد سکه
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}


void shop::on_pushButton_wheat_buy_clicked()
{
    int selectedQuantity = ui->spinBox_wheat->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 2; // محاسبه مجموعه آن جنس
    QFile wheat("D:/faz2/faz2/number_of_wheat.txt");
    QFile file("D:/faz2/faz2/coin.txt");

    QTextStream in(&wheat);
    QTextStream out(&wheat);
        QTextStream out1(&file);
    if(wheat.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_wheat;
        wheat.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                             // اگر فایل باز نشده باشد ارور میدهد
        return;
    }
    number_of_wheat += selectedQuantity;
    if (wheat.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_wheat;
        wheat.close();
    }else {                                                                           // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
                                                                                      // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1<< coin;
            file.close();
        }
     else {
                                                                                       // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
      }
                                                                                       // تاکید بر نکاتی برای UI
        ui->spinBox_wheat->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->lineEdit_wheat_buy->clear();
        }else {
                                                                                       // اعلام خطا از نظر تعداد سکه
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}

void shop::on_pushButton_cron_buy_clicked()
{
    int selectedQuantity = ui->spinBox_cron->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 2; // محاسبه مجموعه آن جنس
    QFile cron("D:/faz2/faz2/number_of_cron.txt");
    QFile file("D:/faz2/faz2/coin.txt");
    QTextStream out1(&file);
    QTextStream in(&cron);
    QTextStream out(&cron);

    if(cron.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_cron;
        cron.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                             // اگر فایل باز نشده باشد ارور میدهد
        return;
    }
    number_of_cron += selectedQuantity;
    if (cron.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_cron;
        cron.close();
    }else {                                                                           // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
                                                                                      // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1 << coin;
            file.close();
        }
     else {
                                                                                       // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
      }
                                                                                       // تاکید بر نکاتی برای UI
        ui->spinBox_cron->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->lineEdit_cron_buy->clear();
        }else {
                                                                                       // اعلام خطا از نظر تعداد سکه
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

        }
}

void shop::on_toolButton_clicked()
{
        player->stop();
}

