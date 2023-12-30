#include "hous.h"
#include "ui_hous.h"

hous::hous(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hous)
{
    ui->setupUi(this);
}

hous::~hous()
{
    delete ui;
}
