#include "finish.h"
#include "ui_finish.h"

finish::finish(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::finish)
{
    ui->setupUi(this);
}

finish::~finish()
{
    delete ui;
}
