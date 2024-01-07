#include "shop.h"
#include "ui_shop.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include <QMediaPlayer>
int coin;
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

    QFile file("D:/faz2/faz2/coin.txt");
    QTextStream in(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> coin;
        file.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    ui->lineEdit_coins->setText(QString::number(coin));
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
        QMessageBox::warning(this,"EROR","You don't have enough coins");            // Declaring an error in terms of the number of coins
        num = 0;
    }
    ui->label_chicken->setText(QString::number(num));

}


//void shop::on_spinBox_chicken_egg_valueChanged(int arg1)
//{
//    int num;
//    num = arg1 * 3;
//    if(coin<num){
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//        num = 0;
//    }
//    ui->lineEdit_chicken_egg->setText(QString::number(num));
//}


//void shop::on_spinBox_chicken_egg_sale_valueChanged(int arg1)
//{
//    if(number_of_chicken_egg<arg1){
//        QMessageBox::warning(this,"EROR","You don't have enough chicken egg");
//        ui->spinBox_chicken_egg_sale->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_chicken_egg_sale->clear();

//    }
//    int num = arg1 * 3;
//    ui->lineEdit_chicken_egg_sale->setText(QString::number(num));
//}


//void shop::on_spinBox_chicken_mat_valueChanged(int arg1)
//{
//    int num;
//    num = arg1 * 2;
//    if(coin<num){
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//        num = 0;
//    }
//    ui->lineEdit_chicken_mat->setText(QString::number(num));
//}


//void shop::on_spinBox_chicken_mat_sale_valueChanged(int arg1)
//{
//    if(number_of_chicken_mat<arg1){
//        QMessageBox::warning(this,"EROR","You don't have enough chicken meat");
//        ui->spinBox_chicken_mat_sale->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_chicken_mat_sale->clear();

//    }
//    int num = arg1 * 2;
//    ui->lineEdit_chicken_mat_sale->setText(QString::number(num));
//}


void shop::on_spinBox_cow_valueChanged(int arg1)
{
    int num;
    num = arg1 * 7;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");                // Declaring an error in terms of the number of coins
        num = 0;
        ui->spinBox_cow->setValue(0);
    }
    ui->label_cow->setText(QString::number(num));
}


//void shop::on_spinBox_cow_milk_valueChanged(int arg1)
//{
//    int num;
//    num = arg1 * 5;
//    if(coin<num){
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//        num = 0;
//    }
//    ui->lineEdit_cow_milk->setText(QString::number(num));
//}


//void shop::on_spinBox_cow_milk_sale_valueChanged(int arg1)
//{
//    if(number_of_cow_milk<arg1){
//        QMessageBox::warning(this,"EROR","You don't have enough cow milk");
//        ui->spinBox_cow_milk_sale->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_cow_milk_sale->clear();

//    }
//    int num = arg1 * 5;
//    ui->lineEdit_cow_milk_sale->setText(QString::number(num));
//}


//void shop::on_spinBox_cow_mat_valueChanged(int arg1)
//{
//    int num;
//    num = arg1 * 6;
//    if(coin<num){
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//        num = 0;
//    }
//    ui->lineEdit_cow_mat->setText(QString::number(num));
//}



//void shop::on_spinBox_cow_mat_sale_valueChanged(int arg1)
//{
//    if(number_of_cow_mat<arg1){
//        QMessageBox::warning(this,"EROR","You don't have enough cow meat");
//        ui->spinBox_cow_mat_sale->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_cow_mat_sale->clear();

//    }
//    int num = arg1 * 6;
//    ui->lineEdit_cow_mat_sale->setText(QString::number(num));
//}

void shop::on_spinBox_sheep_valueChanged(int arg1)
{
    int num;
    num = arg1 * 5;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");                        // Declaring an error in terms of the number of coins
        num = 0;
        ui->spinBox_sheep->setValue(0);
    }
    ui->label_sheep->setText(QString::number(num));
}


