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
    int number_of_worker;
    QFile worker("D:/faz2/faz2/number_of_worker.txt");
    QTextStream in(&worker);
    if(worker.open(QIODevice::ReadOnly | QIODevice::Text)){
        in >> number_of_worker;
        worker.close();
    }else{
        QMessageBox::warning(this,"EROR","فایل باز نشد");                   // اگر فایل باز نشده باشد ارور میدهد
    }
    ui->lineEdit_worker->setText(QString::number(number_of_worker));
}

worker::~worker()
{
    delete ui;
}
