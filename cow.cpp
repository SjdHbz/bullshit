#include "cow.h"
#include "ui_cow.h"

cow::cow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cow)
{
    ui->setupUi(this);
}

cow::~cow()
{
    delete ui;
}