//void shop::on_spinBox_sheep_milk_valueChanged(int arg1)
//{
//    int num;
//    num = arg1 * 3;
//    if(coin<num){
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//        num = 0;
//    }
//    ui->lineEdit_sheep_milk->setText(QString::number(num));
//}


//void shop::on_spinBox_sheep_milk_sale_valueChanged(int arg1)
//{

//    if(number_of_sheep_milk<arg1){
//        QMessageBox::warning(this,"EROR","You don't have enough sheep milk");
//        ui->spinBox_sheep_milk_sale->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_sheep_milk_sale->clear();

//    }
//    int num = arg1 * 3;
//    ui->lineEdit_sheep_milk_sale->setText(QString::number(num));
//}


//void shop::on_spinBox_sheep_mat_valueChanged(int arg1)
//{
//    int num;
//    num = arg1 * 4;
//    if(coin<num){
//        QMessageBox::warning(this,"EROR","You don't have enough coins");
//        num = 0;
//    }
//    ui->lineEdit_sheep_mat->setText(QString::number(num));
//}


//void shop::on_spinBox_sheep_mat_sale_valueChanged(int arg1)
//{
//    if(number_of_sheep_mat<arg1){
//        QMessageBox::warning(this,"EROR","You don't have enough sheep meat");
//        ui->spinBox_sheep_mat_sale->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_sheep_mat_sale->clear();

//    }
//    int num = arg1 * 4;
//    ui->lineEdit_sheep_mat_sale->setText(QString::number(num));
//}


void shop::on_spinBox_wheat_valueChanged(int arg1)
{
    int num;
    num = arg1 * 2;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");                // Declaring an error in terms of the number of coins
        ui->spinBox_wheat->setValue(0);
        num = 0;
    }
//    int Num;
//    Num = arg1 * 3;
    ui->label_wheat->setText(QString::number(num));
//    ui->lineEdit_wheat_sale->setText(QString::number(Num));
}


void shop::on_spinBox_cron_valueChanged(int arg1)
{
    int num;
    num = arg1 * 2;
    if(coin<num){
        QMessageBox::warning(this,"EROR","You don't have enough coins");                // Declaring an error in terms of the number of coins
        ui->spinBox_cron->setValue(0);
        num = 0;
    }
//    int Num;
//    Num = arg1 * 2;
    ui->label_corn->setText(QString::number(num));
//    ui->lineEdit_cron_sale->setText(QString::number(Num));
}


void shop::on_pushButton_chicken_clicked()
{
    int selectedQuantity = ui->spinBox_chicken->value();                                            // Number selected by the user from spinBox
    int totalPrice = selectedQuantity * 3;                                                         // Calculate the set of that type
    QFile chicken("D:/faz2/faz2/number_of_chicken.txt");
    QFile file("D:/faz2/faz2/coin.txt");

    QTextStream in(&chicken);
    QTextStream out(&chicken);
    QTextStream out1(&file);

    if(chicken.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_chicken;
        chicken.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
    }
    number_of_chicken += selectedQuantity;
    if (chicken.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_chicken;
        chicken.close();
    }else {
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
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
            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
      }
        // تاکید بر نکاتی برای UI
        ui->spinBox_chicken->setValue(0);                           // Set spinBox value to 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->label_chicken->clear();
        }else {
                                                                                        // Declaring an error in terms of the number of coins
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}

void shop::on_pushButton_cow_clicked(){
    int selectedQuantity = ui->spinBox_cow->value();                    // Number selected by the user from spinBox
    int totalPrice = selectedQuantity * 7;                                  // Calculate the set of that type
    QFile cow("D:/faz2/faz2/number_of_cow.txt");
    QFile file("D:/faz2/faz2/coin.txt");
    QTextStream out1(&file);

    QTextStream in(&cow);
    QTextStream out(&cow);

    if(cow.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_cow;
        cow.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error

    }
    number_of_cow += selectedQuantity;
    if (cow.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_cow;
        cow.close();
    }else{                                                                             // Declaring an error in terms of the number of coins
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
                                                                             // Save the number of remaining coins in the text file

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1 << coin;
            file.close();
        }
     else {

            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error

      }

        ui->spinBox_cow->setValue(0);
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->label_cow->clear();
        }else{
                                                                                                // Declaring an error in terms of the number of coins
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}

