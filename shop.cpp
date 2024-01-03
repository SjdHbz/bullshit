#include "shop.h"
#include "ui_shop.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

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
int number_of_corn;
int number_of_land;
int number_of_worker;
shop::shop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::shop)
{
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


//void shop::on_pushButton_chicken_clicked()
//{
//    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){

//    if(coin>=3){
//    int k = ui-> lineEdit_chicken ->text().toInt();
//    number_of_chicken=number_of_chicken+k/3;
//    coin = coin-k;
//    out >> coin;
//    ui->spinBox_chicken->clear();
//    ui->lineEdit_chicken->clear();
//    ui->lineEdit_chicken->setEnabled(true);
//    }
//    else {
//        ui->spinBox_chicken->clear();
//        ui->lineEdit_chicken->clear();
//        ui->lineEdit_chicken->setEnabled(false);
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//    }
//    file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");
//    }
//}
void shop::on_pushButton_chicken_clicked()
{
    int selectedQuantity = ui->spinBox_chicken->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 5; // محاسبه مجموعه آن جنس
    QFile chicken("D:/faz2/faz2/number_of_chicken.txt");
    QTextStream in(&chicken);
    QTextStream out(&chicken);

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
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
        QFile file("D:/faz2/faz2/coin.txt");

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << coin;
            file.close();
        }
     else {
        // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
      }
        // تاکید بر نکاتی برای UI
        ui->spinBox_chicken->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->lineEdit_chicken->clear();
        }else {
       // اعلام خطا از نظر تعداد سکه
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}

//void shop::on_pushButton_cow_clicked()
//{
//    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
//    if(coin>=7){
//    int k = ui->lineEdit_cow->text().toInt();
//    push.number_of_cows=push.number_of_cows+k/7;
//    coin = coin - k;
//    men.set_coin(set);
//    out >> coin;
//    ui->spinBox_cow->clear();
//    ui->lineEdit_cow->clear();
//    ui->lineEdit_cow->setEnabled(true);

//    }
//    else {
//        ui->spinBox_cow->clear();
//        ui->lineEdit_cow->clear();
//        ui->lineEdit_cow->setEnabled(false);
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//    }
//     file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");
//    }
//}
void shop::on_pushButton_cow_clicked(){
    int selectedQuantity = ui->spinBox_cow->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 7; // محاسبه مجموعه آن جنس
    QFile cow("D:/faz2/faz2/number_of_cow.txt");
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
        QFile file("D:/faz2/faz2/coin.txt");

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << coin;
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

//void shop::on_pushButton_sheep_clicked()
//{
//    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
//    if(coin>=5){
//    int k = ui->lineEdit_sheep->text().toInt();
//    push.number_of_sheep=push.number_of_sheep+k/5;
//    coin = coin-k;
//    men.set_coin(set);
//    out >> coin;
//    ui->spinBox_sheep->clear();
//    ui->lineEdit_sheep->clear();
//    ui->lineEdit_sheep->setEnabled(true);
//    }
//    else {
//        ui->spinBox_sheep->clear();
//        ui->lineEdit_sheep->clear();
//        ui->lineEdit_sheep->setEnabled(false);
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//    }
//     file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");
//    }
//}



void shop::on_pushButton_sheep_clicked()
{

    int selectedQuantity = ui->spinBox_sheep->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 5; // محاسبه مجموعه آن جنس
    QFile sheep("D:/faz2/faz2/number_of_sheep.txt");   
    QTextStream in(&sheep);
    QTextStream out(&sheep);

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
        coin -= totalPrice; // کم کردن سکه‌ها
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
        QFile file("D:/faz2/faz2/coin.txt");

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
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


//void shop::on_pushButton_wheat_buy_clicked()
//{
//    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
//    if(coin>=2){
//    int k = ui->lineEdit_wheat_buy->text().toInt();
////    push.number_of_wheat=push.number_of_wheat+k/2;
//    coin = coin-k;
//    //men.set_coin(set);
//    out >> coin;
//    ui->spinBox_wheat->clear();
//    ui->lineEdit_wheat_buy->clear();
//    ui->lineEdit_wheat_buy->setEnabled(true);
//    }
//    else {
//        ui->spinBox_wheat->clear();
//        ui->lineEdit_wheat_buy->clear();
//        ui->lineEdit_wheat_buy->setEnabled(false);
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//    }
//     file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");
//    }
//}
void shop::on_pushButton_wheat_buy_clicked()
{
    int selectedQuantity = ui->spinBox_wheat->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 2; // محاسبه مجموعه آن جنس
    //
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

        QFile file("D:/faz2/faz2/coin.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << coin;
            file.close();
        }
        // تاکید بر نکاتی برای UI
        ui->spinBox_wheat->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
    } else {
        // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
    }
    ui->lineEdit_wheat_buy->clear();
}

//void shop::on_pushButton_cron_buy_clicked()
//{
//    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
//    if(coin>=2){
//    int k = ui->lineEdit_cron_buy->text().toInt();
////    push.number_of_corn=push.number_of_corn+k/2;
//    coin=coin-k;
//    //men.set_coin(set);
//    out >> coin;
//    ui->spinBox_cron->clear();
//    ui->lineEdit_cron_buy->clear();
//    ui->lineEdit_cron_buy->setEnabled(true);

//    }
//    else {
//        ui->spinBox_cron->clear();
//        ui->lineEdit_cron_buy->clear();
//        ui->lineEdit_cron_buy->setEnabled(false);
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//    }
//     file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");
//    }
//}

void shop::on_pushButton_cron_buy_clicked()
{
    int selectedQuantity = ui->spinBox_cron->value(); // تعداد انتخاب شده توسط کاربر از spinBox
    int totalPrice = selectedQuantity * 2; // محاسبه مجموعه آن جنس
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
        QFile file("D:/faz2/faz2/coin.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << coin;
            file.close();
        }
        // تاکید بر نکاتی برای UI
        ui->spinBox_cron->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
    } else {
        // اعلام خطا از نظر تعداد سکه
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
    }
    ui->lineEdit_cron_buy->clear();
}
