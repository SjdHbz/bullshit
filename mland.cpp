#include "mland.h"
#include "ui_mland.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
mland::mland(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mland)
{
    ui->setupUi(this);
    int number_of_land;
    QFile land("D:/faz2/faz2/number_of_land.txt");
    QTextStream in(&land);
    if(land.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_land;
        land.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->lineEdit_land->setText(QString::number(number_of_land));
}

mland::~mland()
{
    delete ui;
}