void shop::on_pushButton_sheep_clicked()
{

    int selectedQuantity = ui->spinBox_sheep->value();                          // Number selected by the user from spinBox
    int totalPrice = selectedQuantity * 5;                                        // Calculate the set of that type
    QFile sheep("D:/faz2/faz2/number_of_sheep.txt");
    QFile file("D:/faz2/faz2/coin.txt");

    QTextStream in(&sheep);
    QTextStream out(&sheep);
    QTextStream out1(&file);

    if(sheep.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_sheep;
        sheep.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
        return;
    }
    number_of_sheep += selectedQuantity;
    if (sheep.open(QIODevice::WriteOnly | QIODevice::Text)) {       
        out << number_of_sheep;
        sheep.close();
    }else {                                                                              // Declaring an error in terms of the number of coins
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice;                                                                 // Subtract coins
                                                                                           // Save the number of remaining coins in the text file

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1 << coin;
            file.close();
        }    
     else {

            QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error
      }

        ui->spinBox_sheep->setValue(0); // تنظیم مقدار spinBox به 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->label_sheep->clear();
        }else {
                                                                                     // Declaring an error in terms of the number of coins
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}


void shop::on_pushButton_wheat_buy_clicked()
{
    int selectedQuantity = ui->spinBox_wheat->value();                                  // Number selected by the user from spinBox
    int totalPrice = selectedQuantity * 2;                                              // Calculate the set of that type
    QFile wheat("D:/faz2/faz2/number_of_wheat.txt");
    QFile file("D:/faz2/faz2/coin.txt");

    QTextStream in(&wheat);
    QTextStream out(&wheat);
        QTextStream out1(&file);
    if(wheat.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_wheat;
        wheat.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error

    }
    number_of_wheat += selectedQuantity;
    if (wheat.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_wheat;
        wheat.close();
    }else {                                                                           // Declaring an error in terms of the number of coins
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice;                                                            // Subtract coins
                                                                                      // Save the number of remaining coins in the text file

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1<< coin;
            file.close();
        }
     else { // Subtract coins
                                                                                     // Declaring an error in terms of the number of coins
     QMessageBox::warning(this, "ERROR", "You don't have enough coins");             return;
      }

        ui->spinBox_wheat->setValue(0);                                              // Set spinBox value to 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->label_wheat->clear();
        }else {
                                                                                       // Declaring an error in terms of the number of coins
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

    }
}

void shop::on_pushButton_cron_buy_clicked()
{
    int selectedQuantity = ui->spinBox_cron->value();                                   //Number selected by the user from spinBox
    int totalPrice = selectedQuantity * 2;                                          // Calculate the set of that type
    QFile cron("D:/faz2/faz2/number_of_cron.txt");
    QFile file("D:/faz2/faz2/coin.txt");
    QTextStream out1(&file);
    QTextStream in(&cron);
    QTextStream out(&cron);

    if(cron.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_cron;
        cron.close();
    }else{
        QMessageBox::warning(this,"EROR","The file could not be opened");                   // If the file is not opened, it will give an error

    }
    number_of_cron += selectedQuantity;
    if (cron.open(QIODevice::WriteOnly | QIODevice::Text)) {
        out << number_of_cron;
        cron.close();
    }else {                                                                           // Declaring an error in terms of the number of coins
        QMessageBox::warning(this, "ERROR", "You don't have enough coins");
        return;
    }
    if (coin >= totalPrice) {
        coin -= totalPrice; // کم کردن سکه‌ها
                                                                                       // Save the number of remaining coins in the text file

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out1 << coin;
            file.close();
        }
     else {
                                                                                       // Declaring an error in terms of the number of coins
        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
        return;
      }

        ui->spinBox_cron->setValue(0);                                                      // Set spinBox value to 0
        ui->lineEdit_coins->setText(QString::number(coin));
        ui->label_corn->clear();
        }else {
                                                                                       // Declaring an error in terms of the number of coins
           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

        }
}

