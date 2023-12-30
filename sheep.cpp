#include "sheep.h"
#include "ui_sheep.h"
#include "Score.h"

sheep::sheep(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sheep)
{
    ui->setupUi(this);
}

sheep::~sheep()
{
    delete ui;
}

void sheep::on_pushButton_sheep_clicked()
{
    MyGame::Score push;
    ui->lineEdit_sheep->setText(QString::number(push.number_of_sheep));
}

