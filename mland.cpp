#include "mland.h"
#include "ui_mland.h"

mland::mland(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mland)
{
    ui->setupUi(this);
}

mland::~mland()
{
    delete ui;
}