void shop::on_toolButton_clicked()
{
        player->stop();
}



//void shop::on_pushButton_sheep_milk_buy_clicked()
//{
//    int selectedQuantity = ui->spinBox_sheep_milk->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 3; // محاسبه مجموعه آن جنس
//    QFile sheep_milk("D:/faz2/faz2/number_of_sheep_milk.txt");
//    QFile file("D:/faz2/faz2/coin.txt");

//    QTextStream in(&sheep_milk);
//    QTextStream out(&sheep_milk);
//    QTextStream out1(&file);

//    if(sheep_milk.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> number_of_sheep_milk;
//        sheep_milk.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        return;
//    }
//    number_of_sheep_milk += selectedQuantity;
//    if (sheep_milk.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        out << number_of_sheep_milk;
//        sheep_milk.close();
//    }else {
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//    }
//    if (coin >= totalPrice) {
//        coin -= totalPrice; // کم کردن سکه‌ها
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out1 << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//        // تاکید بر نکاتی برای UI
//        ui->spinBox_sheep_milk->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_coins->setText(QString::number(coin));
//        ui->lineEdit_sheep_milk->clear();
//        }else {
//                                                                                        // اعلام خطا از نظر تعداد سکه
//           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

//    }
//}





//void shop::on_pushButton_sheep_milk_sale_clicked()
//{
//    QFile file("D:/faz2/faz2/coin.txt");
//    QFile sheep_milk("D:/faz2/faz2/number_of_sheep_milk.txt");

//    QTextStream out(&file);
//    QTextStream in(&file);
//    QTextStream stream(&sheep_milk);

//    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> coin;
//        file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }

//    int selectedQuantity = ui->spinBox_sheep_milk_sale->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 3; // محاسبه مجموعه آن جنس
//    if(sheep_milk.open(QIODevice::ReadOnly | QIODevice::Text)){
//        stream >> number_of_sheep_milk;
//        sheep_milk.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }


//    if (number_of_sheep_milk > 0) {
//        coin += totalPrice; // زیاد کردن سکه‌ها
//        number_of_sheep_milk -= selectedQuantity;
//        if(sheep_milk.open(QIODevice::WriteOnly | QIODevice::Text)){
//            stream << number_of_sheep_milk;
//            sheep_milk.close();
//        }else{
//            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        }
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//    }
//    ui->spinBox_sheep_milk_sale->setValue(0);
//    ui->lineEdit_sheep_milk_sale->setText(QString::number(number_of_sheep_milk));
//    ui->lineEdit_coins->setText(QString::number(coin));


//}


//void shop::on_pushButton_sheep_mat_clicked()
//{
//    int selectedQuantity = ui->spinBox_sheep_mat->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 4; // محاسبه مجموعه آن جنس
//    QFile sheep_mat("D:/faz2/faz2/number_of_sheep_mat.txt");
//    QFile file("D:/faz2/faz2/coin.txt");

//    QTextStream in(&sheep_mat);
//    QTextStream out(&sheep_mat);
//    QTextStream out1(&file);

//    if(sheep_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> number_of_sheep_mat;
//        sheep_mat.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        return;
//    }
//    number_of_sheep_mat += selectedQuantity;
//    if (sheep_mat.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        out << number_of_sheep_mat;
//        sheep_mat.close();
//    }else {                                                                              // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//    }
//    if (coin >= totalPrice) {
//        coin -= totalPrice; // کم کردن سکه‌ها
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out1 << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//        // تاکید بر نکاتی برای UI
//        ui->spinBox_sheep_mat->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_coins->setText(QString::number(coin));
//        ui->lineEdit_sheep_mat->clear();
//        }else {
//                                                                                        // اعلام خطا از نظر تعداد سکه
//           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

//    }
//}


//void shop::on_pushButton_sheep_mat_sale_clicked()
//{
//    QFile file("D:/faz2/faz2/coin.txt");
//    QFile sheep_mat("D:/faz2/faz2/number_of_sheep_mat.txt");

//    QTextStream out(&file);
//    QTextStream in(&file);
//    QTextStream stream(&sheep_mat);

//    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> coin;
//        file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }

//    int selectedQuantity = ui->spinBox_sheep_mat_sale->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 4; // محاسبه مجموعه آن جنس
//    if(sheep_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
//        stream >> number_of_sheep_mat;
//        sheep_mat.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }


//    if (number_of_sheep_mat > 0) {
//        coin += totalPrice; // زیاد کردن سکه‌ها
//        number_of_sheep_mat -= selectedQuantity;
//        if(sheep_mat.open(QIODevice::WriteOnly | QIODevice::Text)){
//            stream << number_of_sheep_mat;
//            sheep_mat.close();
//        }else{
//            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        }
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//    }
//    ui->spinBox_sheep_mat_sale->setValue(0);
//    ui->lineEdit_sheep_mat_sale->setText(QString::number(number_of_sheep_mat));
//    ui->lineEdit_coins->setText(QString::number(coin));


//}




//void shop::on_pushButton_cow_milk_clicked()
//{
//    int selectedQuantity = ui->spinBox_cow_milk->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 5; // محاسبه مجموعه آن جنس
//    QFile cow_milk("D:/faz2/faz2/number_of_cow_milk.txt");
//    QFile file("D:/faz2/faz2/coin.txt");

//    QTextStream in(&cow_milk);
//    QTextStream out(&cow_milk);
//    QTextStream out1(&file);

//    if(cow_milk.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> number_of_cow_milk;
//        cow_milk.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        return;
//    }
//    number_of_cow_milk += selectedQuantity;
//    if (cow_milk.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        out << number_of_cow_milk;
//        cow_milk.close();
//    }else {                                                                              // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//    }
//    if (coin >= totalPrice) {
//        coin -= totalPrice; // کم کردن سکه‌ها
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out1 << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//        // تاکید بر نکاتی برای UI
//        ui->spinBox_cow_milk->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_coins->setText(QString::number(coin));
//        ui->lineEdit_cow_milk->clear();
//        }else {
//                                                                                        // اعلام خطا از نظر تعداد سکه
//           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

//    }
//}





//void shop::on_pushButton_cow_milk_sale_clicked()
//{
//    QFile file("D:/faz2/faz2/coin.txt");
//    QFile cow_milk("D:/faz2/faz2/number_of_cow_milk.txt");

//    QTextStream out(&file);
//    QTextStream in(&file);
//    QTextStream stream(&cow_milk);

//    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> coin;
//        file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }

//    int selectedQuantity = ui->spinBox_cow_milk_sale->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 5; // محاسبه مجموعه آن جنس
//    if(cow_milk.open(QIODevice::ReadOnly | QIODevice::Text)){
//        stream >> number_of_cow_milk;
//        cow_milk.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }


//    if (number_of_cow_milk > 0) {
//        coin += totalPrice; // زیاد کردن سکه‌ها
//        number_of_cow_milk -= selectedQuantity;
//        if(cow_milk.open(QIODevice::WriteOnly | QIODevice::Text)){
//            stream << number_of_cow_milk;
//            cow_milk.close();
//        }else{
//            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        }
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//    }
//    ui->spinBox_cow_milk_sale->setValue(0);
//    ui->lineEdit_cow_milk_sale->setText(QString::number(number_of_cow_milk));
//    ui->lineEdit_coins->setText(QString::number(coin));

//}


//void shop::on_pushButton_cow_mat_clicked()
//{
//    int selectedQuantity = ui->spinBox_cow_mat->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 6; // محاسبه مجموعه آن جنس
//    QFile cow_mat("D:/faz2/faz2/number_of_cow_mat.txt");
//    QFile file("D:/faz2/faz2/coin.txt");

//    QTextStream in(&cow_mat);
//    QTextStream out(&cow_mat);
//    QTextStream out1(&file);

//    if(cow_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> number_of_cow_mat;
//        cow_mat.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        return;
//    }
//    number_of_cow_mat += selectedQuantity;
//    if (cow_mat.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        out << number_of_cow_mat;
//        cow_mat.close();
//    }else {                                                                              // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//    }
//    if (coin >= totalPrice) {
//        coin -= totalPrice; // کم کردن سکه‌ها
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out1 << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//        // تاکید بر نکاتی برای UI
//        ui->spinBox_cow_mat->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_coins->setText(QString::number(coin));
//        ui->lineEdit_cow_mat->clear();
//        }else {
//                                                                                        // اعلام خطا از نظر تعداد سکه
//           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

//    }
//}




//void shop::on_pushButton_cow_mat_sale_clicked()
//{
//    QFile file("D:/faz2/faz2/coin.txt");
//    QFile cow_mat("D:/faz2/faz2/number_of_cow_mat.txt");

//    QTextStream out(&file);
//    QTextStream in(&file);
//    QTextStream stream(&cow_mat);

//    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> coin;
//        file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }

//    int selectedQuantity = ui->spinBox_cow_mat_sale->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 6; // محاسبه مجموعه آن جنس
//    if(cow_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
//        stream >> number_of_cow_mat;
//        cow_mat.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }


//    if (number_of_cow_mat > 0) {
//        coin += totalPrice; // زیاد کردن سکه‌ها
//        number_of_cow_mat -= selectedQuantity;
//        if(cow_mat.open(QIODevice::WriteOnly | QIODevice::Text)){
//            stream << number_of_cow_mat;
//            cow_mat.close();
//        }else{
//            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        }
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//    }
//    ui->spinBox_cow_mat_sale->setValue(0);
//    ui->lineEdit_cow_mat_sale->setText(QString::number(number_of_cow_mat));
//    ui->lineEdit_coins->setText(QString::number(coin));


//}


//void shop::on_pushButton_chicken_egg_clicked()
//{
//    int selectedQuantity = ui->spinBox_chicken_egg->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 3; // محاسبه مجموعه آن جنس
//    QFile chicken_egg("D:/faz2/faz2/number_of_chicken_egg.txt");
//    QFile file("D:/faz2/faz2/coin.txt");

//    QTextStream in(&chicken_egg);
//    QTextStream out(&chicken_egg);
//    QTextStream out1(&file);

//    if(chicken_egg.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> number_of_chicken_egg;
//        chicken_egg.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        return;
//    }
//    number_of_chicken_egg += selectedQuantity;
//    if (chicken_egg.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        out << number_of_chicken_egg;
//        chicken_egg.close();
//    }else {                                                                              // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//    }
//    if (coin >= totalPrice) {
//        coin -= totalPrice; // کم کردن سکه‌ها
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out1 << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//        // تاکید بر نکاتی برای UI
//        ui->spinBox_chicken_egg->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_coins->setText(QString::number(coin));
//        ui->lineEdit_chicken_egg->clear();
//        }else {
//                                                                                        // اعلام خطا از نظر تعداد سکه
//           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

//    }
//}


//void shop::on_pushButton_chicken_mat_clicked()
//{
//    int selectedQuantity = ui->spinBox_chicken_mat->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 2; // محاسبه مجموعه آن جنس
//    QFile chicken_mat("D:/faz2/faz2/number_of_chicken_mat.txt");
//    QFile file("D:/faz2/faz2/coin.txt");

//    QTextStream in(&chicken_mat);
//    QTextStream out(&chicken_mat);
//    QTextStream out1(&file);

//    if(chicken_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> number_of_chicken_mat;
//        chicken_mat.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        return;
//    }
//    number_of_chicken_mat += selectedQuantity;
//    if (chicken_mat.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        out << number_of_chicken_mat;
//        chicken_mat.close();
//    }else {                                                                              // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//    }
//    if (coin >= totalPrice) {
//        coin -= totalPrice; // کم کردن سکه‌ها
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی

//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out1 << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//        // تاکید بر نکاتی برای UI
//        ui->spinBox_chicken_mat->setValue(0);                           // تنظیم مقدار spinBox به 0
//        ui->lineEdit_coins->setText(QString::number(coin));
//        ui->lineEdit_chicken_mat->clear();
//        }else {
//                                                                                        // اعلام خطا از نظر تعداد سکه
//           QMessageBox::warning(this, "ERROR", "You don't have enough coins");

//    }
//}


//void shop::on_pushButton_chicken_egg_sale_clicked()
//{
//    QFile file("D:/faz2/faz2/coin.txt");
//    QFile chicken_egg("D:/faz2/faz2/number_of_chicken_egg.txt");

//    QTextStream out(&file);
//    QTextStream in(&file);
//    QTextStream stream(&chicken_egg);

//    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> coin;
//        file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }

//    int selectedQuantity = ui->spinBox_chicken_egg_sale->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 3; // محاسبه مجموعه آن جنس
//    if(chicken_egg.open(QIODevice::ReadOnly | QIODevice::Text)){
//        stream >> number_of_chicken_egg;
//        chicken_egg.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }


//    if (number_of_chicken_egg > 0) {
//        coin += totalPrice; // زیاد کردن سکه‌ها
//        number_of_chicken_egg -= selectedQuantity;
//        if(chicken_egg.open(QIODevice::WriteOnly | QIODevice::Text)){
//            stream << number_of_chicken_egg;
//            chicken_egg.close();
//        }else{
//            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        }
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//    }
//    ui->spinBox_chicken_egg_sale->setValue(0);
//    ui->lineEdit_chicken_egg_sale->setText(QString::number(number_of_chicken_egg));
//    ui->lineEdit_coins->setText(QString::number(coin));
//}





//void shop::on_pushButton_chicken_mat_sale_clicked()
//{
//    QFile file("D:/faz2/faz2/coin.txt");
//    QFile chicken_mat("D:/faz2/faz2/number_of_chicken_mat.txt");

//    QTextStream out(&file);
//    QTextStream in(&file);
//    QTextStream stream(&chicken_mat);

//    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
//        in >> coin;
//        file.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }

//    int selectedQuantity = ui->spinBox_chicken_mat_sale->value(); // تعداد انتخاب شده توسط کاربر از spinBox
//    int totalPrice = selectedQuantity * 2; // محاسبه مجموعه آن جنس
//    if(chicken_mat.open(QIODevice::ReadOnly | QIODevice::Text)){
//        stream >> number_of_chicken_mat;
//        chicken_mat.close();
//    }else{
//        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//    }


//    if (number_of_chicken_mat > 0) {
//        coin += totalPrice; // زیاد کردن سکه‌ها
//        number_of_chicken_mat -= selectedQuantity;
//        if(chicken_mat.open(QIODevice::WriteOnly | QIODevice::Text)){
//            stream << number_of_chicken_mat;
//            chicken_mat.close();
//        }else{
//            QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
//        }
//        // ذخیره تعداد سکه‌های باقی‌مانده در فایل متنی
//        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//            out << coin;
//            file.close();
//        }
//     else {
//        // اعلام خطا از نظر تعداد سکه
//        QMessageBox::warning(this, "ERROR", "فایل باز نشد");
//        return;
//      }
//    }
//    ui->spinBox_chicken_mat_sale->setValue(0);
//    ui->lineEdit_chicken_mat_sale->setText(QString::number(number_of_chicken_mat));
//    ui->lineEdit_coins->setText(QString::number(coin));

//}

